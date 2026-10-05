#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "internal.h"
#include "filters.h"

typedef struct Upmix71Context {
    const AVClass *class;
    float sample_rate;
    float *left_delay;
    float *right_delay;
    size_t write_index;
    size_t delay_side;
    size_t delay_back;
    size_t max_delay_size;
} Upmix71Context;

static av_cold int init(AVFilterContext *ctx)
{
    Upmix71Context *s = ctx->priv;
    s->write_index = 0;
    return 0;
}

static int config_input(AVFilterLink *inlink)
{
    AVFilterContext *ctx = inlink->dst;
    Upmix71Context *s = ctx->priv;

    s->sample_rate = inlink->sample_rate;
    s->delay_side = (size_t)(s->sample_rate * 0.020f);
    s->delay_back = (size_t)(s->sample_rate * 0.040f);
    s->max_delay_size = s->delay_back + 1;

    s->left_delay = av_calloc(s->max_delay_size, sizeof(float));
    s->right_delay = av_calloc(s->max_delay_size, sizeof(float));

    if (!s->left_delay || !s->right_delay)
        return AVERROR(ENOMEM);

    return 0;
}

static int filter_frame(AVFilterLink *inlink, AVFrame *in)
{
    AVFilterContext *ctx = inlink->dst;
    AVFilterLink *outlink = ctx->outputs;
    Upmix71Context *s = ctx->priv;
    AVFrame *out;
    int i;

    out = ff_get_audio_buffer(outlink, in->nb_samples);
    if (!out) {
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }

    av_frame_copy_properties(out, in);

    const float *src_l = (const float *)in->extended_data[0];
    const float *src_r = (const float *)in->extended_data[1];

    float *dst_l   = (float *)out->extended_data[0];
    float *dst_r   = (float *)out->extended_data[1];
    float *dst_c   = (float *)out->extended_data[2];
    float *dst_lfe = (float *)out->extended_data[3];
    float *dst_ls  = (float *)out->extended_data[4];
    float *dst_rs  = (float *)out->extended_data[5];
    float *dst_lb  = (float *)out->extended_data[6];
    float *dst_rb  = (float *)out->extended_data[7];

    for (i = 0; i < in->nb_samples; i++) {
        float l = src_l[i];
        float r = src_r[i];

        float mid = (l + r) * 0.5f;
        float side = (l - r) * 0.5f;

        dst_c[i] = mid * 0.707f;
        dst_l[i] = (l * 0.8f) + (side * 0.2f);
        dst_r[i] = (r * 0.8f) - (side * 0.2f);

        s->left_delay[s->write_index] = l;
        s->right_delay[s->write_index] = r;

        size_t idx_side = (s->write_index + s->max_delay_size - s->delay_side) % s->max_delay_size;
        size_t idx_back = (s->write_index + s->max_delay_size - s->delay_back) % s->max_delay_size;

        dst_ls[i] = (s->left_delay[idx_side] - s->right_delay[idx_side]) * 0.5f;
        dst_rs[i] = (s->right_delay[idx_side] - s->left_delay[idx_side]) * 0.5f;

        dst_lb[i] = s->left_delay[idx_back] * 0.4f;
        dst_rb[i] = s->right_delay[idx_back] * 0.4f;

        dst_lfe[i] = (l + r) * 0.3f;

        s->write_index = (s->write_index + 1) % s->max_delay_size;
    }

    av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}

static av_cold void uninit(AVFilterContext *ctx)
{
    Upmix71Context *s = ctx->priv;
    av_freep(&s->left_delay);
    av_freep(&s->right_delay);
}

static const AVFilterPad upmix71_inputs[] = {
    {
        .name         = "default",
        .type         = AVMEDIA_TYPE_AUDIO,
        .config_props = config_input,
        .filter_frame = filter_frame,
    },
};

static const AVFilterPad upmix71_outputs[] = {
    {
        .name = "default",
        .type = AVMEDIA_TYPE_AUDIO,
    },
};

const AVFilter ff_af_upmix71 = {
    .name          = "upmix71",
    .description   = NULL_IF_CONFIG_SMALL("Upmix stereo audio to 7.1 channel layout."),
    .priv_size     = sizeof(Upmix71Context),
    .init          = init,
    .uninit        = uninit,
    FILTER_INPUTS(upmix71_inputs),
    FILTER_OUTPUTS(upmix71_outputs),
    .flags         = AVFILTER_FLAG_SUPPORT_TIMELINE_GENERIC,
};

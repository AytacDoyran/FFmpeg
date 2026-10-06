/*
 * filter registration
 * Copyright (c) 2008 Vitor Sessak
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "avfilter.h"
#include "filters.h"

extern const FFFilter ff_af_aap;
extern const FFFilter ff_af_abench;
extern const FFFilter ff_af_acompressor;
extern const FFFilter ff_af_acontrast;
extern const FFFilter ff_af_acopy;
extern const FFFilter ff_af_acue;
extern const FFFilter ff_af_acrossfade;
extern const FFFilter ff_af_acrossover;
extern const FFFilter ff_af_acrusher;
extern const FFFilter ff_af_adeclick;
extern const FFFilter ff_af_adeclip;
extern const FFFilter ff_af_adecorrelate;
extern const FFFilter ff_af_adelay;
extern const FFFilter ff_af_adenorm;
extern const FFFilter ff_af_aderivative;
extern const FFFilter ff_af_adrc;
extern const FFFilter ff_af_adynamicequalizer;
extern const FFFilter ff_af_adynamicsmooth;
extern const FFFilter ff_af_aecho;
extern const FFFilter ff_af_aemphasis;
extern const FFFilter ff_af_aeval;
extern const FFFilter ff_af_aexciter;
extern const FFFilter ff_af_afade;
extern const FFFilter ff_af_afftdn;
extern const FFFilter ff_af_afftfilt;
extern const FFFilter ff_af_afir;
extern const FFFilter ff_af_aformat;
extern const FFFilter ff_af_afreqshift;
extern const FFFilter ff_af_afwtdn;
extern const FFFilter ff_af_agate;
extern const FFFilter ff_af_aiir;
extern const FFFilter ff_af_aintegral;
extern const FFFilter ff_af_ainterleave;
extern const FFFilter ff_af_alatency;
extern const FFFilter ff_af_alimiter;
extern const FFFilter ff_af_allpass;
extern const FFFilter ff_af_aloop;
extern const FFFilter ff_af_amerge;
extern const FFFilter ff_af_ametadata;
extern const FFFilter ff_af_amix;
extern const FFFilter ff_af_amultiply;
extern const FFFilter ff_af_anequalizer;
extern const FFFilter ff_af_anlmdn;
extern const FFFilter ff_af_anlmf;
extern const FFFilter ff_af_anlms;
extern const FFFilter ff_af_anull;
extern const FFFilter ff_af_apad;
extern const FFFilter ff_af_aperms;
extern const FFFilter ff_af_aphaser;
extern const FFFilter ff_af_aphaseshift;
extern const FFFilter ff_af_apsnr;
extern const FFFilter ff_af_apsyclip;
extern const FFFilter ff_af_apulsator;
extern const FFFilter ff_af_arealtime;
extern const FFFilter ff_af_aresample;
extern const FFFilter ff_af_areverse;
extern const FFFilter ff_af_arls;
extern const FFFilter ff_af_arnndn;
extern const FFFilter ff_af_asdr;
extern const FFFilter ff_af_asegment;
extern const FFFilter ff_af_aselect;
extern const FFFilter ff_af_asendcmd;
extern const FFFilter ff_af_asetnsamples;
extern const FFFilter ff_af_asetpts;
extern const FFFilter ff_af_asetrate;
extern const FFFilter ff_af_asettb;
extern const FFFilter ff_af_ashowinfo;
extern const FFFilter ff_af_asidedata;
extern const FFFilter ff_af_asisdr;
extern const FFFilter ff_af_asoftclip;
extern const FFFilter ff_af_aspectralstats;
extern const FFFilter ff_af_asplit;
extern const FFFilter ff_af_asr;
extern const FFFilter ff_af_astats;
extern const FFFilter ff_af_astreamselect;
extern const FFFilter ff_af_asubboost;
extern const FFFilter ff_af_asubcut;
extern const FFFilter ff_af_asupercut;
extern const FFFilter ff_af_asuperpass;
extern const FFFilter ff_af_asuperstop;
extern const FFFilter ff_af_atempo;
extern const FFFilter ff_af_atilt;
extern const FFFilter ff_af_atrim;
extern const FFFilter ff_af_axcorrelate;
extern const FFFilter ff_af_azmq;
extern const FFFilter ff_af_bandpass;
extern const FFFilter ff_af_bandreject;
extern const FFFilter ff_af_bass;
extern const FFFilter ff_af_biquad;
extern const FFFilter ff_af_bs2b;
extern const FFFilter ff_af_channelmap;
extern const FFFilter ff_af_channelsplit;
extern const FFFilter ff_af_chorus;
extern const FFFilter ff_af_compand;
extern const FFFilter ff_af_compensationdelay;
extern const FFFilter ff_af_crossfeed;
extern const FFFilter ff_af_crystalizer;
extern const FFFilter ff_af_dcshift;
extern const FFFilter ff_af_deesser;
extern const FFFilter ff_af_dialoguenhance;
extern const FFFilter ff_af_drmeter;
extern const FFFilter ff_af_dynaudnorm;
extern const FFFilter ff_af_earwax;
extern const FFFilter ff_af_ebur128;
extern const FFFilter ff_af_equalizer;
extern const FFFilter ff_af_extrastereo;
extern const FFFilter ff_af_firequalizer;
extern const FFFilter ff_af_flanger;
extern const FFFilter ff_af_haas;
extern const FFFilter ff_af_hdcd;
extern const FFFilter ff_af_headphone;
extern const FFFilter ff_af_highpass;
extern const FFFilter ff_af_highshelf;
extern const FFFilter ff_af_join;
extern const FFFilter ff_af_ladspa;
extern const FFFilter ff_af_loudnorm;
extern const FFFilter ff_af_lowpass;
extern const FFFilter ff_af_lowshelf;
extern const FFFilter ff_af_lv2;
extern const FFFilter ff_af_mcompand;
extern const FFFilter ff_af_pan;
extern const FFFilter ff_af_replaygain;
extern const FFFilter ff_af_rubberband;
extern const FFFilter ff_af_sidechaincompress;
extern const FFFilter ff_af_sidechaingate;
extern const FFFilter ff_af_silencedetect;
extern const FFFilter ff_af_silenceremove;
extern const FFFilter ff_af_sofalizer;
extern const FFFilter ff_af_speechnorm;
extern const FFFilter ff_af_stereotools;
extern const FFFilter ff_af_stereowiden;
extern const FFFilter ff_af_superequalizer;
extern const FFFilter ff_af_surround;
extern const FFFilter ff_af_tiltshelf;
extern const FFFilter ff_af_treble;
extern const FFFilter ff_af_tremolo;
extern const FFFilter ff_af_upmix71;
extern const FFFilter ff_af_vibrato;
extern const FFFilter ff_af_virtualbass;
extern const FFFilter ff_af_volume;
extern const FFFilter ff_af_volumedetect;
extern const FFFilter ff_af_whisper;

extern const FFFilter ff_asrc_aevalsrc;
extern const FFFilter ff_asrc_afdelaysrc;
extern const FFFilter ff_asrc_afireqsrc;
extern const FFFilter ff_asrc_afirsrc;
extern const FFFilter ff_asrc_anoisesrc;
extern const FFFilter ff_asrc_anullsrc;
extern const FFFilter ff_asrc_flite;
extern const FFFilter ff_asrc_hilbert;
extern const FFFilter ff_asrc_sinc;
extern const FFFilter ff_asrc_sine;

extern const FFFilter ff_asink_anullsink;

extern const FFFilter ff_vf_addroi;
extern const FFFilter ff_vf_alphaextract;
extern const FFFilter ff_vf_alphamerge;
extern const FFFilter ff_vf_amplify;
extern const FFFilter ff_vf_ass;
extern const FFFilter ff_vf_atadenoise;
extern const FFFilter ff_vf_avgblur;
extern const FFFilter ff_vf_avgblur_opencl;
extern const FFFilter ff_vf_avgblur_vulkan;
extern const FFFilter ff_vf_backgroundkey;
extern const FFFilter ff_vf_bbox;
extern const FFFilter ff_vf_bench;
extern const FFFilter ff_vf_bilateral;
extern const FFFilter ff_vf_bilateral_cuda;
extern const FFFilter ff_vf_bitplanenoise;
extern const FFFilter ff_vf_blackdetect;
extern const FFFilter ff_vf_blackdetect_vulkan;
extern const FFFilter ff_vf_blackframe;
extern const FFFilter ff_vf_blend;
extern const FFFilter ff_vf_blend_vulkan;
extern const FFFilter ff_vf_blockdetect;
extern const FFFilter ff_vf_blurdetect;
extern const FFFilter ff_vf_bm3d;
extern const FFFilter ff_vf_boxblur;
extern const FFFilter ff_vf_boxblur_opencl;
extern const FFFilter ff_vf_bwdif;
extern const FFFilter ff_vf_bwdif_cuda;
extern const FFFilter ff_vf_bwdif_vulkan;
extern const FFFilter ff_vf_cas;
extern const FFFilter ff_vf_ccrepack;
extern const FFFilter ff_vf_chromaber_vulkan;
extern const FFFilter ff_vf_chromahold;
extern const FFFilter ff_vf_chromakey;
extern const FFFilter ff_vf_chromakey_cuda;
extern const FFFilter ff_vf_chromanr;
extern const FFFilter ff_vf_chromashift;
extern const FFFilter ff_vf_ciescope;
extern const FFFilter ff_vf_codecview;

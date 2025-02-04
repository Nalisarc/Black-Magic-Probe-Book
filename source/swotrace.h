/*
 * Shared code for SWO Trace for the bmtrace and bmdebug utilities.
 *
 * Copyright 2019-2023 CompuPhase
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _SWOTRACE_H
#define _SWOTRACE_H

#include <stdbool.h>
#include "nuklear.h"

#define NUM_CHANNELS  32  /* number of SWO channels */

enum {
  TRACESTAT_OK = 0,
  TRACESTAT_NO_INTERFACE, /* Black Magic Probe not found (trace interface not found) */
  TRACESTAT_NO_DEVPATH,   /* device path to trace interface not found */
  TRACESTAT_NO_ACCESS,    /* failure opening the device interface */
  TRACESTAT_NO_PIPE,      /* endpoint pipe could not be found -> not a Black Magic Probe? */
  TRACESTAT_BAD_PACKET,   /* invalid trace data packet received */
  TRACESTAT_NO_THREAD,    /* thread could not be created */
  TRACESTAT_INIT_FAILED,  /* WunUSB / libusb initialization failed */
  TRACESTAT_NO_CONNECT,   /* Failed to connect to Black Magic Probe */
  TRACESTAT_NOT_INIT,     /* not yet initialized */
};

enum {
  TRACESTATMSG_BMP,
  TRACESTATMSG_CTF,
};

typedef struct tagTRACEFILTER {
  char *expr;
  int enabled;
} TRACEFILTER;

#define ADDRESS_ALIGN   2 /* alignment of an address in bytes (16-bit Thumb) */
#define Address2Index(address, base)  (((address) - (base)) / ADDRESS_ALIGN)
#define Index2Address(index, base)    ((index) * ADDRESS_ALIGN + (base))

void channel_set(int index, bool enabled, const char *name, struct nk_color color);
bool channel_getenabled(int index);
void channel_setenabled(int index, bool enabled);
const char *channel_getname(int index, char *name, size_t size);
void channel_setname(int index, const char *name);
struct nk_color channel_getcolor(int index);
void channel_setcolor(int index, struct nk_color color);

int  trace_init(unsigned short endpoint, const char *ipaddress);
void trace_close(void);
unsigned long trace_errno(int *loc);
int  trace_overflowerrors(bool reset);

void trace_setdatasize(short size);
short trace_getdatasize();
int  trace_getpacketerrors(bool reset);

void tracestring_clear(void);
int  tracestring_isempty(void);
unsigned tracestring_count(void);
int  tracestring_process(bool enabled);
int  tracestring_save(const char *filename);
int  tracestring_find(const char *text, int curline);
int  tracestring_findtimestamp(double timestamp);

int  traceprofile_process(bool enabled, unsigned *sample_map, uint32_t code_base, uint32_t code_top, unsigned *overflow);

void tracelog_statusmsg(int type, const char *msg, int code);
void tracelog_statusclear(void);
const char *tracelog_getstatusmsg(int idx);
float tracelog_labelwidth(float rowheight);
void tracelog_widget(struct nk_context *ctx, const char *id, float rowheight, int limitlines,
                     int markline, const TRACEFILTER *filters, nk_flags widget_flags);

void timeline_getconfig(double *spacing, unsigned long *scale, unsigned long *delta);
void timeline_setconfig(double spacing, unsigned long scale, unsigned long delta);
double timeline_widget(struct nk_context *ctx, const char *id, float rowheight,
                       int limitlines, nk_flags widget_flags);

double get_timestamp(void);

#endif /* _SWOTRACE_H */

/*-
 * Copyright (c) 2014 Nokia
 * Copyright (c) 2014 ENEA Software AB
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#ifndef _OFPI_TIMER_H
#define _OFPI_TIMER_H

#include "api/ofp_timer.h"

#define MS_PER_SEC 1000UL

#define US_PER_SEC 1000000UL
#define US_PER_MS  1000UL

#define NS_PER_SEC 1000000000UL
#define NS_PER_MS  1000000UL
#define NS_PER_US  1000UL

#if ODP_VERSION < 105
#define ODP_TIME_USEC_IN_NS ODP_TIME_USEC
#define ODP_TIME_MSEC_IN_NS ODP_TIME_MSEC
#define ODP_TIME_SEC_IN_NS ODP_TIME_SEC
#define ENTRY_USETIME_INVALID 0xFFFFFFFF
#define ODP_TIME_NULL ENTRY_USETIME_INVALID
#define odp_time_local odp_cpu_cycles
#define odp_time_diff(x, y) odp_time_diff_cycles(y, x)
#define odp_time_to_ns odp_time_cycles_to_ns
#define odp_time_to_u64
typedef uint64_t odp_time_t;
#endif /* ODP_VERSION < 105 */

#define OFP_TIMER_RESOLUTION_US	10000UL
#define OFP_TIMER_MIN_US		0UL
#define OFP_TIMER_MAX_US		10000000UL
#define OFP_TIMER_TMO_COUNT		1000UL

#define HZ				(1000000UL/OFP_TIMER_RESOLUTION_US)
#define hz				HZ

#define OFP_TIMER_ARG_LEN		256

/* Timer type */
#define OFP_TIMER_SOCKET 0

int ofp_timer_lookup_shared_memory(void);
int ofp_timer_init_global(int resolution_us,
	int min_us, int max_us,
	int tmo_count);
int ofp_timer_stop_global(void);
int ofp_timer_term_global(void);

void ofp_timer_evt_cleanup(odp_event_t);

#endif

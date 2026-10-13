/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM vmscan

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_VMSCAN_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_VMSCAN_H

#include <trace/hooks/vendor_hooks.h>
#include <linux/types.h>

struct page;

/*
 * oplus vmscan vendor hooks, ported from the oplus android14 (6.1) kernel
 * for the zram_opt / kswapd_opt / levelprotect drivers.
 */

DECLARE_HOOK(android_vh_tune_swappiness,
	TP_PROTO(int *swappiness),
	TP_ARGS(swappiness));

DECLARE_HOOK(android_vh_page_referenced_check_bypass,
	TP_PROTO(struct page *page, unsigned long nr_to_scan, int lru, bool *bypass),
	TP_ARGS(page, nr_to_scan, lru, bypass));

DECLARE_HOOK(android_vh_vmscan_kswapd_done,
	TP_PROTO(int node_id, unsigned int highest_zoneidx, unsigned int alloc_order,
		 unsigned int reclaim_order),
	TP_ARGS(node_id, highest_zoneidx, alloc_order, reclaim_order));

DECLARE_HOOK(android_rvh_set_balance_anon_file_reclaim,
	TP_PROTO(bool *balance_anon_file_reclaim),
	TP_ARGS(balance_anon_file_reclaim));

#endif /* _TRACE_HOOK_VMSCAN_H */
/* This part must be outside protection */
#include <trace/define_trace.h>

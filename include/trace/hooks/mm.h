/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM mm

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_MM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_MM_H

#include <trace/hooks/vendor_hooks.h>
#include <linux/types.h>
#include <linux/mmzone.h>

/*
 * oplus mm vendor hooks, ported from the oplus android14 (6.1) kernel
 * for the levelprotect / kswapd_opt / zram_opt drivers.
 */

DECLARE_HOOK(android_vh_alloc_pages_slowpath,
	TP_PROTO(gfp_t gfp_mask, unsigned int order, unsigned long delta),
	TP_ARGS(gfp_mask, order, delta));

/* oplus hook (not upstream GKI): strip reclaim gfp flags before allocating */
DECLARE_HOOK(android_vh_customize_alloc_gfp,
	TP_PROTO(gfp_t *alloc_gfp, unsigned int order),
	TP_ARGS(alloc_gfp, order));

DECLARE_HOOK(android_vh_kvmalloc_node_use_vmalloc,
	TP_PROTO(size_t size, gfp_t *kmalloc_flags, bool *use_vmalloc),
	TP_ARGS(size, kmalloc_flags, use_vmalloc));

/* GKI 6.1 hook: adjust zone watermarks with oplus extra_free_kbytes */
DECLARE_HOOK(android_vh_init_adjust_zone_wmark,
	TP_PROTO(struct zone *zone, u64 interval),
	TP_ARGS(zone, interval));

/* GKI hook for speculative page faults; never called on 4.19 (no SPF) */
DECLARE_HOOK(android_vh_do_swap_page_spf,
	TP_PROTO(bool *allow_swap_spf),
	TP_ARGS(allow_swap_spf));

/* levelprotect (mapped_protect) hooks */
DECLARE_HOOK(android_vh_update_page_mapcount,
	TP_PROTO(struct page *page, bool inc_size, bool compound,
		 bool *first_mapping, bool *success),
	TP_ARGS(page, inc_size, compound, first_mapping, success));

DECLARE_HOOK(android_vh_add_page_to_lrulist,
	TP_PROTO(struct page *page, bool compound, enum lru_list lru),
	TP_ARGS(page, compound, lru));

DECLARE_HOOK(android_vh_del_page_from_lrulist,
	TP_PROTO(struct page *page, bool compound, enum lru_list lru),
	TP_ARGS(page, compound, lru));

DECLARE_HOOK(android_vh_page_should_be_protected,
	TP_PROTO(struct page *page, bool *should_protect),
	TP_ARGS(page, should_protect));

DECLARE_HOOK(android_vh_mark_page_accessed,
	TP_PROTO(struct page *page),
	TP_ARGS(page));

DECLARE_HOOK(android_vh_do_traversal_lruvec,
	TP_PROTO(struct lruvec *lruvec),
	TP_ARGS(lruvec));

DECLARE_HOOK(android_vh_show_mapcount_pages,
	TP_PROTO(void *unused),
	TP_ARGS(unused));

#endif /* _TRACE_HOOK_MM_H */
/* This part must be outside protection */
#include <trace/define_trace.h>

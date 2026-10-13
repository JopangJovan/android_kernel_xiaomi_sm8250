/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM iommu

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_IOMMU_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_IOMMU_H

#include <trace/hooks/vendor_hooks.h>
#include <linux/types.h>

/* oplus kswapd_opt hook: adjust iommu dma alloc flags by order */
DECLARE_HOOK(android_vh_adjust_alloc_flags,
	TP_PROTO(unsigned int order, gfp_t *alloc_flags),
	TP_ARGS(order, alloc_flags));

#endif /* _TRACE_HOOK_IOMMU_H */
/* This part must be outside protection */
#include <trace/define_trace.h>

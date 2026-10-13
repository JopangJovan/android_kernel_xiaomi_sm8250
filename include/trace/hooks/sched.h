/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM sched
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH trace/hooks
#if !defined(_TRACE_HOOK_SCHED_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_SCHED_H
#include <trace/hooks/vendor_hooks.h>

struct task_struct;

DECLARE_HOOK(android_rvh_flush_task,
	TP_PROTO(struct task_struct *prev),
	TP_ARGS(prev));

DECLARE_HOOK(android_rvh_sched_fork,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p));

DECLARE_HOOK(android_rvh_try_to_wake_up,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p));

DECLARE_HOOK(android_rvh_new_task_stats,
	TP_PROTO(struct task_struct *p),
	TP_ARGS(p));

#endif /* _TRACE_HOOK_SCHED_H */
/* This part must be outside protection */
#include <trace/define_trace.h>

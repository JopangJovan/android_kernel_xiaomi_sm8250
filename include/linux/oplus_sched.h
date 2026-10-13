/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_OPLUS_SCHED_H
#define _LINUX_OPLUS_SCHED_H

#include <linux/types.h>
#include <linux/list.h>
#include <linux/spinlock.h>

struct task_struct;
struct binder_node;

struct oplus_task_struct {
	struct list_head fbg_list;
	raw_spinlock_t fbg_list_entry_lock;
	bool fbg_running;
	u16 fbg_state;
	s8 preferred_cluster_id;
	s8 fbg_depth;
	u64 last_wake_ts;
	int fbg_cur_group;
	struct task_struct *task;
	unsigned long im_flag;
#if IS_ENABLED(CONFIG_OPLUS_BINDER_STRATEGY) || IS_ENABLED(CONFIG_OPLUS_FEATURE_CPU_JANKINFO)
	/* UX scheduler fields (stub storage — sched_assist not ported) */
	int ux_state;
	int ux_depth;
	atomic64_t inherit_ux;
	int binder_async_ux_enable;
	int binder_async_ux_sts;
	u64 total_exec;
	struct binder_node *binder_thread_node;
	u64 enqueue_time;
	u64 block_start_time;
#endif
};

#endif /* _LINUX_OPLUS_SCHED_H */

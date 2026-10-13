// SPDX-License-Identifier: GPL-2.0-only
/* vendor_hook.c
 *
 * Android Vendor Hook Support
 *
 * Copyright 2020 Google LLC
 */

#define CREATE_TRACE_POINTS
#include <trace/hooks/vendor_hooks.h>
#include <trace/hooks/memory.h>
#include <trace/hooks/syscall_check.h>
#include <linux/tracepoint.h>
#include <trace/hooks/binder.h>
#include <trace/hooks/signal.h>
#include <trace/hooks/sched.h>
#include <trace/hooks/midas_dev.h>
#include <trace/hooks/mm.h>
#include <trace/hooks/vmscan.h>
#include <trace/hooks/iommu.h>

/*
 * Export tracepoints that act as a bare tracehook (ie: have no trace event
 * associated with them) to allow external modules to probe them.
 */
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_set_memory_x);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_set_memory_nx);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_set_memory_ro);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_set_memory_rw);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_check_mmap_file);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_check_file_open);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_check_bpf_syscall);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_transaction_init);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_priority_skip);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_set_priority);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_restore_priority);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_wakeup_ilocked);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_wait_for_work);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_sync_txn_recvd);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_alloc_new_buf_locked);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_reply);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_trans);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_preset);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_proc_transaction);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_new_ref);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_del_ref);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_binder_print_transaction_info);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_do_send_sig_info);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_rvh_flush_task);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_rvh_sched_fork);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_rvh_try_to_wake_up);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_rvh_new_task_stats);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_midas_record_task_times);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_killed_process);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_alloc_pages_slowpath);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_customize_alloc_gfp);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_kvmalloc_node_use_vmalloc);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_init_adjust_zone_wmark);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_do_swap_page_spf);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_update_page_mapcount);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_add_page_to_lrulist);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_del_page_from_lrulist);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_page_should_be_protected);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_mark_page_accessed);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_do_traversal_lruvec);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_show_mapcount_pages);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_tune_swappiness);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_page_referenced_check_bypass);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_vmscan_kswapd_done);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_rvh_set_balance_anon_file_reclaim);
EXPORT_TRACEPOINT_SYMBOL_GPL(android_vh_adjust_alloc_flags);

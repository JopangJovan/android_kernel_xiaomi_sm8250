/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_MEMORY_MONITOR_H
#define _LINUX_MEMORY_MONITOR_H

#include <linux/sched.h>

struct process_mem {
	char comm[TASK_COMM_LEN];
	int pid;
	int ppid;
	int oom_score_adj;
	unsigned long rss;
	unsigned long rssfile;
	unsigned long swapents_ori;
	unsigned int uid;
	unsigned long gl_dev;
	unsigned long egl;
};

static inline void mm_get_all_pmem(int *cnt, struct process_mem *pmem)
{
	if (cnt)
		*cnt = 0;
}

#endif /* _LINUX_MEMORY_MONITOR_H */

/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Compatibility shims for porting oplus android14 (5.15/6.1) mm drivers
 * to this 4.19 kernel.
 */
#ifndef _OPLUS_MM_COMPAT_H_
#define _OPLUS_MM_COMPAT_H_

#include <linux/proc_fs.h>
#include <linux/version.h>

/*
 * struct proc_ops appeared in 5.6. On 4.19 proc entries use struct
 * file_operations, whose read/write/open/release/lseek members have the
 * same signatures as the proc_ops variants, so map them one to one.
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 6, 0)
#define proc_ops		file_operations
#define proc_open		open
#define proc_read		read
#define proc_write		write
#define proc_lseek		llseek
#define proc_release		release
#endif

#endif /* _OPLUS_MM_COMPAT_H_ */

/* SPDX-License-Identifier: MIT */

#ifndef __INTERNAL__LIBURING_SYSCALL_H
	#error "This file should be included from src/syscall.h (liburing)"
#endif

#ifndef LIBURING_ARCH_AARCH32_SYSCALL_H
#define LIBURING_ARCH_AARCH32_SYSCALL_H

/**
 * Note for syscall registers usage (aarch32):
 *   - r7 is the syscall number.
 *   - r0 is the return value.
 *   - r0 is also the 1st argument.
 *   - r1 is the 2nd argument.
 *   - r2 is the 3rd argument.
 *   - r3 is the 4th argument.
 *   - r4 is the 5th argument.
 *   - r5 is the 6th argument.
 *
 * `syscall` instruction will clobber lr.
 */

#define __do_syscall0(num) ({						\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (num);			\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

#define __do_syscall1(num, arg1) ({					\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (long)(arg1);		\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_arg1),						\
		  "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

#define __do_syscall2(num, arg1, arg2) ({				\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (long)(arg1);		\
	register long _arg2 __asm__("r1") = (long)(arg2);		\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

#define __do_syscall3(num, arg1, arg2, arg3) ({				\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (long)(arg1);		\
	register long _arg2 __asm__("r1") = (long)(arg2);		\
	register long _arg3 __asm__("r2") = (long)(arg3);		\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

#define __do_syscall4(num, arg1, arg2, arg3, arg4) ({			\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (long)(arg1);		\
	register long _arg2 __asm__("r1") = (long)(arg2);		\
	register long _arg3 __asm__("r2") = (long)(arg3);		\
	register long _arg4 __asm__("r3") = (long)(arg4);		\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_arg4),						\
		  "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

#define __do_syscall5(num, arg1, arg2, arg3, arg4, arg5) ({		\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (long)(arg1);		\
	register long _arg2 __asm__("r1") = (long)(arg2);		\
	register long _arg3 __asm__("r2") = (long)(arg3);		\
	register long _arg4 __asm__("r3") = (long)(arg4);		\
	register long _arg5 __asm__("r4") = (long)(arg5);		\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_arg4),						\
		  "r"(_arg5),						\
		  "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

#define __do_syscall6(num, arg1, arg2, arg3, arg4, arg5, arg6) ({	\
	register long _num __asm__("r7") = (num);			\
	register long _arg1 __asm__("r0") = (long)(arg1);		\
	register long _arg2 __asm__("r1") = (long)(arg2);		\
	register long _arg3 __asm__("r2") = (long)(arg3);		\
	register long _arg4 __asm__("r3") = (long)(arg4);		\
	register long _arg5 __asm__("r4") = (long)(arg5);		\
	register long _arg6 __asm__("r5") = (long)(arg6);		\
									\
	__asm__ volatile (						\
		"svc #0"						\
		: "=r"(_arg1)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_arg4),						\
		  "r"(_arg5),						\
		  "r"(_arg6),						\
		  "r"(_num)						\
		: "memory", "cc", "lr"					\
	);								\
	_arg1;								\
})

static inline void *__sys_mmap(void *addr, size_t length, int prot, int flags,
			       int fd, off_t offset)
{
	return (void *) __do_syscall6(__NR_mmap, addr, length, prot, flags, fd,
				      offset);
}

static inline int __sys_munmap(void *addr, size_t length)
{
	return (int) __do_syscall2(__NR_munmap, addr, length);
}

static inline int __sys_madvise(void *addr, size_t length, int advice)
{
	return (int) __do_syscall2(__NR_madvise, addr, length);
}

static inline int __sys_getrlimit(int resource, struct rlimit *rlim)
{
	return (int) __do_syscall2(__NR_getrlimit, resource, rlim);
}

static inline int __sys_setrlimit(int resource, const struct rlimit *rlim)
{
	return (int) __do_syscall2(__NR_setrlimit, resource, rlim);
}

static inline int __sys_close(int fd)
{
	return (int) __do_syscall1(__NR_close, fd);
}

static inline int ____sys_io_uring_register(int fd, unsigned opcode,
					    const void *arg, unsigned nr_args)
{
	return (int) __do_syscall4(__NR_io_uring_register, fd, opcode, arg,
				   nr_args);
}

static inline int ____sys_io_uring_setup(unsigned entries,
					 struct io_uring_params *p)
{
	return (int) __do_syscall2(__NR_io_uring_setup, entries, p);
}

static inline int ____sys_io_uring_enter2(int fd, unsigned to_submit,
					  unsigned min_complete, unsigned flags,
					  sigset_t *sig, int sz)
{
	return (int) __do_syscall6(__NR_io_uring_enter, fd, to_submit,
				   min_complete, flags, sig, sz);
}

static inline int ____sys_io_uring_enter(int fd, unsigned to_submit,
					 unsigned min_complete, unsigned flags,
					 sigset_t *sig)
{
	return ____sys_io_uring_enter2(fd, to_submit, min_complete, flags, sig,
				       _NSIG / 8);
}

#endif /* #ifndef LIBURING_ARCH_AARCH32_SYSCALL_H */

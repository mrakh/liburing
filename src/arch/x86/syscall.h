/* SPDX-License-Identifier: MIT */

#ifndef __INTERNAL__LIBURING_SYSCALL_H
	#error "This file should be included from src/syscall.h (liburing)"
#endif

#ifndef LIBURING_ARCH_X86_SYSCALL_H
#define LIBURING_ARCH_X86_SYSCALL_H

/**
 * Note for syscall registers usage (x86):
 *   - %eax is the syscall number.
 *   - %eax is also the return value.
 *   - %ebx is the 1st argument.
 *   - %ecx is the 2nd argument.
 *   - %edx is the 3rd argument.
 *   - %esi is the 4th argument.
 *   - %edi is the 5th argument.
 *   - %ebp is the 6th argument.
 */

#define __do_syscall0(num) ({						\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
})

#define __do_syscall1(num, arg1) ({					\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
	register long _arg1 __asm__("ebx") = (long)(arg1);		\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "r"(_arg1),						\
		  "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
})

#define __do_syscall2(num, arg1, arg2) ({				\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
	register long _arg1 __asm__("ebx") = (long)(arg1);		\
	register long _arg2 __asm__("ecx") = (long)(arg2);		\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
})

#define __do_syscall3(num, arg1, arg2, arg3) ({				\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
	register long _arg1 __asm__("ebx") = (long)(arg1);		\
	register long _arg2 __asm__("ecx") = (long)(arg2);		\
	register long _arg3 __asm__("edx") = (long)(arg3);		\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
})

#define __do_syscall4(num, arg1, arg2, arg3, arg4) ({			\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
	register long _arg1 __asm__("ebx") = (long)(arg1);		\
	register long _arg2 __asm__("ecx") = (long)(arg2);		\
	register long _arg3 __asm__("edx") = (long)(arg3);		\
	register long _arg4 __asm__("esi") = (long)(arg4);		\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_arg4),						\
		  "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
})

#define __do_syscall5(num, arg1, arg2, arg3, arg4, arg5) ({		\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
	register long _arg1 __asm__("ebx") = (long)(arg1);		\
	register long _arg2 __asm__("ecx") = (long)(arg2);		\
	register long _arg3 __asm__("edx") = (long)(arg3);		\
	register long _arg4 __asm__("esi") = (long)(arg4);		\
	register long _arg5 __asm__("edi") = (long)(arg5);		\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_arg4),						\
		  "r"(_arg5),						\
		  "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
})

#define __do_syscall6(num, arg1, arg2, arg3, arg4, arg5, arg6) ({	\
	long _ret;							\
	register long _num __asm__("eax") = (num);			\
	register long _arg1 __asm__("ebx") = (long)(arg1);		\
	register long _arg2 __asm__("ecx") = (long)(arg2);		\
	register long _arg3 __asm__("edx") = (long)(arg3);		\
	register long _arg4 __asm__("esi") = (long)(arg4);		\
	register long _arg5 __asm__("edi") = (long)(arg5);		\
	register long _arg6 __asm__("ebp") = (long)(arg6);		\
									\
	__asm__ volatile (						\
		"int $0x80"						\
		: "=a"(_ret)						\
		: "r"(_arg1),						\
		  "r"(_arg2),						\
		  "r"(_arg3),						\
		  "r"(_arg4),						\
		  "r"(_arg5),						\
		  "r"(_arg6),						\
		  "0"(_num)						\
		: "memory", "cc"					\
	);								\
	_ret;								\
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

#endif /* #ifndef LIBURING_ARCH_X86_SYSCALL_H */

/* SPDX-License-Identifier: MIT */

#ifndef __INTERNAL__LIBURING_LIB_H
	#error "This file should be included from src/lib.h (liburing)"
#endif

#ifndef LIBURING_ARCH_AARCH32_LIB_H
#define LIBURING_ARCH_AARCH32_LIB_H

static inline long get_page_size(void)
{
	// Couldn't find any non-4K aarch32 targets.
	// Re-evaluate this when Asahi Linux is stable.
	return 4096;
}

#endif /* #ifndef LIBURING_ARCH_AARCH32_LIB_H */

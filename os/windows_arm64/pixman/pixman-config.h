#pragma once

#ifndef __ASSEMBLER__
#include <intrin.h>
#endif
#define HAVE_FEDIVBYZERO 1

#define HAVE_FENV_H 1

#define PACKAGE foo

#define SIZEOF_LONG 4

#define TLS __declspec(thread)

// Enable ARM NEON SIMD optimizations
#define USE_ARM_NEON 1

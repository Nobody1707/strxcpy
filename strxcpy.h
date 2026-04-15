// SPDX-License-Identifier: MPL-2.0
// Copyright 2026 Michael D. Morris

#ifndef STRXCPY_H_GUARD
#define STRXCPY_H_GUARD

#include <assert.h>
#include <stddef.h>
#include <string.h>

static_assert(__STDC_VERSION__ >= 202311L,  "This header requires C23 or later.");

/// Copies at most len characters from src to dst, stopping if it
/// copies a nul. If all len characters are copied without encountering a nul
/// character, then the final character of the string is replaced with a nul.
///
/// Returns:
/// A pointer to the copied nul character, or a nullptr if the string was
/// truncated.
inline char *strxcpy(char * restrict dst, char const * restrict src, size_t len) {
  char *nul = memccpy(dst, src, '\0', len);
  if (!nul && len > 0) {
    dst[len - 1] = '\0';
  }
  return nul ? nul - 1 : nul;
}

/// If STRXCPY_DEFINE_ENTRY_POINT is defined, then an external definiton of
/// STRXCPY will be created. Exactly one TU should provide an external
/// definition.
#ifdef STRXCPY_DEFINE_ENTRY_POINT
char *strxcpy(char *dst, char const *src, size_t len);
#endif

#endif

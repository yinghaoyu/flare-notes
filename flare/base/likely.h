#ifndef FLARE_BASE_LIKELY_H_
#define FLARE_BASE_LIKELY_H_

#if __GNUC__
#define FLARE_LIKELY(expr) (__builtin_expect(!!(expr), 1))
#define FLARE_UNLIKELY(expr) (__builtin_expect(!!(expr), 0))
#else
#define FLARE_LIKELY(expr) (expr)
#define FLARE_UNLIKELY(expr) (expr)
#endif

#endif  // FLARE_BASE_LIKELY_H_

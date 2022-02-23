#pragma once
#include "../std_inc.hpp"

#undef NO_INLINE

#ifdef _WIN64 || _WIN32
#ifndef NO_INLINE
#define INLINE __forceinline
#else
#pragma warning( "WARNING! Using not inlined functions! May cause linking errors." )
#define INLINE
#endif
#else

#endif

#ifdef _WIN64
#define PLAT_W64
#elif _WIN32
#define PLAT_W32
#elif __APPLE__
#define PLAT_APPLE
#endif

#define USE_NAMESPACES

#ifdef USE_NAMESPACES
/* namespace creation */
#define XUTIL_START namespace xutil {
#define XUTIL_DETAIL_START namespace xutil::detail {
#define ENG_START namespace eng {
#define ENG_END }
#define XUTIL_END }
/* namespace access */
#define _XUTIL xutil::
#define _ENG eng::
#define _DETAIL detail::
#else
/* namespace creation */
#define XUTIL_START
#define XUTIL_DETAIL_START
#define ENG_START
#define ENG_END
#define XUTIL_END
/* namespace access */
#define _XUTIL
#define _ENG
#define _DETAIL
#endif

#ifdef CLASS_USE_PRIVATE_METHODS
#define members private
#else
#define members public
#endif

#define methods public

#define shgetfolder( _id, _to ) SHGetKnownFolderPath( _id, 0, nullptr, &_to )
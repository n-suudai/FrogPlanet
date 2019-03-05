#pragma once


// とりあえず Windows
#define FROG_PLANET_PLATFORM_WINDOWS 1


// 他のプラットフォームをすべてゼロで定義
#if !defined(FROG_PLANET_PLATFORM_WINDOWS)
#define FROG_PLANET_PLATFORM_WINDOWS 0
#endif

#if !defined(FROG_PLANET_PLATFORM_MAC)
#define FROG_PLANET_PLATFORM_MAC 0
#endif

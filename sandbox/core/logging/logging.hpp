#pragma once
#include "../plat.hpp"

XUTIL_START

/* do we log to files? */
inline constexpr auto g_file_logging{ true };

/* log some text to console and file if enabled */
void console_log( std::string_view what );

XUTIL_END

extern std::filesystem::path g_main_directory;

#ifdef XUTIL_SEC
inline bool g_main_dir_present{ false };
#define MAIN_DIR_PRESENT g_main_dir_present
#else
#define MAIN_DIR_PRESENT true
#endif

/* called in entry to create game directory */
INLINE void main_directory( ) {
	/* documents dir */
	PWSTR dir;
	shgetfolder( FOLDERID_Documents, dir );
	/* navigate to our dir */
	g_main_directory.assign( dir ) / "nle-sandbox";

	/* secure directory access */
#ifdef XUTIL_SEC
	MAIN_DIR_PRESENT = true;
#endif
}
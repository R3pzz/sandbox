#include "../logging.hpp"

/* time in logging */
#include "../../time/time.hpp"

void _XUTIL console_log( std::string_view what ) {
	auto time = std::asctime( &get_time( ) );
	auto concated = time + std::string{ what };

	std::ofstream ofs{ g_main_directory / "sandbox_log.txt" };

	/* out to a file */
	if ( g_file_logging )
		if ( MAIN_DIR_PRESENT )
			ofs << concated << std::endl;

	printf( "%s\n", concated.c_str( ) );
}

std::filesystem::path g_main_directory{};
#include "std_inc.hpp"

/* console logging */
#include "core/logging/logging.hpp"

int main( ) {
	/* navigate to main directory */
	main_directory( );

	_XUTIL console_log( "hi from sb!" );

	system( "PAUSE" );

	return 0;
}
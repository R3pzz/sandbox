#pragma once
#include "../plat.hpp"

XUTIL_START

inline constexpr auto g_dictionary{
	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };

INLINE decltype( auto ) random_string( std::size_t size ) {
	srand( time( nullptr ) );

	/* reserve buffer with given length */
	std::string temp{};
	temp.reserve( size );

	/* fill each character */
	for ( std::size_t i{}; i != size; i++ )
		temp.append( &g_dictionary[ rand() % ( sizeof( g_dictionary ) - 1 ) ] );

	return temp;
}

XUTIL_END
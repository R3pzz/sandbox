#pragma once
#include "../plat.hpp"

/* for hashing */
#include <hash/sha256.h>

/* for random string generation */
#include "random.hpp"

class actor_hasher {
	/* type of hash wee'll be generating */
public:
	static decltype( auto ) hash( ) {
		return hash( _XUTIL random_string( 32u ) );
	}

protected:
	static std::string hash( const std::string &what ) {
		return SHA256{}( what );
	}

};

inline actor_hasher *g_actor_hasher{};
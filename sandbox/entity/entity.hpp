#pragma once
#include "../core/traits/traits.hpp"
#include "../core/hasher/actor_hasher.hpp"

namespace engine::entity {
	template <typename Hash>
		requires _XUTIL _DETAIL is_hash_v<Hash>
	class basic_entity {
	public:
		/* @Desc: Makes this entity unique */
		INLINE void make_unique( ) {
			m_hash = g_actor_hasher->hash( );
			m_is_unique = true;
		}

	public:
		/* @Desc: Type of hash */
		using hash_type = Hash;

		/* @Desc: Is this entity unique */
		bool m_is_unique{};
		/* @Desc: Unique identifier */
		hash_type m_hash{};
	};

	/* @Desc: This is the class we'll use to create entities */
	template <typename Traits, typename Hash, typename Derived>
		requires _XUTIL _DETAIL is_hash_v<Hash>
	class traited_entity : public Derived {
	public:
		explicit traited_entity( ) { }

	public:
		/* @Desc:  */
		using base_type = Derived;
	};
}
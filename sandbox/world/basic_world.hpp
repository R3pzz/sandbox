#pragma once
#include "../core/plat.hpp"

namespace engine::world::detail {
	template <typename Entity, std::size_t Max>
	class world_iterator {
	public:
		/* @Desc: */
		using world_type = basic_world<Entity>;

		INLINE void from_world( const world_type& world ) {
			
		}

	public:
		/* @Desc: */
		using entity_type = Entity;
		/* @Desc: */
		using pointer_type = std::uintptr_t;
		/* @Desc: */
		using difference_type = std::ptrdiff_t;
		/* @Desc: */
		using size_type = std::size_t;

		explicit world_iterator( pointer_type *base, size_type start ) : m_size{ Max }, m_at{ start } {}

		explicit world_iterator( const world_type &world ) { from_world( world ); }

		/* @Section: Storage */


		/* @Desc: */
		size_type m_size{};
		/* @Desc: */
		size_type m_at{};
		/* @Desc: */
		pointer_type* m_base{};
	};
}

namespace engine::world {
	template <typename Entity>
	class basic_world {
	public:
		/* @Desc: */
		using contained_type = Entity;
		/* @Desc: */
	
		INLINE void register_object( const contained_type& object ) {
			m_objects.emplace( object );
		}

	public:
		/* @Desc: */
		using hash_type = std::uint32_t;

		hash_type m_unique_id{};

		std::vector<contained_type> m_objects{};
	};
}
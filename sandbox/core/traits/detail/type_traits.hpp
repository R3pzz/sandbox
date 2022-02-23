#pragma once
#include "../../plat.hpp"

XUTIL_DETAIL_START

/* @Desc: Does Type stand for hash type */
template <typename Type>
concept is_hash_v = std::_Is_any_of_v<Type, std::int16_t, std::int32_t,
	std::int64_t, std::uint16_t, std::uint32_t, std::uint64_t>;

XUTIL_END
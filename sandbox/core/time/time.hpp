#pragma once
#include "../plat.hpp"

XUTIL_START

inline std::uint32_t g_tick_count{ 0u };

template <typename _flt_ty, typename _time_ty, typename _tick_ty>
class time_info {
	/* float type */
	using float_type = _flt_ty;
	/* std::milli, ... */
	using time_type = _time_ty;
	/* tick count type */
	using tick_type = _tick_ty;

	/* no deafault ctor */
	explicit time_info( ) {
	}

methods:
	explicit time_info( std::uint32_t tick_count ) {
		
	}

members:
	/* time lasted per frame */
	float_type	m_frame_time{};
	/* current time and previous time */
	time_type	m_cur_time{},
				m_prev_time{};
	/* cur tick and previous tick */
	tick_type	m_cur_tick{},
				m_tick_count{};
};

INLINE tm get_time( ) {
	auto ctime = time( nullptr );
	auto ctm = localtime( &ctime );

	return *ctm;
}

XUTIL_END
#ifndef SPROUT_OPERATION_FIT_INSERT_HPP
#define SPROUT_OPERATION_FIT_INSERT_HPP

#include <cstddef>
#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/operation/fixed/insert.hpp>
#include <sprout/sub_array.hpp>

namespace sprout {
	namespace fit {
		namespace result_of {
			//
			// insert
			//
			template<typename Container, typename T, typename... Values>
			struct insert {
			public:
				typedef sprout::sub_array<
					typename sprout::fixed_container_traits<
						typename sprout::fixed::result_of::insert<Container, T, Values...>::type
					>::internal_type
				> type;
			};
		}	// namespace result_of

		//
		// insert
		//
		template<typename Container, typename T, typename... Values>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::insert<Container, T, Values...>::type insert(
			Container const& cont,
			typename sprout::fixed_container_traits<Container>::const_iterator pos,
			T const& v,
			Values const&... values
			)
		{
			return sprout::sub_copy(
				sprout::get_fixed(sprout::fixed::insert(cont, pos, v, values...)),
				sprout::fixed_begin_offset(cont),
				sprout::fixed_end_offset(cont) + 1 + sizeof...(Values)
				);
		}
		//
		// insert
		//
		template<typename Container, typename T, typename... Values>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::insert<Container, T, Values...>::type insert(
			Container const& cont,
			typename sprout::fixed_container_traits<Container>::difference_type pos,
			T const& v,
			Values const&... values
			)
		{
			return sprout::sub_copy(
				sprout::get_fixed(sprout::fixed::insert(cont, pos, v, values...)),
				sprout::fixed_begin_offset(cont),
				sprout::fixed_end_offset(cont) + 1 + sizeof...(Values)
				);
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_OPERATION_FIT_INSERT_HPP

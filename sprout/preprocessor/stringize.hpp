#ifndef SPROUT_PREPROCESSOR_STRINGIZE_HPP
#define SPROUT_PREPROCESSOR_STRINGIZE_HPP

#include <sprout/config.hpp>

#define SPROUT_PP_STRINGIZE_I(text) #text

//
// SPROUT_PP_STRINGIZE
//
#define SPROUT_PP_STRINGIZE(text) SPROUT_PP_STRINGIZE_I(text)

#endif	// #ifndef SPROUT_PREPROCESSOR_STRINGIZE_HPP


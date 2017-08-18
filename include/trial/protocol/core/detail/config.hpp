#ifndef TRIAL_PROTOCOL_CORE_DETAIL_CONFIG_HPP
#define TRIAL_PROTOCOL_CORE_DETAIL_CONFIG_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2017 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#if __cplusplus >= 201402L
# define TRIAL_PROTOCOL_CXX14(x) x
#else
# define TRIAL_PROTOCOL_CXX14(x)
#endif

#if defined(__GNUC__) || defined(__clang__)
# define TRIAL_PROTOCOL_UNREACHABLE() __builtin_unreachable()
#else
# define TRIAL_PROTOCOL_UNREACHABLE() assert(false)
#endif

#endif // TRIAL_PROTOCOL_CORE_DETAIL_CONFIG_HPP

#ifndef TRIAL_PROTOCOL_DETAIL_TYPE_TRAITS_HPP
#define TRIAL_PROTOCOL_DETAIL_TYPE_TRAITS_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2016 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/cstdint.hpp>
#include <boost/type_traits/conditional.hpp>

namespace trial
{
namespace protocol
{
namespace detail
{

template <typename T>
struct make_floating_point
{
    typedef typename boost::conditional<
        boost::is_same< float, boost::common_type<T, float> >::value,
        float,
        typename boost::conditional<
            boost::is_same< double, boost::common_type<T, double> >::value,
            double,
            long double
            >::type
        >::type type;
};

template <typename T>
struct make_integral
{
    // This is a crude approximation
    typedef typename boost::conditional<
        sizeof(T) <= sizeof(boost::int32_t),
            boost::int32_t, typename boost::conditional<
            sizeof(T) <= sizeof(boost::int64_t),
                boost::int64_t,
                boost::intmax_t
                >::type
        >::type type;
};

} // namespace detail
} // namespace protocol
} // namespace trial

#endif // TRIAL_PROTOCOL_DETAIL_TYPE_TRAITS_HPP

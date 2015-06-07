#ifndef TRIAL_PROTOCOL_SERIALIZATION_PAIR_HPP
#define TRIAL_PROTOCOL_SERIALIZATION_PAIR_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <utility> // std::pair
#include <trial/protocol/serialization/serialization.hpp>

namespace trial
{
namespace protocol
{
namespace serialization
{

template <typename Archive, typename T1, typename T2>
struct save_functor< Archive, typename std::pair<T1, T2> >
{
    static void save(Archive&,
                     const std::pair<T1, T2>&,
                     const unsigned int);
};

template <typename Archive, typename T1, typename T2>
struct load_functor< Archive, typename std::pair<T1, T2> >
{
    static void load(Archive&,
                     std::pair<T1, T2>&,
                     const unsigned int);
};

template <typename T1, typename T2>
struct serialize_functor< typename std::pair<T1, T2> >
{
    template <typename Archive>
    static typename boost::enable_if<typename Archive::is_loading, void>::type
    serialize(Archive& ar,
              std::pair<T1, T2>& data,
              const unsigned int version)
    {
        boost::serialization::split_free(ar, data, version);
    }

    template <typename Archive>
    static typename boost::enable_if<typename Archive::is_saving, void>::type
    serialize(Archive& ar,
              const std::pair<T1, T2>& data,
              const unsigned int version)
    {
        boost::serialization::split_free(ar, data, version);
    }
};

} // namespace serialization
} // namespace protocol
} // namespace trial

#endif // TRIAL_PROTOCOL_SERIALIZATION_PAIR_HPP

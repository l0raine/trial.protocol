#ifndef TRIAL_PROTOCOL_JSON_SERIALIZATION_STD_SET_HPP
#define TRIAL_PROTOCOL_JSON_SERIALIZATION_STD_SET_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <trial/protocol/json/serialization/serialization.hpp>
#include <trial/protocol/serialization/std/set.hpp>

namespace trial
{
namespace protocol
{
namespace serialization
{

template <typename Key, typename Compare, typename Allocator>
struct save_overloader< json::oarchive,
                        typename std::set<Key, Compare, Allocator> >
{
    static void save(json::oarchive& archive,
                     const std::set<Key, Compare, Allocator>& data,
                     const unsigned int)
    {
        archive.template save<json::token::begin_array>();
        for (typename std::set<Key, Compare, Allocator>::const_iterator it = data.begin();
             it != data.end();
             ++it)
        {
            archive.save_override(*it);
        }
        archive.template save<json::token::end_array>();
    }
};

template <typename Key, typename Compare, typename Allocator>
struct load_overloader< json::iarchive,
                        typename std::set<Key, Compare, Allocator> >
{
    static void load(json::iarchive& archive,
                     std::set<Key, Compare, Allocator>& data,
                     const unsigned int)
    {
        archive.template load<json::token::begin_array>();
        while (!archive.template at<json::token::end_array>())
        {
            Key value;
            archive.load_override(value);
            data.insert(value);
        }
        archive.template load<json::token::end_array>();
    }
};

} // namespace serialization
} // namespace protocol
} // namespace trial

#endif // TRIAL_PROTOCOL_JSON_SERIALIZATION_STD_SET_HPP
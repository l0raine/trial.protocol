#ifndef TRIAL_PROTOCOL_JSON_SERIALIZATION_DYNAMIC_VARIABLE_HPP
#define TRIAL_PROTOCOL_JSON_SERIALIZATION_DYNAMIC_VARIABLE_HPP

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
#include <trial/protocol/json/serialization/serialization.hpp>
#include <trial/protocol/serialization/dynamic/variable.hpp>
#include <trial/protocol/json/token.hpp>
#include <trial/protocol/json/detail/compact.hpp>

namespace trial
{
namespace protocol
{
namespace serialization
{

template <typename CharT>
struct save_overloader< protocol::json::basic_oarchive<CharT>,
                        typename dynamic::variable >
{
    static void save(protocol::json::basic_oarchive<CharT>& ar,
                     const dynamic::variable& data,
                     const unsigned int protocol_version)
    {
        switch (data.code())
        {
        case dynamic::code::null:
            ar.template save<json::token::null>();
            break;

        case dynamic::code::boolean:
            ar.save(data.value<bool>());
            break;

        case dynamic::code::signed_char:
            ar.save(data.value<signed char>());
            break;

        case dynamic::code::unsigned_char:
            ar.save(data.value<unsigned char>());
            break;

        case dynamic::code::signed_short_integer:
            ar.save(data.value<signed short int>());
            break;

        case dynamic::code::unsigned_short_integer:
            ar.save(data.value<unsigned short int>());
            break;

        case dynamic::code::signed_integer:
            ar.save(data.value<signed int>());
            break;

        case dynamic::code::unsigned_integer:
            ar.save(data.value<unsigned int>());
            break;

        case dynamic::code::signed_long_integer:
            ar.save(data.value<signed long int>());
            break;

        case dynamic::code::unsigned_long_integer:
            ar.save(data.value<unsigned long int>());
            break;

        case dynamic::code::signed_long_long_integer:
            ar.save(data.value<signed long long int>());
            break;

        case dynamic::code::unsigned_long_long_integer:
            ar.save(data.value<unsigned long long int>());
            break;

        case dynamic::code::real:
            ar.save(data.value<float>());
            break;

        case dynamic::code::long_real:
            ar.save(data.value<double>());
            break;

        case dynamic::code::long_long_real:
            ar.save(data.value<long double>());
            break;

        case dynamic::code::string:
            ar.save(data.value<dynamic::string>());
            break;

        case dynamic::code::wstring:
        case dynamic::code::u16string:
        case dynamic::code::u32string:
            throw json::error(json::incompatible_type);

        case dynamic::code::array:
            ar.template save<json::token::begin_array>();
            for (const auto& item : data)
            {
                ar.save_override(item, protocol_version);
            }
            ar.template save<json::token::end_array>();
            break;

        case dynamic::code::map:
            ar.template save<json::token::begin_object>();
            for (auto it = data.begin(); it != data.end(); ++it)
            {
                ar.save_override(it.key(), protocol_version);
                ar.save_override(it.value(), protocol_version);
            }
            ar.template save<json::token::end_object>();
            break;
        }
    }
};

template <typename CharT>
struct load_overloader< protocol::json::basic_iarchive<CharT>,
                        typename dynamic::variable >
{
    static void load(protocol::json::basic_iarchive<CharT>& ar,
                     dynamic::variable& data,
                     const unsigned int /* protocol_version */)
    {
        using namespace trial::protocol::json;
        switch (ar.symbol())
        {
        case token::symbol::null:
            ar.template load<token::null>();
            data = dynamic::null;
            break;

        case token::symbol::boolean:
            {
                bool value = {};
                ar.load(value);
                data = value;
            }
            break;

        case token::symbol::integer:
            {
                std::intmax_t value = {};
                ar.load(value);
                data = json::detail::compact<dynamic::variable>(value);
            }
            break;

        case token::symbol::real:
            {
                long double value = {};
                ar.load(value);
                data = json::detail::compact<dynamic::variable>(value);
            }
            break;

        case token::symbol::string:
            {
                std::string value;
                ar.load(value);
                data = value;
            }
            break;

        case token::symbol::begin_array:
            {
                ar.template load<token::begin_array>();
                data = dynamic::array::make();
                while (!ar.template at<token::end_array>())
                {
                    dynamic::variable value;
                    ar.load_override(value);
                    data.insert(data.end(), value);
                }
                ar.template load<token::end_array>();
            }
            break;

        case token::symbol::begin_object:
            {
                ar.template load<token::begin_object>();
                data = dynamic::map::make();
                while (!ar.template at<token::end_object>())
                {
                    std::string key;
                    ar.load_override(key);
                    dynamic::variable value;
                    ar.load_override(value);
                    data.insert(data.end(), { std::move(key), std::move(value) });
                }
                ar.template load<token::end_object>();
            }
            break;

        default:
            assert(false);
            break;
        }
    }
};

} // namespace serialization
} // namespace protocol
} // namespace trial

#endif // TRIAL_PROTOCOL_JSON_SERIALIZATION_DYNAMIC_VARIABLE_HPP

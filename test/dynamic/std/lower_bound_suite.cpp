///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2017 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <trial/protocol/core/detail/lightweight_test.hpp>
#include <trial/dynamic/variable.hpp>

using namespace trial::dynamic;

//-----------------------------------------------------------------------------
// std::lower_bound
//-----------------------------------------------------------------------------

void find_null()
{
    variable data;
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
}

void find_boolean()
{
    variable data(true);
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
}

void find_integer()
{
    variable data(2);
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
}

void find_real()
{
    variable data(3.0);
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
}

void find_string()
{
    variable data("alpha");
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
}

void find_wstring()
{
    variable data(L"bravo");
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
}

void find_u16string()
{
    variable data(u"charlie");
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
}

void find_u32string()
{
    variable data(U"delta");
    {
        auto where = std::lower_bound(data.begin(), data.end(), null);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
}

void find_array()
{
    variable data = array::make({true, 2, 3.0, "alpha", L"bravo", u"charlie", U"delta"});
    {
        auto where = std::lower_bound(data.begin(), data.end(), 0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 2);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 4);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 3);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 3);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "zulu");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 4);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 4);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"zulu");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 5);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 5);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"zulu");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 6);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 6);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"zulu");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 7);
    }
}

void find_map()
{
    variable data = map::make(
        {
            { "alpha", true },
            { "bravo", 2 },
            { "charlie", 3.0 },
            { "delta", "hydrogen" },
            { "echo", L"helium" },
            { "golf", u"lithium" },
            { "hotel", U"beryllium" }
        });
    {
        auto where = std::lower_bound(data.begin(), data.end(), 0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), true);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 2);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 3.0);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 2);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), 4);
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 3);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "hydrogen");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 3);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), "tungsten");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 4);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"helium");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 4);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), L"tungsten");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 5);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"lithium");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 5);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), u"tungsten");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 6);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"beryllium");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.begin(), where), 6);
    }
    {
        auto where = std::lower_bound(data.begin(), data.end(), U"tungsten");
        TRIAL_PROTOCOL_TEST(where == data.end());
    }
}

void find_key_map()
{
    variable data = map::make(
        {
            { "alpha", true },
            { "bravo", 2 },
            { "charlie", 3.0 },
            { "delta", "hydrogen" }
        });
    {
        auto where = std::lower_bound(data.key_begin(), data.key_end(), "alpha");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.key_begin(), where), 0);
    }
    {
        auto where = std::lower_bound(data.key_begin(), data.key_end(), "bravo");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.key_begin(), where), 1);
    }
    {
        auto where = std::lower_bound(data.key_begin(), data.key_end(), "charlie");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.key_begin(), where), 2);
    }
    {
        auto where = std::lower_bound(data.key_begin(), data.key_end(), "delta");
        TRIAL_PROTOCOL_TEST_EQUAL(std::distance(data.key_begin(), where), 3);
    }
    {
        auto where = std::lower_bound(data.key_begin(), data.key_end(), "hydrogen");
        TRIAL_PROTOCOL_TEST(where == data.key_end());
    }
}

int main()
{
    find_null();
    find_boolean();
    find_integer();
    find_real();
    find_string();
    find_wstring();
    find_u16string();
    find_u32string();
    find_array();
    find_map();
    find_key_map();

    return boost::report_errors();
}

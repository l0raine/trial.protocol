#ifndef TRIAL_PROTOCOL_TRANSENC_SERIALIZATION_OARCHIVE_HPP
#define TRIAL_PROTOCOL_TRANSENC_SERIALIZATION_OARCHIVE_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015 Bjorn Reese <breese@users.sourceforge.net>
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <boost/archive/detail/common_oarchive.hpp>
#include <trial/protocol/transenc/writer.hpp>

namespace trial
{
namespace protocol
{
namespace transenc
{

class oarchive
    : public boost::archive::detail::common_oarchive<oarchive>
{
    friend class boost::archive::save_access;

public:
    template <typename T>
    oarchive(T&);

    template <typename T>
    void save_override(const T& data);
    template <typename T>
    void save_override(const T& data, long);

    template <typename T>
    void save(const T& data);

    template <typename T>
    void save();

    // Ignore these
    void save_override(const boost::archive::version_type) {}
    void save_override(const boost::archive::object_id_type) {}
    void save_override(const boost::archive::object_reference_type) {}
    void save_override(const boost::archive::class_id_type) {}
    void save_override(const boost::archive::class_id_optional_type) {}
    void save_override(const boost::archive::class_id_reference_type) {}
    void save_override(const boost::archive::tracking_type) {}
    void save_override(const boost::archive::class_name_type&) {}

protected:
    transenc::writer writer;
};

} // namespace transenc
} // namespace protocol
} // namespace trial

#include <trial/protocol/transenc/serialization/detail/oarchive.ipp>

#include <boost/archive/detail/register_archive.hpp>

BOOST_SERIALIZATION_REGISTER_ARCHIVE(trial::protocol::transenc::oarchive);

#endif // TRIAL_PROTOCOL_TRANSENC_SERIALIZATION_OARCHIVE_HPP
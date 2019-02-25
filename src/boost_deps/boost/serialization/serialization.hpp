#ifndef BOOST_SERIALIZATION_SERIALIZATION_HPP
#define BOOST_SERIALIZATION_SERIALIZATION_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1310)
#  pragma warning (disable : 4675) // suppress ADL warning
#endif

#include <boost/config.hpp>
#include <boost/serialization/strong_typedef.hpp>
#include <boost/serialization/pfto.hpp>
#include <boost/serialization/throw_exception.hpp>
#include <boost/serialization/nvp.hpp>

// incremented for each "release"
#define BOOST_SERIALIZATION_LIBRARY_VERSION 19

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// serialization.hpp: interface for serialization system.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

//////////////////////////////////////////////////////////////////////
// public interface to serialization. 

/////////////////////////////////////////////////////////////////////////////
// layer 0 - intrusive verison
// declared and implemented for each user defined class to be serialized
//
//  template<Archive>
//  serialize(Archive &ar, const unsigned int file_version){
//      ar & base_object<base>(*this) & member1 & member2 ... ;
//  }

/////////////////////////////////////////////////////////////////////////////
// layer 1 - layer that routes member access through the access class.
// this is what permits us to grant access to private class member functions
// by specifying friend class vinaboost::serialization::access

#include <boost/serialization/access.hpp>

/////////////////////////////////////////////////////////////////////////////
// layer 2 - default implementation of non-intrusive serialization.
//
// note the usage of function overloading to compensate that C++ does not
// currently support Partial Template Specialization for function templates 
// We have declared the version number as "const unsigned long".  
// Overriding templates for specific data types should declare the version
// number as "const unsigned int". Template matching will first be applied
// to functions with the same version types - that is the overloads.  
// If there is no declared function prototype that matches, the second argument
// will be converted to "const unsigned long" and a match will be made with 
// one of the default template functions below.

namespace vinaboost {
namespace serialization {

BOOST_STRONG_TYPEDEF(unsigned int, version_type)

// default implementation - call the member function "serialize"
template<class Archive, class T>
inline void serialize(
    Archive & ar, T & t, const BOOST_PFTO unsigned int file_version
){
    access::serialize(ar, t, static_cast<unsigned int>(file_version));
}

// save data required for construction
template<class Archive, class T>
inline void save_construct_data(
    Archive & /*ar*/, 
    const T * /*t*/, 
    const BOOST_PFTO unsigned int /*file_version */
){
    // default is to save no data because default constructor
    // requires no arguments.
}

// load data required for construction and invoke constructor in place
template<class Archive, class T>
inline void load_construct_data(
    Archive & /*ar*/, 
    T * t, 
    const BOOST_PFTO unsigned int /*file_version*/
){
    // default just uses the default constructor.  going
    // through access permits usage of otherwise private default
    // constructor
    access::construct(t);
}

/////////////////////////////////////////////////////////////////////////////
// layer 3 - move call into serialization namespace so that ADL will function
// in the manner we desire.
//
// on compilers which don't implement ADL. only the current namespace
// i.e. vinaboost::serialization will be searched.
// 
// on compilers which DO implement ADL
// serialize overrides can be in any of the following
// 
// 1) same namepace as Archive
// 2) same namespace as T
// 3) vinaboost::serialization
//
// Due to Martin Ecker

template<class Archive, class T>
inline void serialize_adl(
    Archive & ar, 
    T & t, 
    const unsigned int file_version
){
    // note usage of function overloading to delay final resolution
    // until the point of instantiation.  This works around the two-phase
    // lookup "feature" which inhibits redefintion of a default function
    // template implementation. Due to Robert Ramey
    //
    // Note that this trick generates problems for compiles which don't support
    // PFTO, suppress it here.  As far as we know, there are no compilers
    // which fail to support PFTO while supporting two-phase lookup.
    #if ! defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
        const version_type v(file_version);
        serialize(ar, t, v);
    #else
        serialize(ar, t, file_version);
    #endif
}

template<class Archive, class T>
inline void save_construct_data_adl(
    Archive & ar, 
    const T * t, 
    const unsigned int file_version
){
    // see above
    #if ! defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
        const version_type v(file_version);
        save_construct_data(ar, t, v);
    #else
        save_construct_data(ar, t, file_version);
    #endif
}

template<class Archive, class T>
inline void load_construct_data_adl(
    Archive & ar, 
    T * t, 
    const unsigned int file_version
){
    // see above comment
    #if ! defined(BOOST_NO_FUNCTION_TEMPLATE_ORDERING)
        const version_type v(file_version);
        load_construct_data(ar, t, v);
    #else
        load_construct_data(ar, t, file_version);
    #endif
}

} // namespace serialization
} // namespace vinaboost

#endif //BOOST_SERIALIZATION_SERIALIZATION_HPP

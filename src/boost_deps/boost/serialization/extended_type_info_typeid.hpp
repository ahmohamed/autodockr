#ifndef BOOST_SERIALIZATION_EXTENDED_TYPE_INFO_TYPEID_HPP
#define BOOST_SERIALIZATION_EXTENDED_TYPE_INFO_TYPEID_HPP

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

// extended_type_info_typeid.hpp: implementation for version that depends
// on runtime typing (rtti - typeid) but uses a user specified string
// as the portable class identifier.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <typeinfo>
#include <cstdarg>
#include <cassert>
#include <boost/config.hpp>

#include <boost/static_assert.hpp>
#include <boost/serialization/static_warning.hpp>
#include <boost/type_traits/is_polymorphic.hpp>
#include <boost/type_traits/remove_const.hpp>

#include <boost/serialization/singleton.hpp>
#include <boost/serialization/extended_type_info.hpp>
#include <boost/serialization/factory.hpp>

#include <boost/mpl/if.hpp>

#include <boost/config/abi_prefix.hpp> // must be the last header
#ifdef BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4251 4231 4660 4275)
#endif

namespace vinaboost {
namespace serialization {
namespace typeid_system {

class BOOST_SERIALIZATION_DECL(BOOST_PP_EMPTY()) extended_type_info_typeid_0 : 
    public extended_type_info
{
    virtual const char * get_debug_info() const {
        if(static_cast<const std::type_info *>(0) == m_ti)
            return static_cast<const char *>(0);
        return m_ti->name();
    }
protected:
    const std::type_info * m_ti;
    extended_type_info_typeid_0(const char * key);
    ~extended_type_info_typeid_0();
    void type_register(const std::type_info & ti);
    void type_unregister();
    const extended_type_info *
    get_extended_type_info(const std::type_info & ti) const;
public:
    virtual bool
    is_less_than(const extended_type_info &rhs) const;
    virtual bool
    is_equal(const extended_type_info &rhs) const;
    const std::type_info & get_typeid() const {
        return *m_ti;
    }
};

} // typeid_system

template<class T>
class extended_type_info_typeid : 
    public typeid_system::extended_type_info_typeid_0,
    public singleton<extended_type_info_typeid<T> >
{
public:
    extended_type_info_typeid() :
        typeid_system::extended_type_info_typeid_0(get_key())
    {
        type_register(typeid(T));
        key_register();
    }
    ~extended_type_info_typeid(){
        key_unregister();
        type_unregister();
    }
    // get the eti record for the true type of this record
    // relying upon standard type info implemenation (rtti)
    const extended_type_info *
    get_derived_extended_type_info(const T & t) const {
        // note: this implementation - based on usage of typeid (rtti)
        // only does something if the class has at least one virtual function.
        BOOST_STATIC_WARNING(vinaboost::is_polymorphic<T>::value);
        return 
            typeid_system::extended_type_info_typeid_0::get_extended_type_info(
                typeid(t)
            );
    }
    const char * get_key() const {
        return vinaboost::serialization::guid<T>();
    }
    virtual void * construct(unsigned int count, ...) const{
        // count up the arguments
        std::va_list ap;
        va_start(ap, count);
        switch(count){
        case 0:
            return factory<vinaboost::remove_const<T>, 0>(ap);
        case 1:
            return factory<vinaboost::remove_const<T>, 1>(ap);
        case 2:
            return factory<vinaboost::remove_const<T>, 2>(ap);
        case 3:
            return factory<vinaboost::remove_const<T>, 3>(ap);
        case 4:
            return factory<vinaboost::remove_const<T>, 4>(ap);
        default:
            assert(false); // too many arguments
            // throw exception here?
            return NULL;
        }
    }
    virtual void destroy(void const * const /* p */) const {
        // the only current usage of extended type info is in the
        // serialization library.  The statement below requires
        // that destructor of type T be public and this creates
        // a problem for some users.  So, for now, comment this
        // out 
        //delete static_cast<T const *>(p);
        // and trap any attempt to invoke this function
        assert(false);
    }
};

} // namespace serialization
} // namespace vinaboost

///////////////////////////////////////////////////////////////////////////////
// If no other implementation has been designated as default, 
// use this one.  To use this implementation as the default, specify it
// before any of the other headers.
#ifndef BOOST_SERIALIZATION_DEFAULT_TYPE_INFO
    #define BOOST_SERIALIZATION_DEFAULT_TYPE_INFO
    namespace vinaboost {
    namespace serialization {
    template<class T>
    struct extended_type_info_impl {
        typedef BOOST_DEDUCED_TYPENAME 
            vinaboost::serialization::extended_type_info_typeid<T> type;
    };
    } // namespace serialization
    } // namespace vinaboost
#endif

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif
#include <boost/config/abi_suffix.hpp> // pops abi_suffix.hpp pragmas

#endif // BOOST_SERIALIZATION_EXTENDED_TYPE_INFO_TYPEID_HPP

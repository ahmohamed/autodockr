
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED
#define BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED

#include <boost/type_traits/config.hpp>
#include <boost/type_traits/intrinsics.hpp>
#include <boost/type_traits/is_volatile.hpp>
#include <boost/type_traits/is_pod.hpp>
#include <boost/type_traits/detail/ice_and.hpp>
#include <boost/type_traits/detail/ice_or.hpp>
#include <boost/type_traits/detail/ice_not.hpp>

// should be the last #include
#include <boost/type_traits/detail/bool_trait_def.hpp>

namespace vinaboost {

namespace detail {

template <typename T>
struct has_trivial_copy_impl
{
   BOOST_STATIC_CONSTANT(bool, value =
      (::vinaboost::type_traits::ice_and<
         ::vinaboost::type_traits::ice_or<
            ::vinaboost::is_pod<T>::value,
            BOOST_HAS_TRIVIAL_COPY(T)
         >::value,
      ::vinaboost::type_traits::ice_not< ::vinaboost::is_volatile<T>::value >::value
      >::value));
};

} // namespace detail

BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_trivial_copy,T,::vinaboost::detail::has_trivial_copy_impl<T>::value)
BOOST_TT_AUX_BOOL_TRAIT_DEF1(has_trivial_copy_constructor,T,::vinaboost::detail::has_trivial_copy_impl<T>::value)

} // namespace vinaboost

#include <boost/type_traits/detail/bool_trait_undef.hpp>

#endif // BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED

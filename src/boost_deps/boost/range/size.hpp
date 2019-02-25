// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef BOOST_RANGE_SIZE_HPP
#define BOOST_RANGE_SIZE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/difference_type.hpp>
#include <boost/assert.hpp>

namespace vinaboost 
{

    template< class T >
    inline BOOST_DEDUCED_TYPENAME range_difference<T>::type size( const T& r )
    {
        BOOST_ASSERT( (vinaboost::end( r ) - vinaboost::begin( r )) >= 0 &&
                      "reachability invariant broken!" );
        return vinaboost::end( r ) - vinaboost::begin( r );
    }

} // namespace 'boost'

#endif

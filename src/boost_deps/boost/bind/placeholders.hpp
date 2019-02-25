#ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/placeholders.hpp - _N definitions
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/bind/bind.html for documentation.
//

#include <boost/bind/arg.hpp>
#include <boost/config.hpp>

namespace
{

#if defined(__BORLANDC__) || defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ < 400)

static inline vinaboost::arg<1> _1() { return vinaboost::arg<1>(); }
static inline vinaboost::arg<2> _2() { return vinaboost::arg<2>(); }
static inline vinaboost::arg<3> _3() { return vinaboost::arg<3>(); }
static inline vinaboost::arg<4> _4() { return vinaboost::arg<4>(); }
static inline vinaboost::arg<5> _5() { return vinaboost::arg<5>(); }
static inline vinaboost::arg<6> _6() { return vinaboost::arg<6>(); }
static inline vinaboost::arg<7> _7() { return vinaboost::arg<7>(); }
static inline vinaboost::arg<8> _8() { return vinaboost::arg<8>(); }
static inline vinaboost::arg<9> _9() { return vinaboost::arg<9>(); }

#elif defined(BOOST_MSVC) || (defined(__DECCXX_VER) && __DECCXX_VER <= 60590031) || defined(__MWERKS__) || \
    defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ == 400)  

static vinaboost::arg<1> _1;
static vinaboost::arg<2> _2;
static vinaboost::arg<3> _3;
static vinaboost::arg<4> _4;
static vinaboost::arg<5> _5;
static vinaboost::arg<6> _6;
static vinaboost::arg<7> _7;
static vinaboost::arg<8> _8;
static vinaboost::arg<9> _9;

#else

vinaboost::arg<1> _1;
vinaboost::arg<2> _2;
vinaboost::arg<3> _3;
vinaboost::arg<4> _4;
vinaboost::arg<5> _5;
vinaboost::arg<6> _6;
vinaboost::arg<7> _7;
vinaboost::arg<8> _8;
vinaboost::arg<9> _9;

#endif

} // unnamed namespace

#endif // #ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

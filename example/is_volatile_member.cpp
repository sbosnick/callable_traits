/*<-
Copyright (c) 2016 Barrett Adair

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
->*/

#include <boost/callable_traits/config.hpp>

#ifdef CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS
int main(){ return 0; }
#else

//[ is_volatile_member
#include <type_traits>
#include <boost/callable_traits/is_volatile_member.hpp>

namespace ct = boost::callable_traits;

static_assert(ct::is_volatile_member<int() volatile>::value, "");
static_assert(ct::is_volatile_member<int() const volatile>::value, "");
static_assert(!ct::is_volatile_member<int()>::value, "");

struct foo;

static_assert(ct::is_volatile_member<int(foo::*)() volatile>::value, "");
static_assert(!ct::is_volatile_member<int(foo::*)() const>::value, "");
static_assert(!ct::is_volatile_member<int(foo::*)()>::value, "");

int main() {}
//]
#endif

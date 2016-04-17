/*
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
*/

#include <type_traits>
#include <functional>
#include <tuple>
#include <callable_traits/add_member_cv.hpp>

#ifndef CT_ASSERT
#define CT_ASSERT(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#endif //CT_ASSERT

#ifdef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS
#define LREF
#define RREF
#else
#define LREF &
#define RREF &&
#endif

struct foo {};

namespace ct = callable_traits;

int main() {

    {
        using f =   void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...);
        using l =   void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) LREF;
        using r =   void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) RREF;
        using c =   void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) const;
        using cl =  void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) const LREF;
        using cr =  void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) const RREF;
        using v =   void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) volatile;
        using vl =  void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) volatile LREF;
        using vr =  void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) volatile RREF;
        using cv =  void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) const volatile;
        using cvl = void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) const volatile LREF;
        using cvr = void(CALLABLE_TRAITS_DEFAULT_VARARGS_CC foo::*)(...) const volatile RREF;

        CT_ASSERT(std::is_same<cv,   ct::add_member_cv<f>>{});
        CT_ASSERT(std::is_same<cv,   ct::add_member_cv<c>>{});
        CT_ASSERT(std::is_same<cvl,  ct::add_member_cv<l>>{});
        CT_ASSERT(std::is_same<cvl,  ct::add_member_cv<cl>>{});
        CT_ASSERT(std::is_same<cvr,  ct::add_member_cv<r>>{});
        CT_ASSERT(std::is_same<cvr,  ct::add_member_cv<cr>>{});
        CT_ASSERT(std::is_same<cv,  ct::add_member_cv<v>>{});
        CT_ASSERT(std::is_same<cv,  ct::add_member_cv<cv>>{});
        CT_ASSERT(std::is_same<cvl, ct::add_member_cv<vl>>{});
        CT_ASSERT(std::is_same<cvl, ct::add_member_cv<cvl>>{});
        CT_ASSERT(std::is_same<cvr, ct::add_member_cv<vr>>{});
        CT_ASSERT(std::is_same<cvr, ct::add_member_cv<cvr>>{});
    }

    {
        using f =   void(foo::* volatile)(int, int);
        using l =   void(foo::* volatile)(int, int) LREF;
        using r =   void(foo::* volatile)(int, int) RREF;
        using c =   void(foo::* volatile)(int, int) const;
        using cl =  void(foo::* volatile)(int, int) const LREF;
        using cr =  void(foo::* volatile)(int, int) const RREF;
        using v =   void(foo::* volatile)(int, int) volatile;
        using vl =  void(foo::* volatile)(int, int) volatile LREF;
        using vr =  void(foo::* volatile)(int, int) volatile RREF;
        using cv =  void(foo::* volatile)(int, int) const volatile;
        using cvl = void(foo::* volatile)(int, int) const volatile LREF;
        using cvr = void(foo::* volatile)(int, int) const volatile RREF;

        CT_ASSERT(std::is_same<cv,   ct::add_member_cv<f>>{});
        CT_ASSERT(std::is_same<cv,   ct::add_member_cv<c>>{});
        CT_ASSERT(std::is_same<cvl,  ct::add_member_cv<l>>{});
        CT_ASSERT(std::is_same<cvl,  ct::add_member_cv<cl>>{});
        CT_ASSERT(std::is_same<cvr,  ct::add_member_cv<r>>{});
        CT_ASSERT(std::is_same<cvr,  ct::add_member_cv<cr>>{});
        CT_ASSERT(std::is_same<cv,  ct::add_member_cv<v>>{});
        CT_ASSERT(std::is_same<cv,  ct::add_member_cv<cv>>{});
        CT_ASSERT(std::is_same<cvl, ct::add_member_cv<vl>>{});
        CT_ASSERT(std::is_same<cvl, ct::add_member_cv<cvl>>{});
        CT_ASSERT(std::is_same<cvr, ct::add_member_cv<vr>>{});
        CT_ASSERT(std::is_same<cvr, ct::add_member_cv<cvr>>{});
    }

#ifndef CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS

    {
        using f =   void();
        using l =   void() LREF;
        using r =   void() RREF;
        using c =   void() const;
        using cl =  void() const LREF;
        using cr =  void() const RREF;
        using v =   void() volatile;
        using vl =  void() volatile LREF;
        using vr =  void() volatile RREF;
        using cv =  void() const volatile;
        using cvl = void() const volatile LREF;
        using cvr = void() const volatile RREF;

        CT_ASSERT(std::is_same<cv,   ct::add_member_cv<f>>{});
        CT_ASSERT(std::is_same<cv,   ct::add_member_cv<c>>{});
        CT_ASSERT(std::is_same<cvl,  ct::add_member_cv<l>>{});
        CT_ASSERT(std::is_same<cvl,  ct::add_member_cv<cl>>{});
        CT_ASSERT(std::is_same<cvr,  ct::add_member_cv<r>>{});
        CT_ASSERT(std::is_same<cvr,  ct::add_member_cv<cr>>{});
        CT_ASSERT(std::is_same<cv,  ct::add_member_cv<v>>{});
        CT_ASSERT(std::is_same<cv,  ct::add_member_cv<cv>>{});
        CT_ASSERT(std::is_same<cvl, ct::add_member_cv<vl>>{});
        CT_ASSERT(std::is_same<cvl, ct::add_member_cv<cvl>>{});
        CT_ASSERT(std::is_same<cvr, ct::add_member_cv<vr>>{});
        CT_ASSERT(std::is_same<cvr, ct::add_member_cv<cvr>>{});
    }

#endif //#ifndef CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS
}
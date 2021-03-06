/*

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_DETAIL_PMF_HPP
#define CALLABLE_TRAITS_DETAIL_PMF_HPP

#include <boost/callable_traits/detail/fwd/pmf_fwd.hpp>
#include <boost/callable_traits/detail/set_function_qualifiers.hpp>
#include <boost/callable_traits/detail/qualifier_flags.hpp>
#include <boost/callable_traits/detail/default_callable_traits.hpp>
#include <boost/callable_traits/detail/utility.hpp>
#include <tuple>

CALLABLE_TRAITS_DETAIL_NAMESPACE_BEGIN

        template<qualifier_flags Applied, bool IsTransactionSafe, bool IsNoExcept, typename CallingConvention,
            typename T, typename Return, typename... Args>
        struct set_member_function_qualifiers_t;

        template<qualifier_flags Applied, bool IsTransactionSafe, bool IsNoexcept, typename CallingConvention,
            typename T, typename Return, typename... Args>
        struct set_varargs_member_function_qualifiers_t;

        template<qualifier_flags Flags, bool IsTransactionSafe, bool IsNoexcept, typename... Ts>
        using set_member_function_qualifiers =
            typename set_member_function_qualifiers_t<Flags, IsTransactionSafe, IsNoexcept, Ts...>::type;

        template<qualifier_flags Flags, bool IsTransactionSafe, bool IsNoexcept, typename... Ts>
        using set_varargs_member_function_qualifiers =
            typename set_varargs_member_function_qualifiers_t<Flags, IsTransactionSafe, IsNoexcept, Ts...>::type;

        template<typename T>
        struct pmf : default_callable_traits<T> {};

        #define CALLABLE_TRAITS_CC_TAG dummy
        #define CALLABLE_TRAITS_VARARGS_CC CALLABLE_TRAITS_DEFAULT_VARARGS_CC
        #define CALLABLE_TRAITS_CC
        #include <boost/callable_traits/detail/unguarded/pmf.hpp>
        #undef CALLABLE_TRAITS_CC
        #undef CALLABLE_TRAITS_CC_TAG
        #undef CALLABLE_TRAITS_VARARGS_CC


        #define CALLABLE_TRAITS_CC_TAG dummy
        #define CALLABLE_TRAITS_VARARGS_CC CALLABLE_TRAITS_DEFAULT_VARARGS_CC
        #define CALLABLE_TRAITS_CC
        #include <boost/callable_traits/detail/unguarded/pmf_varargs.hpp>
        #undef CALLABLE_TRAITS_CC
        #undef CALLABLE_TRAITS_CC_TAG
        #undef CALLABLE_TRAITS_VARARGS_CC

        #ifdef CALLABLE_TRAITS_ENABLE_CDECL
        #define CALLABLE_TRAITS_CC_TAG cdecl_tag
        #define CALLABLE_TRAITS_VARARGS_CC __cdecl
        #define CALLABLE_TRAITS_CC __cdecl
        #include <boost/callable_traits/detail/unguarded/pmf.hpp>
        #undef CALLABLE_TRAITS_CC
        #undef CALLABLE_TRAITS_CC_TAG
        #undef CALLABLE_TRAITS_VARARGS_CC

        #endif //CALLABLE_TRAITS_ENABLE_CDECL

        #ifdef CALLABLE_TRAITS_ENABLE_STDCALL
        #define CALLABLE_TRAITS_CC_TAG stdcall_tag
        #define CALLABLE_TRAITS_VARARGS_CC CALLABLE_TRAITS_DEFAULT_VARARGS_CC
        #define CALLABLE_TRAITS_CC __stdcall
        #include <boost/callable_traits/detail/unguarded/pmf.hpp>
        #undef CALLABLE_TRAITS_CC
        #undef CALLABLE_TRAITS_CC_TAG
        #undef CALLABLE_TRAITS_VARARGS_CC
        #endif

        #ifdef CALLABLE_TRAITS_ENABLE_FASTCALL
        #define CALLABLE_TRAITS_CC_TAG fastcall_tag
        #define CALLABLE_TRAITS_VARARGS_CC CALLABLE_TRAITS_DEFAULT_VARARGS_CC
        #define CALLABLE_TRAITS_CC __fastcall
        #include <boost/callable_traits/detail/unguarded/pmf.hpp>
        #undef CALLABLE_TRAITS_CC
        #undef CALLABLE_TRAITS_CC_TAG
        #undef CALLABLE_TRAITS_VARARGS_CC
        #endif

CALLABLE_TRAITS_DETAIL_NAMESPACE_END

#endif

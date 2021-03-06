/*

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_DETAIL_FWD_FUNCTION_OBJECT_FWD_HPP
#define CALLABLE_TRAITS_DETAIL_FWD_FUNCTION_OBJECT_FWD_HPP

#include <boost/callable_traits/detail/utility.hpp>
#include <boost/callable_traits/detail/pmf.hpp>

CALLABLE_TRAITS_DETAIL_NAMESPACE_BEGIN

    template<typename T>
    struct has_normal_call_operator
    {
        template<typename N, N Value>
        struct check { check(std::nullptr_t) {} };

        template<typename U>
        static std::int8_t test(
            check<decltype(&U::operator()), &U::operator()>);

        template<typename>
        static std::int16_t test(...);

        static constexpr bool value =
            sizeof(test<T>(nullptr)) == sizeof(std::int8_t);
    };

    struct callable_dummy {
        void operator()() {}
    };

    template<typename T>
    using default_to_function_object = typename std::conditional<
        has_normal_call_operator<T>::value,
        T,
        callable_dummy
    >::type;

    template<typename T>
    using function_object_base = typename std::conditional<
        has_normal_call_operator<T>::value,
        pmf<decltype(&default_to_function_object<T>::operator())>,
        default_callable_traits<T>
    >::type;

    template<typename T, typename Base = function_object_base<T>>
    struct function_object;

CALLABLE_TRAITS_DETAIL_NAMESPACE_END


#endif

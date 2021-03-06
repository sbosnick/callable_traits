/*<-
Copyright (c) 2016 Barrett Adair

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
->*/


#include <tuple>
#include <boost/callable_traits/expand_args.hpp>
#include "test.hpp"

int main() {

    {
        using f = void();
        using expect = std::tuple<>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }

    {
        using f = void(*)();
        using expect = std::tuple<>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }

    {
        using f = void(&)();
        using expect = std::tuple<>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }

    {
        using f = void(int, char);
        using expect = std::tuple<int, char>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }

    {
        using f = void(*)(int, char);
        using expect = std::tuple<int, char>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }

    {
        using f = void(&)(int, char);
        using expect = std::tuple<int, char>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }

    {
        auto lambda = [](int, char){};
        using f = decltype(lambda);
        using expect = std::tuple<int, char>;
        assert_same< expand_args_t<f, std::tuple>, expect>();
    }
}

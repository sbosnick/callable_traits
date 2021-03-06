#include <tuple>
#include <utility>
#include <type_traits>
#include <boost/callable_traits.hpp>
#include "test.hpp"


template<int I>
struct N {};

struct foo;

template<typename... Ts>
using sig = int(foo::*)(Ts..., ...) const;

int main() {

    {
        using f = sig<N<0>, N<1>, N<2>, N<3>, N<4>>;
        using test =  push_back_args_t<f, int&, char*>;
        using expect = sig<N<0>, N<1>, N<2>, N<3>, N<4>, int&, char*>;
        CT_ASSERT(std::is_same<test, expect>::value);
    }
}


#include <iostream>
#include <type_traits>
#include <algorithm>

template<class... T >
using common_type_t = typename std::common_type<T...>::type;

double max_variadic() {
    return 0.0;
}

template <typename ... Types>
common_type_t<Types...> max_variadic(Types... args) {
    return std::max({static_cast<common_type_t<Types...>>(args)...});
}

int main() {
    std::cout << max_variadic(1, 4.5, 3.0, 2, 2.9f) << std::endl;
    std::cout << max_variadic(1) << std::endl;
    return 0;
}
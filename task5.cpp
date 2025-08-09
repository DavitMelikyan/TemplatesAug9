#include <iostream>

template <typename T1, typename T2>
struct isSame {
    enum {val = 0};
};

template <typename T>
struct isSame<T, T> {
    enum {val = 1};
};

template <typename T, typename... Types>
struct isUnique;

template <typename T, typename T1, typename ...Types>
struct isUnique<T, T1, Types...> {
    enum {val = isSame<T, T1>::val ? 0 : isUnique<T, Types...>::val};
};

template <typename T>
struct isUnique<T> {
    enum {val = 1};
};

template <typename ...Types>
struct count_types;

template <typename T, typename T1, typename ...Types>
struct count_types<T, T1, Types...> {
    enum {val = (isUnique<T, T1, Types...>::val ? 1 : 0) + count_types<T1,Types...>::val};
};

template <typename T>
struct count_types<T> {
    enum {val = 1};
};

template <>
struct count_types<> {
    enum { val = 0 };
};

int main() {
    std::cout << count_types<int, double, std::string, char, float>::val << std::endl;
    std::cout << count_types<int, int, double>::val << std::endl;
    std::cout << count_types<>::val << std::endl;
    std::cout << count_types<int, int, int>::val << std::endl;
}
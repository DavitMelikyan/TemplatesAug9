#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
void print_with_separator(const T& separator) { 
    std::cout << std::endl;
}

template <typename T>
std::string upperCase(const T& arg) {
    std::string str = arg;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

template <typename T>
std::string compress(const T& arg) {
    std::string str;
    for (int i = 0; i < arg.size(); ++i) {
        if (arg[i] != ' ') {
            str += arg[i];
        }
    }
    return str;
}

template <typename T1, typename T, typename ...Types>
void print_with_separator(const T1& separator, const T& firstArg, const Types&... args) {
    std::cout << firstArg;
    if (sizeof...(args) > 0) {
        std::cout << separator;
    }
    print_with_separator(separator, args...);
}

template <typename T, typename ...Types>
void print_upper(const T& separator, const Types&... args) {
    print_with_separator(separator, upperCase(static_cast<std::string>(args))...);
}

template <typename... Types>
void print_compressed(const Types&... args) {
    print_with_separator("", compress(static_cast<std::string>(args))...);
}

int main() {
    print_with_separator(", ", "apple", "banana", "cherry");
    print_upper(", ", "hello", "world");
    print_compressed("  this   is    compressed  ");
}
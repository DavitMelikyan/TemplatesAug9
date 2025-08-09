#include <iostream>

void print_reverse() { }

template <typename T, typename... Types>
void print_reverse(const T& firstArg, const Types&... args) {
    print_reverse(args...);
    std::cout << firstArg << " ";
}

int main() {
    print_reverse('a', 10, 8.5, 4.75f, "Hello");
    std::cout << std::endl;
    print_reverse('a');
    std::cout << std::endl;
}
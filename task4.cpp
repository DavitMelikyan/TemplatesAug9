#include <iostream>
#include <string>
#include <vector>

void unpack(std::vector<std::string>& arglist) { }

template <typename T, typename ...Types>
void unpack(std::vector<std::string>& arglist, const T& firstArg, const Types&... args) {
    arglist.push_back(std::to_string(firstArg));
    unpack(arglist, args...);
}

template <typename... Types>
void unpack(std::vector<std::string>& arglist, const std::string& firstArg,  const Types&... args) {
    arglist.push_back(firstArg);
    unpack(arglist, args...);
}

template <typename... Types>
void unpack(std::vector<std::string>& arglist, const char* firstArg, const Types&... args) {
    arglist.push_back(std::string(firstArg));
    unpack(arglist, args...);
}

template <typename... Types>
void unpack(std::vector<std::string>& arglist, char firstArg, const Types&... args) {
    arglist.push_back(std::string(1,firstArg));
    unpack(arglist, args...);
}

template <typename ...Types>
std::string format(const std::string& fmt, const Types&... args) {
    std::string str;
    std::vector<std::string> arglist;
    unpack(arglist, args...);
    int k = 0;
    for (int i = 0; i < fmt.size(); ++i) {
        if (i < fmt.size() && fmt[i] == '{' && fmt[i + 1] == '}') {
            str += arglist[k++];
            ++i;
            continue;
        } 
        str += fmt[i];
    }
    return str;
}

int main() {
    std::cout << format("Hello, {}! You have {} messages.", "Alice", 3) << std::endl;
}
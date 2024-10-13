// auto-type.cpp by Bill Weinman [bw.org]
// updated 2022-05-25
#include <format>
#include <iostream>
#include <typeinfo>

using std::format;
using std::cout;

int main() {
    std::string s {"This is a string"};
    auto x = s;
    cout << format("x is {}\n", x);
    cout << format("type of x is {}\n", typeid(x).name());
}

// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <format>
#include <iostream>

using std::format;
using std::cout;

void func() {
    cout << "this is func()\n";
}

int main() {
    cout << "this is main()\n";
    func();
}

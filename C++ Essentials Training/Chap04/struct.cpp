// struct.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
#include <iostream>


using std::cout;

struct S {
    int i {};
    double d {};
    const char * s {};
};

int main() {
    S s1 { 3, 47.9, "string one" };
    cout << s1.i;
}

#include <iostream>
using namespace std;

// pass by value
// a copy is created of the variables
// actual variables are never swapped
void SwapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// pass by address
// copy is not created of variables
// actual variables values are swapped
void SwapByAddress(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// pass by Reference
// copy is not created of variables
// actual variables values are swapped
void SwapByReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    cout << "a: " << a << " " << "b: " << b << endl;
    SwapByValue(a, b);
    cout << "a: " << a << " " << "b: " << b << endl;

    int c = 15, d = 20;
    cout << "c: " << c << " " << "d: " << d << endl;
    SwapByAddress(&c, &d);
    cout << "c: " << c << " " << "d: " << d << endl;

    int e = 25, f = 30;
    cout << "e: " << e << " " << "f: " << f << endl;
    SwapByReference(e, f);
    cout << "e: " << e << " " << "f: " << f << endl;

    return 0;
}
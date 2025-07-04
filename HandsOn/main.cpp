#include <iostream>
using namespace std;

void Swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    cout << "a: " << a << " " << "b: " << b << endl;
    Swap(a, b);
    cout << "a: " << a << " " << "b: " << b << endl;
    return 0;
}
#include <iostream>
using namespace std;

// syntax of function template
template <class T>
T sum(T x, T y){
    T ans = x + y;
    cout << "sum of x & y = " << ans;
}


int main () {
    sum(2,3);
    cout << endl;
    sum(2.2,3.2);
    cout << endl;
    sum(2.21,3.27);
}
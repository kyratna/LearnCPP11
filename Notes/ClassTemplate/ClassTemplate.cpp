#include <iostream>
using namespace std;

// syntax for class template
template <class T>
class Largest{
    private:
        T x, y;
    public:
        Largest(T x, T y){
            if (x > y)
                cout << "x is larger with value = " << x << endl;
            else if (y > x)
                cout << "y is larger with value = " << y << endl;
            else
                cout << "not sure which one is larger" << endl;
        }
};

int main () {
    Largest <float> obj1(2.1,2.2); // works with <float>
    Largest obj2(2.1,2.2); // works without defining <float>
    Largest obj3(1,2);
    Largest obj4(2,2);
}
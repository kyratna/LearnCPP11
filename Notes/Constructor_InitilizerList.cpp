#include <iostream>
using namespace std;
class MyClass {
private:
    int member1;
    double member2;
public:
    // this is initializer list used to initialize value dusring constructor processing.
    MyClass(int value1, double value2, int value3) : member1(value1) {

    }
    void MyClassOutput() {
        cout << "Member 1: " << member1 << endl;
        cout << "Member 2: " << member2 << endl;
    }
};

// driver code
int main()
{

    // creating and initializing the object
    MyClass obj1(10, 11.5, 12);

    obj1.MyClassOutput();

    return 0;
}
#include <iostream>
using namespace std;
// Dynamic Memory management library
#include <memory>

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }
};

int main()
{
    // Shared Pointer Declarations:
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << "P1 Pointer : " << P1->area() << endl; // This'll print 50.
    cout << "P1 Usecount : " << P1.use_count() << endl; // usecount = 1.

    shared_ptr<Rectangle> P2 = std::make_shared<Rectangle>(10,6);
    cout << "P2 Pointer : " << P2->area() << endl; // This'll print 60.
    cout << "P2 Usecount : " << P2.use_count() << endl; // usecount = 1.

    shared_ptr<Rectangle> P3(P1);
    cout << "P3 Pointer : " << P3->area() << endl; // This'll print 50.
    cout << "P1 Usecount : " << P1.use_count() << endl; // usecount = 2.
    cout << "P3 Usecount : " << P3.use_count() << endl; // usecount = 2.

    shared_ptr<Rectangle> P4 = P2;
    cout << "P4 Pointer : " << P4->area() << endl; // This'll print 60.
    cout << "P1 Usecount : " << P1.use_count() << endl; // usecount = 2.
    cout << "P2 Usecount : " << P2.use_count() << endl; // usecount = 2.
    cout << "P4 Usecount : " << P4.use_count() << endl; // usecount = 2.

    //Member function :: Reset() // Resets the shared pointers:
    cout << "P1 Reset." << endl;
    P1.reset();
    // cout << "P1 Pointer : " << P1->area() << endl; // Error, P1 is reset previously.
    cout << "P3 Pointer : " << P3->area() << endl; // This'll print 50.
    cout << "P1 Usecount : " << P1.use_count() << endl; // usecount = 0. Reset previously.
    cout << "P3 Usecount : " << P3.use_count() << endl; // usecount = 1.

    //member function :: Get() // Gets the raw pointer to the object smart pointer is pointing to.
    shared_ptr<int> P5 = make_shared<int>(25);
    cout << "P5 Value : " << *P5 << endl; // 25
    cout << "P5 Usecount : " << P5.use_count() << endl; // 1
    cout << "P5 Get function : " << P5.get() << endl; // same as of P6
    cout << "P5 Address : " << &P5 << endl; // different from P6

    shared_ptr<int> P6 = P5;
    cout << "P6 Value : " << *P6 << endl; // 25
    cout << "P5 Usecount : " << P5.use_count() << endl; // 2
    cout << "P6 Usecount : " << P6.use_count() << endl; // 2
    cout << "P6 Get function : " << P6.get() << endl; // same as of P5
    cout << "P6 Address : " << &P6 << endl; // different from P5

    shared_ptr<int> &P7 = P5; // P7 is reference to P5
    // alternative syntax : shared_ptr<int> &P7(P5);
    cout << "P7 Value : " << *P7 << endl; // 25
    cout << "P5 Usecount : " << P5.use_count() << endl; // 2, reference do not add use count
    cout << "P7 address : " << &P7 << endl; // same as of P5

    int* ptr1 = P5.get();
    cout << "value at address stored in ptr : " << *ptr1 << endl;
    int* ptr2 = P5.get();
    cout << "value at address stored in ptr : " << *ptr2 << endl;

    cout << "End";
    return 0;
}

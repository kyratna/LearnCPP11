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
    // Unique Pointer Declarations
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << "P1 Pointer : " << P1->area() << endl; // This'll print 50.

    unique_ptr<Rectangle> P2 = make_unique<Rectangle>(10, 6);
    cout << "P2 Pointer : " << P2->area() << endl; // This'll print 60.

    unique_ptr<Rectangle> P3;
    P3 = make_unique<Rectangle>(10, 7);
    cout << "P3 Pointer : " << P3->area() << endl; // This'll print 70.
    
    unique_ptr<Rectangle> P4; // unsigned declaration of unique ptr.
    // P4 = new Rectangle(10, 8); // '=' operand not allowed.
    // P4(new Rectangle(10, 8)); // such call is not allowed.
    // unique_ptr<Rectangle> P4(P1); // This is not allowed, it is a deleted function, can not be de-referenced.

    // Move unique pointers.
    P4 = move(P1); // P4 is declared earlier.
    cout << "P4 unique ptr : " << P4->area() << endl; // This'll print 50.

    // unique_ptr<Rectangle> P5 = move(P1); // moving 'P1' again which is previously moved, is not allowed.

    unique_ptr<Rectangle> P6 = move(P2);
    cout << "P6 unique ptr : " << P6->area() << endl; // This'll print 60.

    cout << "End";
    return 0;
}

// C++ program to demonstrate the working of unique_ptr
// Here we are showing the unique_pointer is pointing to P1.
// But, then we remove P1 and assign P2 so the pointer now
// points to P2.

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
    // Smart Pointer
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    // unique_ptr<Rectangle> P2 = make_unique<Rectangle>(10, 5);
    // cout << "P1 unique ptr : " << P1->area() << endl; // This'll print 50
    // cout << P2->area() << endl; // This'll print 50

    // unique_ptr<Rectangle> P3(P1); // This is not allowed, it is a deleted function, can not be de-referenced.
    
    // unique_ptr<Rectangle> P4;
    // P4 = make_unique<Rectangle>(10, 10);
    // cout << P4->area() << endl; // This'll print 100
    
    unique_ptr<Rectangle> P5 = move(P1);
    cout << "P5 unique ptr : " << P5->area() << endl; // This'll print 50
    cout << "P1 again : " << P1->area() << endl; // This'll print 50
    cout << "End";
    // P2 = move(P1);

    // // This'll print 50
    // cout << P2->area() << endl;

    // // cout<<P1->area()<<endl;
    // return 0;
}

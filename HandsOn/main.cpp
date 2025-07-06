#include <iostream>
using namespace std;


int main() {
    int x = 10;
    int *ptr = &x;
    cout << x << " " << *ptr << endl;
    *ptr = 20;
    cout << x << " " << *ptr << endl;

    // #######################################################//

    // y is a const int
    // y is read only type, writing it is compile time error
    const int y = 10;
    // ptr2 is a pointer to an integer (which is non const)
    // ptr2 do not qualify to store address of const int y
    // int *ptr2 = &y; // error
    // *ptr2 = 20; // error

    // #######################################################//

    // z is a const int
    // z is read only type, writing it is compile time error
    const int z = 10;
    // ptr3 is a pointer to a const int
    // ptr3 qualifies to keep address of const int z
    const int *ptr3 = &z;
    // ptr3 can not be used to modify the const int z
    // *ptr3 = 20; // error

    // #######################################################//

    const int t = 10;
    // const ptr4 pointing to const int
    const int *const ptr4 = &t;
    // ptr4 = &y; // error, 2nd const, ptr4 is a constant pointer, can’t be reassigned
    // *ptr4 = 20; // error, 1st const, the pointee is const int, can’t be modified

    return 0;
}
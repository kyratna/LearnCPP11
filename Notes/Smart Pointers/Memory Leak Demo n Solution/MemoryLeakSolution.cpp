#include <iostream>
using namespace std;

// This is unique pointer implementation.
// RAII - Resource Acquisition Is Initialization.
// We will follow this concept to resolve the issue of memory leak with normal pointers.

class wrapper {
    private:
        int* mem;

    public:
        // constructor initializing the mem with dynmic allocated memory address.
        wrapper(int* a) : mem(a) {
            cout << "Inside Constructor\n";
        }
        // destructor taking care of cleanup of dynamic memory allocated.
        ~wrapper() {
            cout << "Inside Destructor\n";
            delete mem;
        }

};

int main() {
    wrapper obj(new int(10)); // constructor is called as soon as class object is created.
                              // destructor is called as soon as scope of above created object is over.

    return 0;
}
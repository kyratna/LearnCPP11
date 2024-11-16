#include <iostream>
using namespace std;

// RAII - Resource Acquisition Is Initialization
// we will follow this concept to resolve the issue of memory leak

int func() {
    for(int i = 0; i < 100000; i++) {
        cout << "Hey\n";
        int* a = new int(10); // dynamic memory allocation on heap.
    }
}

int main() {
    func(); //repeatingly calling dynamic memory allocation consuming the memory as program flow move furthur.
    
    
    return 0;
}
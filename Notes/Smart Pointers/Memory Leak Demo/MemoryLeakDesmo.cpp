#include <iostream>
using namespace std;

// RAII - Resource Acquisition Is Initialization
// we will follow this concept to resolve the issue of memory leak

int func() {
    for(int i = 0; i < 100000; i++) {
        cout << "Hey\n";
        int* a = new int(10); // dynamic memory allocation which is on heap.
    }
}

int main() {
    func(); // calling func which is using dynamic memory allocation
            // consuming the memory as program control move furthur with each iteration.
    
    
    return 0;
}
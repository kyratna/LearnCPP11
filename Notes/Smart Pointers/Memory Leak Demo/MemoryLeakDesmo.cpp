#include <iostream>
using namespace std;

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
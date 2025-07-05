#include <iostream>
using namespace std;

void PrintUsingPointers(int* x) {
    cout << *x << endl;
}

void PrintUsingPointersWithChecks(int* x) {
    if(x != nullptr) { // always check to ensure x is not receiving nullptr otherwise gives segmentation fault
        cout << *x << endl;
    }
}

// here you are not requried to check null ptr.
// since reference has to be initialized always.
void PrintUsingReference(int& x) {
    cout << x << endl;
}

int main() {
    int a = 5;
    int b;
    PrintUsingPointers(&a); // 5
    PrintUsingPointers(&b); // 0
    // PrintUsingPointers(nullptr); // segmentation fault (solution - add check for null ptr)
    PrintUsingPointersWithChecks(&a); // 5
    PrintUsingPointersWithChecks(&b); // 0
    PrintUsingPointersWithChecks(nullptr); // no print

    PrintUsingReference(a);
    PrintUsingReference(b);
    // PrintUsingReference(nullptr); // this is actually an error
    return 0;
}
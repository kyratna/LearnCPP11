#include <iostream>
using namespace std;

// This is unique pointer implementation.
// RAII - Resource Acquisition Is Initialization.
// We will follow this concept to resolve the issue of memory leak with normal pointers.

template <typename T>
class uniqueptr {
    private:
        int* res;

    public:
        // default constructor
        uniqueptr(T* a = nullptr) : res(a) {
            cout << "Inside constructor\n";
        }

        // deleting the copy constructor
        uniqueptr(const uniqueptr<T>& ptr) = delete;

        // deleting the operator = (copy assignment)
        uniqueptr& operator= (const uniqueptr<T>& ptr) = delete;

        // move constructor (tranfer the ownership)
        uniqueptr(uniqueptr<T>&& ptr) noexcept {
            res = ptr.res; // tranfer ownership
            ptr.res = nullptr; // nullifies the internal pointer of ptr, ensuring that ptr no longer owns the resource.
        }

        // move assignment operator (= move())
        uniqueptr& operator= (uniqueptr<T>&& ptr) noexcept {
            // avoid self - assignment
            if(this != &ptr) {
                // if this.res is holding anything, delete that to avoid memory leak.
                if(res) {
                    delete res;
                }
                res = ptr.res; // tranfer the ownership
                ptr.res = nullptr; // nullifies the internal pointer of ptr, ensuring that ptr no longer owns the resource.
            }
            return *this;
        }

        //overloading -> operator
        T* operator->() {
            return res;
        }

        // overloading de-reference operator
        T& operator*() {
            return *res;
        }

        // get - gets you raw pointer to the memory pointer is pointing to.
        T* get() {
            return res;
        }

        // reset - reset the ownership and sets to new passed memory location.
        void reset(T* newres = nullptr) {
            if(res) {
                delete res;
            }
            res = newres;
        }

        ~uniqueptr() {
            if(res) {
                delete res;
                res = nullptr;
            }
        }
};

int main() {
    uniqueptr<int> ptr1(new int(10));
    // uniqueptr<int> ptr2(ptr2); // copy constructor. copy of ownership is not allowed in unique pointer. compilation error.
    // uniqueptr<int> ptr3 = ptr1; // copy constructor. copy of ownership is not allowed in unique pointer. compilation error.
    uniqueptr<int> ptr4(new int(20));
    // ptr4 = ptr1; // assignment operator. copy of ownership is not allowed in unique pointer. compilation error.
    uniqueptr<int> ptr5 = move(ptr1); // move is allowed. transfer of ownership.
    ptr4 = move(ptr1); // move is allowed. transfer of ownership.
    // ptr4 -> func(); // arrow operator is also valid.
    cout << *ptr1 << endl; // de-reference operator or * operator is also valid.
    ptr1.get(); // gets raw pointer to the memory it is pointing to. valid operation.
    ptr4.reset(new int(50)); // reset the ownership and sets to new passed memory location.

    return 0;
}
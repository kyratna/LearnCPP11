#include <iostream>
using namespace std;

// This is shared pointer implementation.
// RAII - Resource Acquisition Is Initialization.
// We will follow this concept to resolve the issue of memory leak with normal pointers.

template <typename T>
class sharedptr {
    private:
        int* res;
        int* refcount;

        // increment the counter whenever pointer is shared
        void incrementcounter() {
            if(refcount) {
                *(refcount)++;
            }
        }

        // decrement the counter whenever shared pointer is removed
        void decrementcounter() {
            // check if refcount is pointing to any memory
            if(refcount) {
                *(refcount)--; // decrement of counter
                // if refcount is 0, delete the whole pointer : res, refcount
                if(*(refcount) == 0) {
                    if(res) {
                        delete res;
                        delete refcount;
                        res = nullptr; // assign res to nullptr
                        refcount = nullptr; // assign refcount to nullptr
                    }
                }
            }
        }

    public:
        // default constructor or parameterized constructor
        sharedptr(T* a = nullptr) : res(a), refcount(new int(1)) {
            cout << "Inside constructor\n";
        }

        // copy constructor - copying ptr to other ptr
        sharedptr(const sharedptr<T>& ptr) : res(ptr.res) {
            refcount = ptr.refcount;
            incrementcounter(); // increase refcount since copy of shared ptr is created
        }

        //the operator = (copy assignment) ptr3 = ptr1
        sharedptr& operator= (const sharedptr<T>& ptr) {
            // avoiding the self assignment
            if(this != &ptr) {
                decrementcounter(); // decrease counter of ptr3 since it will now have ptr1 content.
                res = ptr.res; // copied the ownership
                refcount = ptr.refcount; // copied the refcount memory location
                incrementcounter(); // increase counter of ptr3 which is now ptr1
            }
            return *this; // return the reference back
        }

        // move constructor (tranfer the ownership) rvalue with const
        sharedptr(sharedptr<T>&& ptr) noexcept {
            res = ptr.res; // tranfer ownership
            refcount = ptr.refcount; // tranfer refcount
            ptr.res = nullptr; // nullifies the internal pointer of ptr, ensuring that ptr no longer owns the resource
            ptr.refcount = nullptr; // nullifies the internal refcount of ptr
        }

        // move assignment operator (= move()) : ptr3 = move(ptr1)
        sharedptr& operator= (sharedptr<T>&& ptr) noexcept {
            // avoid self - assignment move
            if(this != &ptr) {
                decrementcounter(); // decrease refcount of ptr3, it is going to loose its older resource
                res = ptr.res; // tranfer the ownership
                refcount = ptr.refcount; // tranfer the refcount
                ptr.res = nullptr; // nullifies the internal pointer of ptr, ensuring that ptr no longer owns the resource.
                ptr.refcount = nullptr; // nullifies the internal refcount of ptr
            }
            return *this; // return the reference back
        }

        //overloading -> operator
        T* operator->() {
            return res;
        }

        // overloading de-reference operator
        T& operator*() {
            return *res;
        }

        // get - gets you refcount of shared pointer
        T* get_count() {
            if(refcount) {
                return *refcount;
            }
            return -1;
        }

        // get - gets you raw pointer to the memory pointer is pointing to.
        T* get() {
            return ref;
        }

        // reset - reset the ownership and sets to new passed memory location.
        void reset(T* newres = nullptr) {
            decrementcounter(); // decrease the older refcount
            res = newres; // new res is assigned as part of reset
            refcount = new int(1); // new ref count initialized with 1
        }

        ~sharedptr() {
            decrementcounter(); // decrease the ref count
        }
};

int main() {
    sharedptr<int> ptr1;
    sharedptr<int> ptr2(new int (10));
    sharedptr<int> ptr3(ptr2);
    sharedptr<int> ptr4 = ptr2;
    sharedptr<int> ptr5(move(ptr2));
    ptr4 = move(ptr3);

    ptr1.reset();
    ptr1.reset(new int(15));

    cout << *ptr1 << endl;
    // ptr1 -> func();
}
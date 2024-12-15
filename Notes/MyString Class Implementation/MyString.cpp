#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    private:
        char* res;
        int len;
    public:
        // default constructor
        MyString() {
            res = nullptr;
            len = 0;
        }

        // parameterised constructor
        MyString(const char* str) {
            len = strlen(str);
            res = new char[len + 1];
            strcpy(res, str);
        }

        // copy constructor
        MyString (const MyString& str) {
            len = str.len;
            res = new char[len + 1];
            strcpy(res, str.res);
        }

        // copy assignment operator
        MyString operator= (const MyString& str) {
            if(this != &str) {
                delete[] res;
                len = str.len;
                res = new char[len + 1];
                strcpy(res, str.res);
            }
            return *this;
        }

        // move constructor
        MyString (MyString&& str) {
            if(this != &str) {
                delete[] res;
                len = str.len;
                res = str.res;
                str.res = nullptr;
                str.len = 0;
            }
        }

        // move assignment operator
        MyString operator=(MyString&& str) {
            if(this != &str) {
                delete[] res;
                len = str.len;
                res = str.res;
                str.res = nullptr;
                str.len = 0;
            }
            return *this;
        }

        // return the length data member value of MyString obj
        int length() {
            return len;
        }

        // display the res of MyString obj
        void display() {
            for(int i=0; i<len; i++) {
                cout << res[i];
            }
            cout << endl;
        }

        // destructor to free up resource
        ~MyString() {
            delete[] res;
        }
};

int main() {
    MyString s1; // default constructor
    cout << "s1: ";
    s1.display(); // nothing printed
    MyString s2 = "Hello"; // parameterised constructor
    cout << "s2: ";
    s2.display(); // Hello
    MyString s3 = s2; // copy constructor
    cout << "s2: ";
    s2.display();
    cout << "s3: ";
    s3.display();
    MyString s4(s3); // copy constructor
    cout << "s4: ";
    s4.display();
    MyString s5; // default constructor
    s5 = s2; // copy assignment operator
    cout << "s5: ";
    s5.display();
    MyString s6; // default constructor
    s6 = move(s2); // move constructor
    cout << "s6: ";
    s6.display();
    cout << "s2: ";
    s2.display();
    cout << "cutom string class implementation ended";
}
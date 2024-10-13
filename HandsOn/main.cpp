#include <iostream>
using namespace std;


class Animal {
        string name;
        int age;
    public:
        Animal();
        void getDetails();
        void setDetails();
};

Animal :: Animal() {
    name = "unknown";
    age = -1;
}

void Animal :: getDetails() {
    cout << "Name of Animal : " << name << endl;
    cout << "Age of Animal : " << age << endl;
}

void Animal :: setDetails() {
    cout << "Name of Animal : ";
    cin >> name;
    cout << endl;
    cout << "Age of Animal : ";
    cin >> age;
}


int main () {
    Animal anm1;
    anm1.getDetails();
    anm1.setDetails();
    anm1.getDetails();
}
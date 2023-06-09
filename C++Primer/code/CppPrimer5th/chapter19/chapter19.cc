#include "Sales_data.h"

#include <iostream>
using std::cout; using std::endl;

#include <typeinfo>

#include <string>
using std::string;

struct Base {
    virtual ~Base() { }
};

struct Derived : Base { };

enum class Animai {
    Panda,
    Lion,
    Fish
};

int main() {
	int arr[10];
	Derived d;
	Base *p = &d;
	
	cout << typeid(42).name() << ", "
	     << typeid(arr).name() << ", "
	     << typeid(Sales_data).name() << ", "
	     << typeid(std::string).name() << ", "
	     << typeid(p).name() << ", "
	     << typeid(*p).name() << endl;
        
    Animai animal = Animai::Fish;
    // cout << animal << endl;  // 不能直接输出
	
	return 0;
}

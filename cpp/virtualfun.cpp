#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f()\n"; }
};

class D1 : public Base {
	virtual void f() { cout << "D1::f()\n"; }
};

int main() {
	Base *pb = new Base();
	pb->f();
	pb = new D1();
	pb->f();
	return 0;
}


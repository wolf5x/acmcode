#include <iostream>
using namespace std;

class Base {
protected:
	int bb;
public:
	Base():bb(1){}

	void print(){
		cout << "p b" << endl;
		cout << this->bb << endl;
	}
};

class Derived:public Base { 
protected:
	int bb;
public:
	Derived():Base(),bb(2){};

	void print() {
		cout << "p d" << endl;
		cout << this->Base::bb << endl;
		cout << this->bb << endl;
	}
};

int main()
{
	Base B;
	Derived C;
	B.print();
	C.print();
	C.Base::print();
	return 0;
}

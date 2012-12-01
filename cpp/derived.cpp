#include <stdio.h>

class Base {
public:
};

class Derived: public Base {
	void add() { puts("Derived add"); }
};

void f(Base *p) {
	dynamic_cast<Derived*>(p)->add();
}

int main() {
	f(new Base());
	return 0;
}



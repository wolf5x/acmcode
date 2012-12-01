#include <iostream> 
#include <cstring>
using namespace std; 
class A{ 
public: 
	int va;
	A(){ va = 10; }
	void outa() { cout << "va = " << va << endl; }
}; 

class B:public A 
{ 
public: 
	int value[10]; 
	B(){ reset(); }
	void reset() { memset(value, 0x5c, sizeof(value)); }
	void outb() { cout << "vb = " << value << endl; }
}; 

int main(){ 
	A* pa = new A[1000];
	A* a = &pa[0];
	B* b = static_cast<B*>(a); 
	(pa+1)->outa();
	b->reset();
	(pa+1)->outa();
	return 0; 
}

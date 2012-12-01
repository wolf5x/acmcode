#include <stdio.h>

class A{
public:
	A(){ 
		printf("default construct %u\n", (unsigned int)this);
		ptr = new int[10];
		printf("ptr %u\n", (unsigned int)ptr);
	}

	A(const A& _x){
		printf("copy construct %u\n", (unsigned int)this);
		ptr = _x.ptr;
		printf("ptr %u\n", (unsigned int)ptr);
	}
/*
	A& operator=(const A& _x) { 
		printf("assign %u\n", (unsigned int)this);
		ptr = _x.ptr;
		printf("ptr %u\n", (unsigned int)ptr);
		return *this; 
	}
	*/

	~A() {
		printf("destruct %u\n", (unsigned int)this);
		delete[] ptr;
		puts("done");
	}

	int *ptr;
};

void mark() {
	static int cnt = 0;
	printf("cnt = %d\n", ++cnt);
}

int main() {
	mark();
	A x;
	mark();
/*
	A y(x);
	mark();

	A z();
	mark();

	x = y;
	mark();
*/
	{
		x = A();
		mark();
	}
	mark();

	return 0;
}


	
	

#include <cstdio>
using namespace std;

int main() {
	int a = 3<<11, b = 1<<11, c = 2<<11;
	printf("%d\n", 600);
	printf("%d ", a);
	printf("%d ", b);
	for(int i = 1; i <= 597; i++)printf("%d ", i);
	printf("%d ", c);
	return 0;
}


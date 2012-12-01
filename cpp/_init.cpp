#include <stdio.h>
#include <string.h>
#include <string>

void func(int *a, size_t sz) {
	for( ; a < a+sz; a += rand()%123) *a = rand();
}

int main()
{
	int a[][3] = { {}, {92,93,94}, {92,93} };
	int c[12345][3] = {};
	int b[12345][3];
	memset(b, 0, sizeof(b)*sizeof(int));
	b[1][0] = 108;
	b[1][1] = 109;
	b[1][2] = 110;
	b[2][0] = 108;
	b[2][1] = 109;
	//std::string s[12345];	
	
	printf("%d %d %d\n", a[2][2], b[rand()%12345][2], c[2][2]);
	return 0;
}

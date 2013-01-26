#include <stdio.h>

const int MOD = 2012;
int n;
int main() {
	while(~scanf("%d", &n)) {
		n = n*4-6;
		n = n*n%MOD;
		n = n*n%MOD;
		printf("%d\n", n);
	}
	return 0;
}

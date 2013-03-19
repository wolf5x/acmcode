#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int num[200010], add[200010], top;
int n;

int main() {
	while(~scanf("%d", &n)) {
		long long ss = 0;
		num[0] = add[0] = 0;
		top = 1;
		while(n-- > 0) {
			int t;
			scanf("%d", &t);
			if(t == 1) {
				int a, x;
				scanf("%d%d", &a, &x);
				ss += a*x;
				add[a-1] += x;
			} else if(t == 2) {
				int k;
				scanf("%d", &k);
				ss += k;
				num[top] = k, add[top] = 0;
				top++;
			} else if(t == 3) {
				top--;
				ss -= num[top]+add[top];
				if(top > 0) 
					add[top-1] += add[top];
			}
			printf("%.8lf\n", (double)ss/top);
		}
	}
	return 0;
}


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int s[100010], n;
int stk[100010], top;

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		int ans = 0;
		top = 0;
		for(int i = 0; i < n; i++) {
			while(top && stk[top-1]<s[i])
				top--;
			if(top) ans = max(ans, stk[top-1]^s[i]);
			stk[top++] = s[i];
		}
		top = 0;
		for(int i = n-1; i >= 0; i--) {
			while(top && stk[top-1]<s[i])
				top--;
			if(top) ans = max(ans, stk[top-1]^s[i]);
			stk[top++] = s[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}


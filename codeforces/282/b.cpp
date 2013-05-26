#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 200010;
int n;
int a[maxn], vis[maxn][2];
long long dp[maxn][2];
int stamp;

long long dodp(int x, int f) {
	if(x <= 0 || x > n) return 0;
	if(vis[x][f] == stamp) return -1;
	else if(vis[x][f]) return dp[x][f];
	vis[x][f] = stamp;
	long long &r = dp[x][f];
	long long tmp = dodp(x+a[x]*(f?1:-1), f^1);
	if(tmp == -1) r = -1;
	else r = a[x]+tmp;
	return r;
}

int main() {
	while(~scanf("%d", &n)) {
		memset(vis, 0, sizeof(vis));
		memset(dp, 0, sizeof(dp));
		stamp = 0;
		for(int i = 2; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n-1; i++) {
			stamp++;
			a[1] = i;
			vis[1][1] = 0;
			cout << dodp(1, 1) << "\n";
		}
	}
	return 0;
}


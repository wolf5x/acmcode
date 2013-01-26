#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int T, n, att, m, p, D;
int x[1010], y[1010], hp[1010];
int pa[1010], mx[1010];

int getpa(int p) {
	return pa[p] == p ? p : (pa[p] = getpa(pa[p]));
}

int main() {
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++) {
		scanf("%d%d%d%d%d", &n, &att, &m, &p, &D);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d", &x[i], &y[i], &hp[i]);
			pa[i] = i, mx[i] = hp[i];
			for(int j = 0; j < i; j++) {
				int dx = x[i]-x[j], dy = y[i]-y[j];
				if((long long)dx*dx+(long long)dy*dy < (long long)D*D) {
					int pi = getpa(i), pj = getpa(j);
					mx[pi] = max(mx[pi], mx[pj]);
					pa[pj] = pi;
				}
			}
		}
		double ans = 0.0;
		double pp = p*1.0/100;
		for(int i = 0; i < n; i++) if(pa[i] == i) {
			int u = (mx[i]+att-1)/att;
			if(p == 0) {
				ans += u;
			} else {
				long double tp = 1.0, ta = 0.0;
				for(int k = 0; k <= u-1; k++) {
					ta += (k+1)*tp;
					tp *= 1-pp;
				}
				ans += ta*pp + u*tp;
			}
		}
		ans *= m;
		printf("Case #%d: %.2lf\n", cas, ans);
	}
	return 0;
}


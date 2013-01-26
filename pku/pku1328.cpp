#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1010;

//x1, x0, id
pair<pair<double,double>, int> po[maxn];
int n, d, x[maxn], y[maxn], v[maxn];

int main() {
	int cas = 0;
	while(~scanf("%d%d", &n, &d) && (n||d)) {
		memset(v, 0, sizeof(v));
		bool ok = true;
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &x[i], &y[i]);
			if(y[i] > d) ok = false;
			double dx = sqrt((double)d*d-(double)y[i]*y[i]);
			po[i] = make_pair(make_pair(x[i]+dx, x[i]-dx), i);
		}
		sort(po, po+n);
		int ans = 0;
		if(!ok) ans = -1;
		else {
			double m = -1e38;
			for(int i = 0; i < n; i++) {
				if(!v[po[i].second]) {
					if(po[i].first.second > m) {
						ans++;
						m = po[i].first.first;
					}
					v[po[i].second] = 1;
				}
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}

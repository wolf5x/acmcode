#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b;
vector<int> e[100010];
bool v[100010];

double dfs(int u, int l) {
	v[u] = true;
	double res = 1.0/l;
	for(int i = 0; i < e[u].size(); i++) {
		if(!v[e[u][i]])
			res += dfs(e[u][i], l+1);
	}
	return res;
}

int main() {
	while(cin >> n) {
		for(int i = 0; i < n; i++)
			e[i].clear(), v[i] = false;
		for(int i = 0; i < n-1; i++) {
			cin >> a >> b;
			--a, --b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		double ans = dfs(0, 1);
		cout << setprecision(10) << ans << endl;
	}
	return 0;
}


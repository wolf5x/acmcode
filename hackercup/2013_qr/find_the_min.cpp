#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int T, n, k, a, b, c, r;
int m[200010];
map<int,int> cnt;
set<int> can;

int main() {
	cin >> T;
	for(int cas = 1; cas <= T; ++cas) {
		cin >> n >> k >> a >> b >> c >> r;
		--n;
		cnt.clear(), can.clear();
		m[0] = a;
		for(int i = 1; i < k; ++i) 
			m[i] = ((long long)b*m[i-1] + c)%r;
		for(int i = 0; i < k+1; ++i)
			can.insert(i);
		for(int i = 0; i < k; ++i)
			++cnt[m[i]], can.erase(m[i]);
		m[k] = *can.begin();
		can.erase(m[k]);
		++cnt[m[k]];
		for(int i = k+1; i < k*2+2; ++i) {
			if(--cnt[m[i-k-1]] == 0) 
				cnt.erase(m[i-k-1]), can.insert(m[i-k-1]);
			m[i] = *can.begin(), can.erase(m[i]), ++cnt[m[i]];
		}
		int ans;
		if(n < k*2+2) 
			ans = m[n];
		else
			ans = m[(n-k-1)%(k+1)+(k+1)];
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}


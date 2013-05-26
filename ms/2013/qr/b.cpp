#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++(i))
#define FOR(i,l,h) for(int i=(l);i<(h);++(i))
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--(i))

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

int T, K, M, N;

inline long long rec(long long x, long long y) {
	return x*(x-1)*y*(y-1)/4;
}

inline long long line(long long x, long long z) {
	return z*(z-1)*x/2;
}

int main() {
	cin >> T;
	FOR(cas, 1, T+1) {
		cin >> N >> M >> K;
		if(N>M) swap(N,M);
		long long ans = 0;
		if(N*N >= K) {
			long long x = sqrt(K), r= K-x*x;
			long long t = rec(x,x);
			if(r>=x) t+= line(x,x)+line(x+1,r-x);
			else t += line(x,r);
			ans = max(ans, t);
		}
		for(int i = 0; M-i>=2; i++) {
			long long l = K/(M-i), r = K%(M-i);
			if(l > N || l == N && r > 0) break;
			long long t = rec(M-i, l) + line(l, r);
			ans = max(ans, t);
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}


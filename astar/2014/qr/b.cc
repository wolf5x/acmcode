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

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn = 1001;
int M;
int N, T[maxn], S[maxn];
int dp[2][maxn];

inline int to(int x, int y) {
	return min(abs(x-y), 360-abs(x-y));
}

inline void checkmin(int &a, int b) {
	if (a == -1 || a > b)
		a = b;
}

int main() {
	cin >> M;
	REP(_, M) {
		cin >> N;
		REP(i, N)
			cin >> T[i+1] >> S[i+1];
		T[0] = S[0] = 0;
		N++;
		SET(dp, -1);
		dp[0][0] = 0;
		REP(i, N-1) {
			int (&now)[maxn] = dp[i%2], (&next)[maxn] = dp[(i+1)%2];
			SET(next, -1);
			REP(j, N) if (now[j] >= 0) {	
				checkmin(next[j], now[j] + to(S[i], S[i+1]));
				checkmin(next[i], now[j] + to(S[j], S[i+1]));
			}
		}
		int ans = -1; 
		REP(i, N) if (dp[(N-1)%2][i] >= 0) {
			checkmin(ans, dp[(N-1)%2][i] + to(S[N-1], S[i]));
		}
		ans += 10*(N-1) + 800*T[N-1];
		cout << ans << endl;
	}
	return 0;
}


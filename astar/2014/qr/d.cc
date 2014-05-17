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
typedef pair<int,int> PII;

int T, M, N, C[100][100];
int sum[100][100], dp[100][100];

inline int getsum(int r, int c1, int c2) {
	return sum[r][c2] - (c1>0 ? sum[r][c1-1] : 0);
}

int main() {
	cin >> T;
	FOR(_, 1, T+1) {
		cin >> M >> N;
		REP(i, M) REP(j, N)
			cin >> C[j][i];
		REP(i, N) REP(j, M) {
			sum[i][j] = C[i][j];
			if (j > 0)
				sum[i][j] += sum[i][j-1];
			dp[i][j] = -1<<30;
		}
		REP(i, M)
			dp[0][i] = sum[0][i];
		REP(i, N-1) REP(j, M) REP(k, M) {
			dp[i+1][k] = max(dp[i+1][k], dp[i][j] + getsum(i+1, min(j,k), max(j,k)));
		}
		cout << "Case #" << _ << ":" << endl
			<< dp[N-1][0] << endl;

	}
	return 0;
}


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

int T, N, M;
long long S;
int trie[3303030][2];
int sz;

inline int bit(long long x, int b) {
	return (x&(1LL<<b)) ? 1 : 0;
}

void insert(long long x) {
	int p = 0;
	FORD(i, 33, 0) {
		int c = bit(x, i);
		if (trie[p][c] == 0) {
			trie[p][c] = sz;
			trie[sz][0] = trie[sz][1] = 0;
			sz++;
		}
		p = trie[p][c];
	}
}

long long find(long long x) {
	int p = 0;
	long long y = 0;
	FORD(i, 33, 0) {
		int c = bit(x, i)^1;
		if (trie[p][c] == 0)
			c ^= 1;
		y |= ((long long)c)<<i;
		p = trie[p][c];
	}
	return y;
}

int main() {
	scanf("%d", &T);
	REP(_, T) {
		scanf("%d%d", &N, &M);
		trie[0][0] = trie[0][1] = 0;
		sz = 1;
		REP(i, N) {
			scanf("%I64d", &S);
			insert(S);
		}
		printf("Case #%d:\n", _+1);
		REP(i, M) {
			scanf("%I64d", &S);
			printf("%I64d\n", find(S));
		}
	}
	return 0;
}


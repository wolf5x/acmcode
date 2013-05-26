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

LL ten[20];

vector<LL> tbl;

bool check(LL x) {
    if(x<0) return false;
    int g[20], p = 0;
    do { g[p++] = x%10; x /= 10; }
    while(x);
    REP(i,p/2) if(g[i]!=g[p-1-i]) return false;
    return true;
}

void dfs(int p, LL x) {
    if(p < 0) {
        LL y = x*x;
        if(check(x) && check(y))  {
            tbl.push_back(x);
        }
        return;
    }
    REP(i,4) {
        LL y = x+(LL)i*ten[p];
        dfs(p-1, y);
    }
}

int main() {
    REP(i, 19) ten[i] = i==0?1:ten[i-1]*10;
    tbl.clear();
    dfs(8, 0);
    REP(i, tbl.size()) cout << tbl[i] << " " << tbl[i]*tbl[i] << endl;
	return 0;
}


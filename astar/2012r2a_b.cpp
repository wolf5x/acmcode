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
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define sq(x)  ((x)*(x))

const int maxn = 1010;
int N, K;
double x[maxn], y[maxn], z[maxn];
double e[maxn][maxn];
bool v[maxn];
double up;

void dfs(int u)
{
    v[u] = true;
    REP(i,N) if(!v[i]) if(e[u][i] <= up + 1e-8) v[i] = true, dfs(i);
}

bool check(double x){
    up = x;
    int cnt = 0;
    memset(v, 0, sizeof(v));
    REP(i,N) if(!v[i]) {
        cnt++, dfs(i);
    }
    return cnt >= K;
}

int main()
{
//    freopen("a.in", "r",stdin);
    while(~scanf("%d%d", &N, &K)){
        REP(i,N) scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
        REP(i,N) REP(j,N) e[i][j] = sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]);
        double lo = 0, hi = 4, mi, ans = -1;
        while(hi - lo >= 1e-8){
            mi = (hi+lo)*0.5;
            if(check(mi)) ans = lo, lo = mi;
            else hi = mi;
        }
        printf("%.6lf\n", ans);
    }
    return 0;
}

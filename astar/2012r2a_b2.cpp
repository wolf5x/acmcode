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
vector<pair<double, pair<int,int> > > e;
int pa[maxn];

int getpa(int p){ return pa[p]==p ? p : (pa[p]=getpa(pa[p])); }

int main()
{
    freopen("a.in", "r",stdin);
    while(~scanf("%d%d", &N, &K)){
        e.clear();
        REP(i,N) scanf("%lf%lf%lf", &x[i], &y[i], &z[i]), pa[i] = i;
        REP(i,N) REP(j,N) if(i<j) e.PB(MP(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]),MP(i,j)));
        sort(e.begin(), e.end());
        int left = N, x = 0;
        while(x < N && left >= K){
            int s = getpa(e[x].second.first), t = getpa(e[x].second.second);
            if(s != t){
                left--;
                pa[s] = t;
            }
            x++;
        }
        double ans;
        if(left < K) ans = e[x-1].first;
        else ans = 1;
        printf("%.6lf\n", ans);
    }
    return 0;
}

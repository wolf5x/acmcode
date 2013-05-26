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
#define ITTYPE(c) typeof((c).begin())

int T, n, w, l, r[10];
map<int, pair<int,int> > bound; // x0, y, x1
vector<pair<int, int> > cc;

vector<pair<int, int> > ans;

void solve()
{
    bound.clear();
    bound.insert(MP(0, MP(-1<<30, w));
    ans.assign(n,MP(-1,-1));
    REP(step, n){
        bool flag = false;
        FORIT(it, bound){
            
        }
    }
    
    
}

int main()
{
    scanf("%d", &T);
    FOR(cas, 1, T){
        scanf("%d%d%d", &n, &w, &l);
        REP(i, n) scanf("%d", &r[i]), cc.PB(MP(r[i], i));
        sort(cc.begin(), cc.end(), greater<pair<int,int> >());
        
        solve();
        
        printf("Case #%d:", cas);
        REP(i, n) printf(" %lf %lf", ans[i].first, ans[i].second); 
        puts("");
    }
    return 0;
}

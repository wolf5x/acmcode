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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn = 500010;

int pa[maxn], sz[maxn];
vector<int> e[maxn];
set<int> grp, tmp;
map<int,int> lft;

int getpa(int u)
{
    return u == pa[u] ? u : (pa[u] = getpa(pa[u]));
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        grp.clear();
        REP(i,n) pa[i] = i, sz[i] = 1, e[i].clear(), grp.insert(i);
        REP(i,m) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            e[a].push_back(b), e[b].push_back(a);
        }
        REP(i,n){
            sort(e[i].begin(), e[i].end());
            e[i].resize(unique(e[i].begin(), e[i].end()) - e[i].begin());
        }
        REP(i, n){
            lft.clear();
            REP(j, e[i].size())
                lft[getpa(e[i][j])]++;
            tmp = grp;
            FORIT(it, grp) if(tmp.find(*it) != tmp.end() && lft[*it] < sz[*it]){
                int p1 = getpa(i), p2 = *it;
                if(p1 != p2){
                    sz[p1] += sz[p2], pa[p2] = p1;
                    tmp.erase(p2);
                }
            }
            grp = tmp;
        }
        REP(i, n) e[i].clear();
        int tot = 0;
        REP(i, n){
            e[getpa(i)].push_back(i);
            if(getpa(i) == i) tot++;
        }
        printf("%d\n", tot);
        REP(i, n) if(e[i].size() > 0){
            sort(e[i].begin(), e[i].end());
            printf("%d", e[i].size());
            REP(j, e[i].size())
                printf(" %d", e[i][j]+1);
            puts("");
        }
    }
    return 0;
}

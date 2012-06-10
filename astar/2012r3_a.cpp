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

const int maxn = 150010;
const int maxk = 51;
const int maxm = maxn*maxk;

int N, M, K, D, L[maxn], X[maxn][maxk];
vector<int> coord[maxn];

long long dp[maxn][maxnk+1];
int startn, endn;

int hi[maxn], lo[maxn];

inline long long go(int i, int j)
{
    return D*abs(i-j);
}

long long solve()
{
    REP(i, N) {
        sort(coord[i].begin(), coord[i].end());
        if(coord[i].size() > 0){
            hi[i] = *coord[i].rbegin();
            lo[i] = *coord[i].begin();
        } else{
            hi[i] = lo[i] = -1;
        }
    }
    endn = startn;
    REP(step, N-1){
        if(coord[(startn+N-step-1)%N].size()>0){
            endn = (startn+N-step-1)%N;
            break;
        }
    }
    if(startn == endn) 
        return (long long)D*(hi[startn]-lo[startn])*2;
    if((startn+1)%N == endn){
        return 100;
    }
    
    REP(i, K+1) dp[startn][i] = 0;
    int now = startn, pre = now
    do{
        if(++now == N) now = 0;
        REP(i,K+1) dp[now][i] = dp[pre][i]+X[pre][i];
        int tmp[MAXK];
        FOR(i,1,K) {
            tmp[i] = 1LL<<60;
            FOR(j,1,K){
                if(hi[now] < 0) 
                    tmp[i] = min(tmp[i], dp[now][j]+go(j,i));
                else 
                    tmp[i] = min(tmp[i], 
                                 dp[now][j]+min(
                                                go(j,lo[now])+go(lo[now],hi[now])+go(hi[now],i), 
                                                go(j,hi[now])+go(hi[now],lo[now])+go(lo[now],i)
                                                ));
            }
            if(hi[now] < 0)
                tmp[i] = min(tmp[i], dp[now][0]+L[now]+go(i,1));
            else
                tmp[i] = min(tmp[i], dp[now][0]+L[now]+go(i,hi[now])+go(hi[now],1));
        }
        tmp[0] = dp[pre][0];
        FOR(j,1,K){
            if(hi[now] < 0)
                tmp[0] = min(tmp[0], L[now]+go(j,1));
            else 
                tmp[0] = min(tmp[0], L[now]+go(i, hi[now])+go(hi[now],1);
        }
    } while(now != endn);
}

int main()
{
    while(~scanf("%d%d%d%d", &N, &K, &D, &M)){
        REP(i,N) scanf("%d", &L[i]), coord[i].clear();
        REP(i,K) {
            REP(j,N) scanf("%d", &X[j][i+1]);
            X[j][0] = 0;
        }
        coord.resize(M);
        REP(i,M) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            coord[xx-1].PB(yy);
        }
        startn = coord[0].first;
        
        long long ans = solve();
        do_reverse();
        ans = min(ans, solve());
    }
    return 0;
}

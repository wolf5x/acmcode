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

const int maxn = 10010;
int T, N, D[maxn], L[maxn], tt[maxn];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("al.out","w", stdout);
    scanf("%d", &T);
    FOR(cas, 1, T){
        scanf("%d", &N);
        REP(i, N) scanf("%d%d", &D[i], &L[i]), tt[i] = 0;
        scanf("%d", &D[N]), L[N] = 0, tt[N] = 0;
        tt[0] = D[0];
        bool ans = false;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N && D[i]+tt[i] >= D[j]; j++)
                tt[j] = max(tt[j], min(D[j]-D[i], L[j]));
            if(D[i]+tt[i] >= D[N]){ 
                ans = true;
                break;
            }
        }
        printf("Case #%d: ", cas);
        puts(ans?"YES":"NO");
    }
    return 0;
}

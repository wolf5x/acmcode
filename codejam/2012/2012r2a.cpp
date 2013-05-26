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
int T, N, D[maxn], L[maxn];

map<int,int> hp;


int main()
{
//    freopen("A-small-attempt1.in", "r", stdin);
//    freopen("a.out","w", stdout);
    scanf("%d", &T);
    FOR(cas, 1, T){
        scanf("%d", &N);
        REP(i, N) scanf("%d%d", &D[i], &L[i]);
        scanf("%d", &D[N]), L[N] = 0;
        L[0] = D[0];
        
        hp.clear();
        hp.insert(MP(-D[N], D[N]));
        int tmp = D[N];
        
        bool ans = false;
        
        for(int p = N-1; p >= 0; p--){
            while( !hp.empty() && -(hp.begin()->first) >= D[p]){
                tmp = min(tmp, hp.begin()->second);
                hp.erase(hp.begin());
            }
            if(D[p]+L[p] >= tmp){
                hp.insert(MP(-(D[p]*2-tmp),D[p]));
                if(p == 0 && tmp-D[p] <= D[p]) ans = true;
            }
        }

        printf("Case #%d: ", cas);
        puts(ans?"YES":"NO");
    }
    return 0;
}

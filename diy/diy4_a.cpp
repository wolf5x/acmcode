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

int t, n, m;
char x[20][21];
int c[21][21];

int main()
{
    memset(c, 0 , sizeof(c));
    REP(i,21) REP(j, i+1) c[i][j] = j==0?1:c[i-1][j]+c[i-1][j-1];
    
    scanf("%d", &t);
    REP(cas, t){
        scanf("%d%d", &n, &m);        
        double ans = 0.0;
        REP(i, n) {
            scanf("%s", x[i]);
            int cnt = 0;
            REP(j, n) if(x[i][j] == '1') cnt++;
            int xx = 0;
            FOR(j, m, cnt) xx += c[cnt][j];
            ans += 0.5*(double)xx/(1<<cnt);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}

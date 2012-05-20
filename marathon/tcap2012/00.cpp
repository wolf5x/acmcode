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

#define REP(i,n) for(int int i=0;i<(n);++i)
#define FOR(i,l,h) for(int int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int maxlock = 200000000;
const int maxn= 2001;

int nc, nr, nmi, nmx;
long long c[maxn][10], r[maxn][maxn], mi[maxn], mx[maxn];
int st[maxn];
int lock;

public class TheUniverseUnravels{
public:
    vector <string> predictCoordinates(vector <string> coords, vector <string> ranks, vector <int> minDist, vector <int> maxDist)
    {
        nc = coords.size();
        nr = ranks.size();
        nmi = minDist.size();
        nmx = maxDist.size();
        istringstream is;
        REP(i, nc){
            is.str(coords[i]);
            st[i] = 0;
            REP(j, 10) {
                is >> c[i][j];
                st[i] |= (c[i][j]>=0) << j;
            }
        }
        REP(i, nr){
            is.str(ranks[i]);
            REP(j, nr) is >> r[i][j];
        }
        REP(i, nmi) mi[i] = minDist[i];
        REP(i, nmx) mx[i] = maxDist[i];
    }
    
    void testin()
    {
        scanf("%d", &nc);
        REP(i, nc) {
            st[i] = 0;
            REP(j, 10) {
                scanf("%lld", &c[i][j]);
                st[i] |= (c[i][j]>=0) << j;
            }
        }
        scanf("%d", &nr);
        REP(i, nr) REP(j, nr) scanf("%lld", &r[i][j]);
        scanf("%d", &nmi);
        REP(i, nmi) scanf("%lld", &mi[i]);
        scanf("%d", &nmx);
        REP(i, nmx) scanf("%lld", &mx[i]);
    }
    
    void solve()
    {
    }
};

int main()
{
    TheUniverseUnravels cls;
    cls.testin();
    return 0;
}

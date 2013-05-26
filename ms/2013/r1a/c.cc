/*
 * ms编程之美2013 初赛第一场C
 * RE
 */
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

const int maxn = 110;
const int maxm = 2010;

const double inf = 1e30;
const double eps = 1e-8;

int T;
int N, M, S, NN[4];
vector<int> xx[4];
double dd[maxn][maxn];
double ss[16][1<<4][1<<4][1<<4][1<<4];
struct Node {
    int u;
    int s1,s2,s3,s4;
    double t;
    void set(int _u, int _s1, int _s2, int _s3, int _s4, double _t) {
        u = _u, s1 = _s1, s2 = _s2, s3 = _s3, s4 = _s4, t = _t;
    }
}hp[1<<20];
int sz;

double popc[1<<4][1<<4];

int ty[maxn], no[maxn];
double ww[17][17];
int yy[17], oo[17], id[17], tot;

bool cmp(const Node &a, const Node &b) {
    return a.t > b.t;
}

void addnode(int type, int number, int oid) {
    ty[oid] = type;
    no[oid] = tot;
    yy[tot] = type;
    oo[tot] = number;
    id[tot] = oid;
    ++tot;
}

void floyd() {
    REP(k,N) if(ty[k]==0) 
        REP(i,N) if(i!=k) 
            REP(j,N) if(j!=k && j!=i)
                dd[i][j] = min(dd[i][j], dd[i][k]+dd[k][j]);
    REP(i,tot) REP(j,tot) {
        ww[i][j] = dd[id[i]][id[j]];
    }
/*
    REP(i, N) REP(j, N) cout << dd[i][j] << (j<N-1?" ":"\n");
    cout << "\n";
    REP(i, tot) REP(j, tot) cout << ww[i][j] << (j<tot-1?" ":"\n");
    cout << "\n";
    */
}

inline void pass(int u, int s1, int s2, int s3, int s4, double t) {
    int type = yy[u], number = oo[u];
    // no touch mofa
    if(type == 1) {
        if(t < ss[u][s1][s2][s3][s4]-eps) {
            hp[sz++].set(u, s1, s2, s3, s4, t);
            push_heap(hp, hp+sz, cmp);
        }
    }

    if(type == 1) s1 |= 1<<number;
    else if(type == 2) s2 |= 1<<number;
    else if(type == 3) s3 |= 1<<number;
    else if(type == 4) s4 |= 1<<number, t += 3.0;

    //cout << "pass " << u << " " << s1 << " " << s2 << " " << s3 << " " << s4 << " v" << t << endl;

    if(t < ss[u][s1][s2][s3][s4]-eps) {
        hp[sz++].set(u, s1, s2, s3, s4, t);
        push_heap(hp, hp+sz, cmp);
    }
}

/*
 *一旦所有魔法台都被关闭后，立刻通关
 *可以不触发mofatai
 */
double bfs(int st) {
    sz = 0;
    REP(i, tot) REP(j, 1<<NN[0]) REP(k, 1<<NN[1]) REP(l, 1<<NN[2]) REP(m, 1<<NN[3])
        ss[i][j][k][l][m] = inf;
    if(ty[st]) {
        int u = no[st], s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        double t = 0;
        pass(u, s1, s2, s3, s4, t);
    } else {
        REP(u, tot) if(dd[st][id[u]] < inf) {
            int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
            double t = dd[st][id[u]]/popc[s3][s4];
            pass(u, s1, s2, s3, s4, t);
        }
    }
    while(sz) {
        if(sz >= (1<<20)-10) while(true);
        Node &h = hp[0];
        int u = h.u, s1 = h.s1, s2 = h.s2, s3 = h.s3, s4 = h.s4;
        double t = h.t;
        pop_heap(hp, hp+sz--, cmp);
        //cout << u << " " << s1 << " " << s2 << " " << s3 << " " << s4 << endl << t << endl;
        if(t > ss[u][s1][s2][s3][s4]) continue;
        if(s1 == (1<<NN[0])-1) {
            if(s2 != (1<<NN[1])-1) continue;
            else return t;
        }
        REP(v, tot) if(u!=v && ww[u][v] < inf){
            int c1 = s1, c2 = s2, c3 = s3, c4 = s4;
            double ct = t + ww[u][v]/popc[s3][s4];
            pass(v, c1, c2, c3, c4, ct);
        }
    }
    return inf;
}

int main() {
    REP(i, 1<<4) REP(j, 1<<4)
        popc[i][j] = 30 + 5*(__builtin_popcount(i) + __builtin_popcount(j));
    cin >> T;
    FOR(cas, 1, T+1) {
        CLR(ty); CLR(no);
        cin >> N >> M;
        REP(i,N) REP(j,N) 
            dd[i][j] = i==j?0:inf;
        int u, v, w;
        REP(i, M) {
            cin >> u >> v >> w;
            --u, --v;
            dd[u][v] = min(dd[u][v], (double)w);
            dd[v][u] = min(dd[v][u], (double)w);
        }
        tot = 0;
        REP(i, 4) {
            cin >> NN[i];
            int xx;
            REP(j, NN[i]) {
                cin >> xx;
                --xx;
                addnode(i+1, j, xx);
            }
        }
        floyd();
        cin >> S;
        --S;
        double ans = bfs(S);
        printf("Case #%d: %.5lf\n", cas, ans);
    }
    return 0;
}


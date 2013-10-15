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
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int Ni = 2510;
const int MAX = 1<<26;
struct Edge{
    int u,v,c;
    int next;
}edge[20*Ni];
int n,m;
int edn;//边数
int p[Ni];//父亲
int d[Ni];
int sp,tp;//原点，汇点

void addedge(int u,int v,int c)
{
    edge[edn].u=u; edge[edn].v=v; edge[edn].c=c;
    edge[edn].next=p[u]; p[u]=edn++;

    edge[edn].u=v; edge[edn].v=u; edge[edn].c=0;
    edge[edn].next=p[v]; p[v]=edn++;
}
int bfs()
{
    queue <int> q;
    memset(d,-1,sizeof(d));
    d[sp]=0;
    q.push(sp);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=p[cur];i!=-1;i=edge[i].next)
        {
            int u=edge[i].v;
            if(d[u]==-1 && edge[i].c>0)
            {
                d[u]=d[cur]+1;
                q.push(u);
            }
        }
    }
    return d[tp] != -1;
}
int dfs(int a,int b)
{
    int r=0;
    if(a==tp)return b;
    for(int i=p[a];i!=-1 && r<b;i=edge[i].next)
    {
        int u=edge[i].v;
        if(edge[i].c>0 && d[u]==d[a]+1)
        {
            int x=min(edge[i].c,b-r);
            x=dfs(u,x);
            r+=x;
            edge[i].c-=x;
            edge[i^1].c+=x;
        }
    }
    if(!r)d[a]=-2;
    return r;
}

int dinic(int sp,int tp)
{
    int total=0,t;
    while(bfs())
    {
        while(t=dfs(sp,MAX))
            total+=t;
    }
    return total;
}

class FoxAndGo3 {
    int nn, mm;
    inline int enc(int r, int c) {
        return r*mm+c;
    }

    public:
        int maxEmptyCells(vector <string> bb) {
            edn = 0;
            memset(p, -1, sizeof(p));
            nn = bb.size(), mm = bb[0].size();
            int tot = nn*mm;
            sp = tot, tp = tot+1;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,-1,0,1};
            int ans = 0;
            for (int i = 0; i < nn; i++) {
                for (int j = 0; j < mm; j++) {
                    if (bb[i][j] == 'o') {
                        ans++;
                        addedge(enc(i,j), tp, 1);
                        for (int k = 0; k < 4; k++) {
                            int tr = i+dr[k], tc = j+dc[k];
                            if (tr >= 0 && tr < nn && tc >= 0 && tc < mm
                                    && bb[tr][tc] == '.') {
                                addedge(enc(tr,tc), enc(i,j), MAX);
                            }
                        }
                    } else if (bb[i][j] == '.') {
                        ans++;
                        addedge(sp, enc(i,j), 1);
                    }
                }
            }
            ans -= dinic(sp, tp);
            return ans;
        }


        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { string Arr0[] = {"o.o",
            ".o.",
            "o.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxEmptyCells(Arg0)); }
        void test_case_1() { string Arr0[] = {"...",
            ".o.",
            "..."}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxEmptyCells(Arg0)); }
        void test_case_2() { string Arr0[] = {"xxxxx",
            "xxoxx",
            "xo.ox",
            "xxoxx",
            "xxxxx"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxEmptyCells(Arg0)); }
        void test_case_3() { string Arr0[] = {".xox.",
            ".o.ox",
            "x.o.o",
            "ox.ox",
            ".ox.."}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, maxEmptyCells(Arg0)); }
        void test_case_4() { string Arr0[] = {"o.o.o",
            ".ox..",
            "oxxxo",
            "..x..",
            "o.o.o"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxEmptyCells(Arg0)); }
        void test_case_5() { string Arr0[] = {"...",
            "...",
            "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, maxEmptyCells(Arg0)); }

        // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndGo3 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

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
 
class GearsDiv1 {
    int n;
	int bb[55][55], mat[55], vis[55];
	public:
	int getmin(string color, vector <string> graph) {
	    n = color.size();
	    int ans = 1<<30;
	    ans = min(ans, check('R','G',color,graph));
	    ans = min(ans, check('G','B',color,graph));
	    ans = min(ans, check('R','B',color,graph));
        return ans;
	}

	int check(char x, char y, string c, vector<string> g) {
	    memset(bb, 0, sizeof(bb));
        for(int i = 0; i < g.size(); i++) if(c[i] == x) {
            for(int j = 0; j < g[0].length(); j++) if(c[j] == y) {
                if (g[i][j] == 'Y') {
                    bb[i][j] = 1;
                }
            }
        }
        int det = hungray();
        return det;
    }

    int hungray() {
        int ret = 0;
        memset(mat, -1, sizeof(mat));
        for(int i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))ret++;
        }
        return ret;
    }

    bool dfs(int u) {
        for(int i = 0; i < n; i++) {
            if (!vis[i] && bb[u][i]) {
                vis[i] = true;
                if (mat[i] == -1 || dfs(mat[i])) {
                    mat[i] = u;
                    return true;
                }
            }
        }
        return false;
    }



    // BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "RGB"; string Arr1[] = {"NYY","YNY","YYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "RGBR"; string Arr1[] = {"NNNN","NNNN","NNNN","NNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "RGBR"; string Arr1[] = {"NYNN","YNYN","NYNY","NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"; string Arr1[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
        "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
        "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
        "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
        "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
        "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
        "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
        "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
        "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
        "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
        "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
        "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
        "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
        "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
        "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
        "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
        "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
        "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
        "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
        "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
        "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
        "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
        "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
        "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
        "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
        "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
        "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
        "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
        "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
        "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getmin(Arg0, Arg1)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GearsDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

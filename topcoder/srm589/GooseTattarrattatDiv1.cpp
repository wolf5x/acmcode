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
 
class GooseTattarrattatDiv1 {
	public:
	int pa[127];

	int getpa(int p) {
	    return pa[p] == p ? p : (pa[p] = getpa(pa[p]));
    }

	int getmin(string S) {
        int cnt[127] = {};
        int mx[127] = {};
        int len = S.length();
        memset(pa, 0, sizeof(pa));
        for(int i = 0; i < len; i++)
            cnt[S[i]]++, pa[S[i]] = S[i];
        for(int i = 0; i < len; i++) {
            int x = getpa(S[i]), y = getpa(S[len-1-i]);
            if (x != y)
                pa[x] = y;
        }
        int ans = len;
        for(int i = 0; i < 127; i++) {
            int c = getpa(i);
            mx[c] = max(mx[c], cnt[i]);
        }
        for(int i = 0; i < 127; i++)
            ans -= mx[i];
        return ans;
    }


    // BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
    void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
    void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
    void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
    void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GooseTattarrattatDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

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

/*
 * Memory Limit is 64MB, so we can at most keep two 2500*2500 arrays.
 */
vector<vector<int> > eql, acl;
vector<vector<int> > eqr, acr;
string s;
int n, g;

class LittleElephantAndRGB {
    public:
    long long getNumber(vector <string> list, int minGreen) {
        s = std::accumulate(list.begin(), list.end(), s = "");
        n = s.length();
        g = minGreen;

        // Calculate ac from left to right and free the memory used by eq
        preload(s, eql, acl, true);
        eql.clear();
        // Calculate eq from right to left and avoid using ac
        reverse(s.begin(), s.end());
        preload(s, eqr, acr, false);
        reverse(eqr.begin(), eqr.end());

        long long ans = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j <= g; j++) {
                ans += (long long)acl[i][j]*eqr[i+1][g-j];
            }
        }
        return ans;
    }

    void preload(string &s, vector<vector<int> > &eq, vector<vector<int> > &ac, bool setac) {
        eq.assign(n, vector<int>(g+1, 0));
        if (setac) {
            ac.assign(n, vector<int>(g+1, 0));
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != 'G') {
                eq[i][0] = i+1;
                if (i > 0)
                    eq[i][0] -= eq[i-1][g];
            } else {
                for (int j = 1; j <= g; j++) {
                    if (i > 0)
                        eq[i][j] += eq[i-1][j-1];
                    if (j == 1)
                        eq[i][j]++;
                }
            }
            if (i > 0)
                eq[i][g] += eq[i-1][g];
            if (setac) {
                int ge = 0;
                for (int j = g; j >= 0; j--) {
                    ge += eq[i][j];
                    ac[i][j] = ge;
                    if (i > 0)
                        ac[i][j] +=ac[i-1][j];
                }
            }
        }
    }



    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"GRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 1LL; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"GG", "GG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 9LL; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"GRBGRBBRG"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 11LL; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"RRBRBBRRR", "R", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 12430LL; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LittleElephantAndRGB ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

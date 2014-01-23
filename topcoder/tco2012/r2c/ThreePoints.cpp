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

class ThreePoints {
    public:
    long long countColoring(int N, int xzero, int xmul, int xadd, int xmod, int yzero, int ymul, int yadd, int ymod) {
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 8; int Arg3 = 6; int Arg4 = 11; int Arg5 = 5; int Arg6 = 7; int Arg7 = 8; int Arg8 = 11; long long Arg9 = 8LL; verify_case(0, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 9; int Arg2 = 6; int Arg3 = 8; int Arg4 = 10; int Arg5 = 4; int Arg6 = 8; int Arg7 = 5; int Arg8 = 10; long long Arg9 = 2LL; verify_case(1, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 3; int Arg3 = 71; int Arg4 = 100; int Arg5 = 78; int Arg6 = 12; int Arg7 = 50; int Arg8 = 100; long long Arg9 = 263LL; verify_case(2, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 300000; int Arg1 = 99097861; int Arg2 = 102766912; int Arg3 = 95284952; int Arg4 = 123456789; int Arg5 = 443104491; int Arg6 = 971853214; int Arg7 = 569775557; int Arg8 = 987654321; long long Arg9 = 749410681185726LL; verify_case(3, Arg9, countColoring(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ThreePoints ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

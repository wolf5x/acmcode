#line 2 "AlienAndSetDiv1.cc"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
int dp[55][55][1<<10];
int msk;
int N, K;

inline void madd(int &a, int b) {
	if ((a += b) >= MOD)
		a -= MOD;
}

int getdp(int n0, int n1, int sta) {
	int &res = dp[n0][n1][sta];
	if (res >= 0) 
		return res;
	if (n0 == N && n1 == N)
		return res = 1;
	res = 0;
	int m1 = __builtin_popcount(sta), m0 = K-m1;
	if (n0 < N && (n0 >= n1 || n1-m1 >= n0+1))
		madd(res, getdp(n0+1, n1, (sta<<1)&msk));
	if (n1 < N && (n1 >= n0 || n0-m0 >= n1+1))
		madd(res, getdp(n0, n1+1, ((sta<<1)|1)&msk));
	return res;
}

class AlienAndSetDiv1
{ 
public: 
int getNumber(int _N, int _K) 
	{ 
		N = _N, K = --_K;
		msk = (1<<K)-1;
		memset(dp, -1, sizeof(dp));
		return getdp(0, 0, 0);
	} 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 20; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 14; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 7; int Arg2 = 40; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        AlienAndSetDiv1 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

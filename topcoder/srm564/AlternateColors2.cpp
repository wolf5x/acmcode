#line 2 "AlternateColors2.cpp"
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

#define REP(i,n) for(int i=0;i<(n);++i)

const int maxn = 100010;
long long s[maxn], t[maxn], u[maxn];
class AlternateColors2
{
    public:
    long long countWays(int n, int k)
    {
        REP(i, n+1) s[i] = t[i] = u[i] = -1;
        return gsk(n, k);
    }
    
    long long gs(int n, int k) {
        if(n < 0) return 0;
        else if(n == 0) return 1;
        long long &r = s[n];
        if(r >= 0) return r;
        r = 1;
        if(k != 2 && k != 3) r += gs(n-3, k-3);
        if(k != 2) r += 2LL*gt(n-2, k-2);
        if(k <= 0) r += 2+gu(n-2, k-2);
        return r;
    }
    
    long long gt(int n, int k) {
        if(n < 0) return 0;
        else if(n == 0) return 1;
        long long &r = t[n];
        if(r >= 0) return r;
        r = 1;
        if(k != 2) r += gt(n-2, k-2);
        if(k <= 0) r++;
        return r;
    }
    
    long long gu(int n, int k) {
        if(n < 0) return 0;
        else if(n == 0) return 1;
        long long &r = u[n];
        if(r >= 0) return r;
        r = 2;
        r += gu(n-2, k-2);
        return r;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 3LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; long long Arg2 = 9LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; long long Arg2 = 21LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 100000; long long Arg2 = 1666700000LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlternateColors2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE


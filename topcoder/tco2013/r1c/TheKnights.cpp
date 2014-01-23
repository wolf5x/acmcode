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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class TheKnights {
    public:
    double find(int n, int a, int b) {
		//cout << n << "," << a << "," << b << ": " << single(n, a, b) << " " << two(n, a, b) << " " << three(n, a, b) << endl;
		long double bas = (double)n*n;
		long double ans = 0.0;
		ans += single(n, a, b)*(bas-1)*2;
		ans -= two(n, a, b)*2;
		ans -= three(n, a, b);
		ans /= bas*(bas-1);
		return ans;
    }

	long double single(int n, int a, int b) {
		long double res = (long double)max(0,n-a)*max(0,n-b)*4;
		if(a != b) res *= 2;
		res += (long double)n*n;
		return res;
	}

	long double two(int n, int a, int b) {
		long double res = (long double)max(0, n-a)*max(0, n-b) * 4;
		if(a != b) res *= 2;
		return res;
	}

	long double three(int n, int a, int b) {
		if(a>b) swap(a,b);
		long double res = 0;
		if(a == b) {
			res += cover(n, a+1, b*2+1)*4;
			res += cover(n, a+b+1, a+b+1)*2;
			return res*2;
		} else {
			res += cover(n, b+1, b+1)*4;
			res += cover(n, a+1, b*2+1)*4;
			res += cover(n, b+1, a*2+1)*4;
			res += cover(n, b+1, a+b+1)*8;
			res += cover(n, a+b+1, a+b+1)*4;
			res += cover(n, a*2+1, b*2+1)*4;
			return res*2;
		}
	}

	long double cover(int n, int a, int b) {
		return (long double)max(0,n-a+1)*max(0,n-b+1);
	}

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; double Arg3 = 3.3333333333333335; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 47; int Arg1 = 7; int Arg2 = 74; double Arg3 = 2.0; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; double Arg3 = 4.888888888888889; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9999; int Arg1 = 999; int Arg2 = 99; double Arg3 = 16.25885103191273; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 6; double Arg3 = 7.636363636363637; verify_case(4, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheKnights ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

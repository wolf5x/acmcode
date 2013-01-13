#line 2 "DefectiveAddition.cpp"
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

const int mod = 1000000007;

inline void add(int &a, int b) {
	a += b;
	while(a >= mod) a-= mod;
}

class DefectiveAddition
{
	int a[55][33], b[33];
	int f[55][2][2]; //num[i], xor res, has free num?

    public:
    int count(vector <int> cards, int n)
    {
		int m = cards.size();
		REP(i, m) REP(j, 30) {
			a[i][j] = (cards[i]>>j)&1;
		}
		REP(i, 30) {
			b[i] = (n>>i)&1;
		}
		int ans = 0;
		for(int h = 29; h >= 0; h--) {
			memset(f, 0, sizeof(f));
			f[0][0][0] = 1;
			REP(i, m) REP(j, 2) REP(k, 2) if(f[i][j][k]){
				int rem = cards[i]&((1<<h)-1);
				if(a[i][h] == 0) {
					add(f[i+1][j][k], (long long)f[i][j][k]*(rem+1)%mod);
				} else {
					add(f[i+1][j^1][k], (long long)f[i][j][k]*(rem+1)%mod);
					if(k == 0) add(f[i+1][j][1],  f[i][j][k]);
					else add(f[i+1][j][k], (long long)f[i][j][k]*(1<<h)%mod);
				}
			}
			add(ans, f[m][b[h]][1]);
			int s = b[h];
			REP(i, m) s ^= a[i][h];
			if(s) break;
			if(h == 0) add(ans, 1);
		}

		return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 5, 7, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 240; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 1965600; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 949480669; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DefectiveAddition ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE


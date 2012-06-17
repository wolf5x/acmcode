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

class FavouriteDigits {
    public:
    int dp[18][10];
    long long bb[18];
    
    long long findNext(long long N, int digit1, int count1, int digit2, int count2) {
        bb[0] = 1;
        FOR(i,1,17) bb[i] = bb[i-1]*10;
        memset(dp,0,sizeof(dp));
        FORD(i,17,0) if(N>=bb[i]){
            dp[i][(N/bb[i])%10]++;
        }
        FORD(i,16,0) REP(j,10) dp[i][j] += dp[i+1][j];
        if(dp[0][digit1] >= count1 && dp[0][digit2] >= count2)
            return N;
        
        REP(i,16){
            REP(j,10){
                if(j<=(N/bb[i])%10) continue;
                long long res = solve(j, i, digit1, count1-dp[i+1][digit1], digit2, count2-dp[i+1][digit2]);
                if(res >= 0){
                    return N/bb[i+1]*bb[i+1]+(long long)j*bb[i]+res;
                }
            }
        }
        
        return -1;
    }
    
    long long solve(int f, int l, int d1, int c1, int d2, int c2)
    {
//        cout << f << " " << l << " " << d1 << " " << c1 << " " << d2 << " " << c2 << endl;
        if(f == d1) c1--;
        if(f == d2) c2--;
        c1 = max(c1, 0);
        c2 = max(c2, 0);
        if(c1+c2 > l) return -1;
        if(d1>d2) swap(d1,d2), swap(c1, c2);
        long long r = 0;
        REP(i,c1) r = r*10+d1;
        REP(i,c2) r = r*10+d2;
        return r;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 47LL; int Arg1 = 1; int Arg2 = 0; int Arg3 = 2; int Arg4 = 0; long long Arg5 = 47LL; verify_case(0, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 47LL; int Arg1 = 5; int Arg2 = 0; int Arg3 = 9; int Arg4 = 1; long long Arg5 = 49LL; verify_case(1, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 47LL; int Arg1 = 5; int Arg2 = 0; int Arg3 = 3; int Arg4 = 1; long long Arg5 = 53LL; verify_case(2, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 47LL; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; int Arg4 = 2; long long Arg5 = 200LL; verify_case(3, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 123456789012345LL; int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; long long Arg5 = 123456789012422LL; verify_case(4, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { long long Arg0 = 92LL; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 100LL; verify_case(5, Arg5, findNext(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FavouriteDigits ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

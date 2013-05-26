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
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(__typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int oo = 0x7f7f7f7f;
class TravellingPurchasingMan
{ 
public: 
    int w[50][50];

    int dp[16][1<<16];
    int a[16], b[16], c[16];

    vector<int> parse(const string &s) {
        istringstream iss(s);
        vector<int> r;
        int t;
        while(iss >> t) {
            r.push_back(t);
        }
        return r;
    }
	int maxStores(int N, vector <string> S, vector <string> R) 
	{ 
        int M = S.size(); 
        REP(i,M) {
            vector<int> x = parse(S[i]);
            a[i] = x[0], b[i] = x[1], c[i] = x[2];
        }
        SET(w,0x7f);
        REP(i,N) w[i][i] = 0;
        REP(i,R.size()) {
            vector<int> x = parse(R[i]);
            w[x[0]][x[1]] = w[x[1]][x[0]] = x[2];
        }
        
        REP(k, N) REP(i, N) if(i!=k) REP(j,N) if(j!=k && j!=i)
            if(w[i][k] < oo && w[k][j] < oo)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
		
        SET(dp, 0x7f);
        REP(i,M) if(w[N-1][i] <= b[i]) {
            dp[i][1<<i] = max(w[N-1][i],a[i])+c[i];
        }
        int up = 1<<M;
        REP(i, up) REP(j, M) {
            if(dp[j][i] <oo) {
                REP(k, M) if(w[j][k] < oo) if(!((1<<k)&i)) if(dp[j][i]+w[j][k]<=b[k]) {
                    dp[k][i|(1<<k)] = min(dp[k][i|(1<<k)], c[k]+max(dp[j][i]+w[j][k], a[k]));
                }
            }
        }

        int ans = 0;
        REP(i, up) REP(j, M) {
            if(dp[j][i] < oo) {
                ans = max(ans, __builtin_popcount(i));
            }
        }
        return ans;
	} 
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = {"0 1000 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main()
{
	TravellingPurchasingMan ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE 

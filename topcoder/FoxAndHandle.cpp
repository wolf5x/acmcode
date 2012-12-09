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

using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)


typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class FoxAndHandle {
    public:
    string lexSmallestName(string S) {
        int cnt[26] = {};
        REP(i, S.length()) cnt[S[i]-'a']++;
        REP(i, 26) cnt[i] /= 2;
        return solve(S, cnt);
    }
    
    string solve(string s, int *cnt) {
        REP(i, 26) if(cnt[i] > 0) {
            REP(j, s.length()) if(s[j] == i+'a') {
                if(check(s.substr(j), cnt)) {
                    cnt[i]--;
                    return string(1, i+'a') + solve(s.substr(j+1), cnt);
                }
            }
        }
        return "";
    }
    
    bool check(string s, int *cnt) {
        vector<int> left(cnt, cnt+26); 
        REP(i, s.length()) {
            left[s[i]-'a']--;
        }
        REP(i, 26) if(left[i] > 0) return false;
        return true;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "foxfox"; string Arg1 = "fox"; verify_case(0, Arg1, lexSmallestName(Arg0)); }
	void test_case_1() { string Arg0 = "ccieliel"; string Arg1 = "ceil"; verify_case(1, Arg1, lexSmallestName(Arg0)); }
	void test_case_2() { string Arg0 = "abaabbab"; string Arg1 = "aabb"; verify_case(2, Arg1, lexSmallestName(Arg0)); }
	void test_case_3() { string Arg0 = "bbbbaaaa"; string Arg1 = "bbaa"; verify_case(3, Arg1, lexSmallestName(Arg0)); }
	void test_case_4() { string Arg0 = "fedcbafedcba"; string Arg1 = "afedcb"; verify_case(4, Arg1, lexSmallestName(Arg0)); }
	void test_case_5() { string Arg0 = "nodevillivedon"; string Arg1 = "deilvon"; verify_case(5, Arg1, lexSmallestName(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndHandle ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

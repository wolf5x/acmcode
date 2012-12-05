#line 2 "ICPCBalloons.cpp"
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int oo = 1<<29;

class ICPCBalloons
{
    public:
    int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted)
    {
        int pn = maxAccepted.size();
        vector<int> mm, bb;
        REP(i, balloonSize.length()) {
            if(balloonSize[i] == 'M') 
                mm.push_back(balloonCount[i]);
            else 
                bb.push_back(balloonCount[i]);
        }
        sort(mm.rbegin(), mm.rend());
        sort(bb.rbegin(), bb.rend());
        sort(maxAccepted.rbegin(), maxAccepted.rend());
        int res = oo;
        for(int mask = (1<<pn)-1; mask >= 0; mask--) {
            vector<int> pm, pb;
            REP(i, pn) {
                if((1<<i)&mask)
                    pm.push_back(maxAccepted[i]);
                else
                    pb.push_back(maxAccepted[i]);
            }
            res = min(res, solve(mm, pm) + solve(bb, pb));
        }
        return res<oo ? res : -1;
    }
    
    int solve(vector<int> &ball, vector<int> &prob) {
        int paint = 0, left = 0;
        REP(i, prob.size()) {
            if(i < ball.size()) {
                if(prob[i] <= ball[i]) {
                    left += ball[i]-prob[i];
                } else {
                    paint += prob[i]-ball[i];
                }
            } else {
                paint += prob[i];
            }
        }
        for(int i = prob.size(); i < ball.size(); i++) {
            left += ball[i];
        }
        return paint>left ? oo : paint;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L"; int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M"; int Arr2[] = {10,20,30,40,50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,6,1,5,6,1,5,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MLMMLMMLM"; int Arr2[] = {7,7,4,4,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(2, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ML"; int Arr2[] = {50,51,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MMMLLLMMLLMLMLM"; int Arr2[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"; int Arr2[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 210; verify_case(5, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ICPCBalloons ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE


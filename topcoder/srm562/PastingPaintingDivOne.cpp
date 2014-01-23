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
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))



class PastingPaintingDivOne {
    public:
    vector<long long> countColors(vector <string> C, int T) {
        long long x[255] = {0};
        int cc[55][55], dd[55][55];
        memset(dd, -1, sizeof(dd));
        int m = C.size(), n = C[0].length();
        for(int i = m-1; i >= 0; i--) for(int j = n-1; j >= 0; j--) {
            if(C[i][j] != '.') 
                cc[i][j] = C[i][j], dd[i][j] = 0;
            else if(i < m-1 && j < n-1) 
                cc[i][j] = cc[i+1][j+1], dd[i][j] = dd[i+1][j+1]+1;
//            cout << i << " " << j <<  " " << (char)cc[i][j] << " " << dd[i][j] << endl;
        }
        REP(i,m) REP(j,1) if(dd[i][j] >= 0){
            x[cc[i][j]] += max(0, T-dd[i][j]);
        }
        REP(i,1) FOR(j,1,n-1) if(dd[i][j] >= 0){
            x[cc[i][j]] += max(0, T-dd[i][j]);
        }
        FOR(i,1,m-1) FOR(j,1,n-1) if(dd[i][j] >= 0){
            x[cc[i][j]] += (T > dd[i][j]);
        }
        vector<long long> ret;
        ret.push_back(x['R']);
        ret.push_back(x['G']);
        ret.push_back(x['B']);
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {
"..G",
"R..",
"BG."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long Arr2[] = {3, 4, 3 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, countColors(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
"R...",
"....",
"....",
"...R"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long Arr2[] = {4, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, countColors(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"RGB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; long Arr2[] = {100000, 100000, 100000 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, countColors(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long Arr2[] = {0, 0, 0 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, countColors(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {
"RB.",
".G."
}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long Arr2[] = {100, 1, 100 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, countColors(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {
"..........G..........",
".........G.G.........",
"........G...G........",
".......G.....G.......",
"......G..B.B..G......",
".....G...B.B...G.....",
"....G...........G....",
"...G...R.....R...G...",
"..G.....RRRRRR....G..",
".G..........RR.....G.",
"GGGGGGGGGGGGGGGGGGGGG"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long Arr2[] = {2000000018, 17000000048, 2000000005 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, countColors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PastingPaintingDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE

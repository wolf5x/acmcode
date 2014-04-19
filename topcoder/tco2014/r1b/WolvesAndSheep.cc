#line 2 "WolvesAndSheep.cc"
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
 
#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(auto i=(c).rbegin(); i!=(c).rend(); ++i)
 
#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))
 
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
typedef long long i64;
 
int r, c;
int w[16][16], s[16][16];
class WolvesAndSheep {
public:
	int getmin(vector <string> f) {
		r = f.size();
		c = f[0].length();
		CLR(w); CLR(s);
		REP(i, r) REP(j, c) {
			w[i][j] = getcnt(w, 0, 0, i-1, j) + getcnt(w, 0, 0, i, j-1) - getcnt(w, 0, 0, i-1, j-1) + (f[i][j] == 'W');
			s[i][j] = getcnt(s, 0, 0, i-1, j) + getcnt(s, 0, 0, i, j-1) - getcnt(s, 0, 0, i-1, j-1) + (f[i][j] == 'S');
		}
		int ans = (r-1) + (c-1);
		for (int i = (1<<(r-1))-1; i >= 0; i--) {
			ans = min(ans, solve(i) + __builtin_popcount(i));
		}
		return ans;
	}

	int solve(int rmsk) {
		int ret = 0, p1 = 0;
		while(p1 < c) {
			int p2 = p1;
			while(p2 < c && check(rmsk, p1, p2))
				p2++;
			if (p2 == p1)
				return 1<<30;
			ret++;
			p1 = p2;
		}
		return ret-1;
	}

	bool check(int rmsk, int c1, int c2) {
		int r1 = 0;
		while(r1 < r) {
			int r2 = r1+1;
			while(r2 < r && !(rmsk&(1<<(r2-1))))
				r2++;
			if(getcnt(w, r1, c1, r2-1, c2) > 0 
					&& getcnt(s, r1, c1, r2-1, c2) > 0)
				return false;
			r1 = r2;
		}
		return true;
	}

	int getcnt(int a[16][16], int r1, int c1, int r2, int c2) {
		if (r1<0 || c1<0 || r1>r2 || c1>c2) return 0;
		int ret = a[r2][c2];
		if (r1) ret -= a[r1-1][c2];
		if (c1) ret -= a[r2][c1-1];
		if (r1 && c1) ret += a[r1-1][c1-1];
		return ret;
	}
 
	

};
 


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

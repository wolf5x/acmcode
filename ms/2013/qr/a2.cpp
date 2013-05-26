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

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

map<string,string> E;
int T, N, M;
string u, v, line;

string& get_final(string &s, int n) {
	if(n == 0 || E.find(s) == E.end())
		return s;
	return get_final(E[s], n-1);
}

int main() {
	cin >> T;
	FOR(cas, 1, T+1) {
		cin >> N >> M;
		E.clear();
		REP(i, M) {
			cin >> u >> v;
			E[u] = v;
		}
		getline(cin, line);
		getline(cin, line);
		istringstream is(line);
		cout << "Case #" << cas << ":";
		while(is >> u) {
			cout << " " << get_final(u, N-1);
		}
		cout << "" << endl;
	}
	return 0;
}


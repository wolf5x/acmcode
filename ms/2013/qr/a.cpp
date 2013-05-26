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
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--(i))

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

int E[210];
map<string,int> id;
string rev[210];
int T, N, M;
string u, v, line;

string get_final(int id, int n) {
	if(n == 0) return rev[id];
	return E[id]>=0 ? get_final(E[id], n-1) : rev[id];
}

int main() {
	cin >> T;
	FOR(cas, 1, T+1) {
		cin >> N >> M;
		SET(E, -1);
		id.clear();
		REP(i, M) {
			cin >> u >> v;
			if(id.find(u) == id.end())
				id.insert(make_pair(u, id.size()+1)), rev[id[u]] = u;
			if(id.find(v) == id.end())
				id.insert(make_pair(v, id.size()+1)), rev[id[v]] = v;
			E[id[u]] = id[v];
		}
		getline(cin, line);
		getline(cin, line);
		istringstream is(line);
		cout << "Case #" << cas << ":";
		while(is >> u) {
			cout << " " << (id.find(u)==id.end() ? u : get_final(id[u], N-1));
		}
		cout << "\n";
	}
	return 0;
}


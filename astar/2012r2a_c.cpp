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
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define sq(x)  ((x)*(x))

const int maxn = 1010;
int n;
long long x[maxn], y[maxn];
long long k[2], a[2], b[2];

long long solve(int p, int q)
{
    vector<long long> det;
    det.clear();
    long long ret = 0;
    REP(i,n){
        ret += a[p]*x[i] + b[p]*y[i];
        det.PB((a[p]-a[q])*x[i] + (b[p]-b[q])*y[i]);
    }
    sort(det.begin(), det.end());
    REP(i,n-k[p]) ret -= det[i];
    return ret;
}

int main()
{
    freopen("b.in", "r",stdin);
    while(cin >> n){
        REP(i,n) cin >> x[i] >> y[i];
        REP(i,2) cin >> k[i] >> a[i] >> b[i];
        long long ans = 0;
        cout << max(solve(0,1), solve(1,0)) << endl;
    }
    return 0;
}

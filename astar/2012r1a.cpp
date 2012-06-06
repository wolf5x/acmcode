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

int n, m, u, d;
int main()
{
    cin >> n >> m;
    long long ans = 1<<30;
    while(m--){
        cin >> u >> d;
        int x = max((int)(n*(double)d/u-1000), 0), y = 3000;
        long long r = 1<<30;
        REP(step, y){
            long long s = (long long)u*x-(long long)d*(n-x);
            if(s > 0){
                r = min(r, s);
            }
            x++;
        }
        ans = min(ans, r);
    }
    cout << ans << endl;
    return 0;
}

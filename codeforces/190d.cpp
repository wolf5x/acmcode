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
#define FORRIT(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

map<int,int> cnt;
multimap<int,int> hp;

int n, k, a[400010];

int main()
{
    while(cin >> n >> k){
        long long ans = 0;
        REP(i, n) cin >> a[i];
        cnt.clear(), hp.clear();
        int p1 = 0, p2 = -1;
        while(p2 < n){
            while(!hp.empty() && hp.begin()->first != -cnt[hp.begin()->second]){
                int tmp = hp.begin()->second;
                hp.erase(hp.begin());
                hp.insert(make_pair(-cnt[tmp], tmp));
            }
            if(p2 >= p1 && !hp.empty() && -hp.begin()->first >= k){
                ans += n-p2;
                cnt[a[p1]] --;
                p1++;
            } else{
                if(++p2 == n) break;
                cnt[a[p2]] ++;
                hp.insert(make_pair(-cnt[a[p2]], a[p2]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

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

const int maxn = 100001;
int D[maxn], C[maxn];
int N, T;

set<pair<int,int> > hp; // Dnow, num;
vector<pair<int,int> > qq; // C, D;

inline long long get_sum(long long hi, long long lo)
{
    return (hi+lo)*(hi-lo+1)/2;
}

int main()
{
    scanf("%d", &T);
    FOR(CAS, 1, T){
        scanf("%d", &N);
        hp.clear(), qq.clear();
        int d, c;
        REP(i,N){
            scanf("%d%d", &d, &c);
            if(c>0 && d>0)
                qq.PB(MP(C,D));
        }
        qq.PB(MP(0,0));
        sort(qq.begin(), qq.end());
        long long ans = 0;
        for(int p = qq.size()-1; p > 0; ){
            int Cnow = qq[qq.size()-1].first;
            int q = p-1;
            while(q > 0 && qq[q].first == Cnow) q--;
            FOR(i,q+1,p){
                hp.insert(MP(-qq[i].second,1));
            }
            int l = Cnow-qq[q].first;
            long long tl = 0, tc = (*hp.begin()).second;
            long long tr = 0;
            while(tl < l && hp.size()>1){

                pair<int,int> now = *hp.begin();
                hp.erase(hp.begin());
                pair<int,int> next = *hp.begin();
                if(tl + tc*((-now.first)-(-next.first)) >= l){
                    long long dl = tl-l;
                    long long xx = dl/tc, yy = dl%tc;
                    //(tc-yy) ge xx, yy ge (xx+1)
                    tl += (tc-yy)*xx;
                    tr += (tc-yy)*get_sum(-now.first, -now.first-xx+1);
                    hp.insert(MP(-(-now.first-xx), tc-yy));
                    tl += yy*(xx+1);
                    tr += yy*get_sum(-now.first, -now.first-xx);
                    hp.insert(MP(-(-now.first-xx-1), yy));
                    
                } else{
                    tl += tc*((-now.first)-(-next.first));
                    tr += tc*get_sum(-now.first, -next.first+1);
                    tc += next.second;
                    hp.erase(hp.begin());
                    hp.insert(MP(next.first, tc));
                    continue;
                }
                
            }
            if(hp.size()== 1)
                hp.insert(MP(0,1));
                
            ans += tr;
            p = q;
        }
        cout << ans << endl;
    }
    
    return 0;
}

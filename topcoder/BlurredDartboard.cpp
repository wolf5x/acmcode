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

class BlurredDartboard {
    public:
    int minThrows(vector <int> points, int P) {
        vector<int> no;
        int x[60] = {0};
        int n = points.size();
        int mx = 0;
        REP(i,n) {
            mx = max(mx, points[i] );
            if(points[i] > 0)
                x[points[i]] = 1;
        }
        int zero = 0;
        long long zs = 0;
        REP(i, n){
            if(!x[i+1]) zs += i+1, zero++, no.PB(i+1);
        }
        sort(no.begin(), no.end());
        if(zero == 0) return (P+mx-1)/mx;
        else {
            long long ret = 0;
            long long rr = P;
            int tmp = max((long long)mx*zero ,zs);
            ret += (rr/tmp)*zero;
            rr %= tmp;
            if(zs < rr) ret += (rr+mx-1)/mx;
            else{
                long long t1 = 0, t2 = 0;
                int ts = 0;
                for(t1 = 0; ts < rr; ts += no[t1++]);
                if(mx>0) t2 = (rr+mx-1)/mx;
                else t2 = 1LL<<60;
                ret += min(t1, t2);
            }
            return (int)ret;
        }
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

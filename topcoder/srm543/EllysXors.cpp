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

#define REP(i,n) for(int i=0;i<(n);++i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class EllysXors {
    public:
    long long getXor(long long L, long long R) {
        return solve(L-1)^solve(R);
    }

    long long solve(long long x)
    {
        long long r = 0;
        REP(i, 60){
            long long tmp = (i==0) ? (x+1)/2 : (((1LL<<i)-1)&x)+1;
            if((i == 0 || (x&(1LL<<i))) && tmp%2) r |= 1LL<<i;
        }
        return r;
    }
    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

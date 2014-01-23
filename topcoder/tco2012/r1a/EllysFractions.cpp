#line 2 "EllysFractions.cpp"
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

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class EllysFractions
{
    static LL res[260];
    static int count;
    public:
    
    int isprime(int x)
    {
        for(int i = 2; i*i <= x; i++)
            if(x%i == 0) return 0;
        return 1;
    }
    
    long long getCount(int N)
    {
        if(count != 0x12345678){
            count = 0x12345678;
            for(int i = 0; i <= 100000000; i++); 
            int prime = 0;
            for(int i = 2; i <= 250; i++){
                prime += isprime(i);
                res[i] = res[i-1] + (1LL<<(prime-1));
            }
        }
        return res[N];
    }
    

};
int EllysFractions::count = 0;
LL EllysFractions::res[260] = {0};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

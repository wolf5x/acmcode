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


typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class KleofasTail {
    public:
    set<unsigned long long> res;
    long long countGoodSequences(long long K, long long A, long long B) {
        A = max(A, K);
        if(K==0) return B-A+1;
//        cout << solve(K,B) << " " << solve(K,A-1) << endl;
        return solve(K,B)-solve(K,A-1);
    }
    
    unsigned long long solve(unsigned long long k, unsigned long long a)
    {
        unsigned long long ok = k;
        unsigned long long ret = 0;
        int x = 0;
        unsigned long long b = 1, c = 0;
        while((a&(~c))>=k){
            if((a&(~c))>k){
                ret += 1LL<<x;
            } else{
                ret += (a^k)+1;
            }
            k <<= 1;
            c = (c<<1)|1;
            x++;
        }
        if(ok%2==0) ret += solve(ok+1,a);
        return ret;
    }
    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor

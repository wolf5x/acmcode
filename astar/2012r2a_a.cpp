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

const int maxn=32,maxm=100010;

long long a[maxm];
int gaus(int n,const int m=32)
{
    int i,j,k;
    j=0;
    for (i=m-1;i>=0;i--)
    {
         for (k=j;k<n;k++)
             if ( (a[k]>>i)&1 )
                 break;
         if (k<n)
         {
             swap(a[k],a[j]);
             for (k=0;k<n;k++)
                 if (k!=j && ( (a[k]>>i)&1 ))
                      a[k]^=a[j];
             j++;
         }
    }
    return j;
}
int n;
int main()
{
    while(cin >> n){
         int i,j,k;
         for (i=0;i<n;i++)
             cin >> a[i];
             
         k=gaus(n);
         
         vector<long long> ans;
         for(j=0; j < 2; j++){
            long long ask = (1LL<<k)-1-j;
            if(ask <= 0){
                ans.PB(0); 
                continue;
            }
             long long res=0;
             for (i=0;i<k;i++)
                 if ((ask>>i)&1)
                      res^=a[k-1-i];
             ans.PB(res);
         }
         cout << ans[0] << " " <<  ans[1] << endl; 
    }
    return 0;
} 

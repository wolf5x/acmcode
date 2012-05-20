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

/*
0 0 10
0 1 5
*/

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    cout << setprecision(10);
    double x[2], y[2], r[2];
    REP(i,2) cin >> x[i] >> y[i] >> r[i];
    if(r[0] < r[1]) swap(x[0], x[1]), swap(y[0], y[1]), swap(r[0], r[1]);
    double d = dist(x[0], y[0], x[1], y[1]);
    if(d >= r[0] + r[1]) {
        cout << (d-r[0]-r[1])*0.5 << endl;
    } else if(r[0] >= d+r[1]){
        cout << (r[0]-d-r[1])*0.5 << endl;
    } else{
        cout << "0" << endl;
    }
    return 0;
}

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
#define FORRIT(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); ++i)

#define CLR(x) memset((x),0,sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int MINC = 1;
const int MAXC = 10;
const int MING = 2;
const int MAXG = 100;
const int MINS = 20;
const int MAXS = 100;
const int MINI = 2;
const int MAXI = 10;
const int MINP = 1;
const int MAXP = 10;

const double CONFLICT_P = 0;

VI preferences, cakes;

int C, G, I, S;

VI mask; // shape to cover
int nh, nw;
vector<pair<int,int> >  piece[MAXG][MAXC][MAXS/2][MAXS/2]; // each guest's: <value, choice>
int cake[MAXC][MAXS][MAXS][MAXI];
int pref[MAXG][MAXI];
int joy[MAXG][MAXC][MAXS][MAXS];

int try_each_low;
int try_total;

char mskb[4][4], mskv[4][4];
char dr[]={0,-1,0,1}, dc[]={-1,0,1,0};

void dfs(int i, int j)
{
    if(i<0 || i>3 || j<0 || j>3)return;
    if(mskv[i][j])return;
    if(!mskb[i][j])return;
    mskv[i][j] = 1;
    REP(k,4) dfs(i+dr[k],j+dc[k]);
}

void gen_mask()
{
    mask.clear();
    REP(step,1<<16){
        REP(i,4)REP(j,4)mskb[i][j] = (step&(1<<(i*4+j)))!=0;
        int c = 0;
        REP(i,4)REP(j,4) c+=mskb[i][j];
        if(c != 4) continue;
        if(b[0][0]+b[0][1]+b[1][0] == 0) continue;
        CLR(mskv);
        c = 0;
        REP(row,4) REP(col,4) if(!v[row][col])
            c++, dfs(row,col);
        if(c>1) continue;
        mask.PB(step);
    }
}

void init()
{
    nh = S/2, nw = s/2;
    int s = 0;
    REP(i,G)REP(j,I) pref[i][j] = preferences[s++];
    s = 0;
    REP(i,C)REP(row,S)REP(col,S)REP(j,I) cake[i][row][col][j] = cakes[s++];
    
    REP(i,G)REP(j,C)REP(row,S)REP(col,S){
        joy[i][j][row][col] = 0;
        REP(k,I) joy[i][j][row][col] += cake[j][row][col][k]*pref[i][k];
    }
    
    gen_mask();
    REP(i,G)REP(j,C)REP(rn,S/2)REP(cn,S/2) {
        piece[i][j][row][col].clear();
        int row = rn<<1, col = cn<<1;
        REP(k,mask.size()){
            
        }
    }
    
    
}


class Cakes
{
    vector <int> split(int _C, int _G, int _I, int _S, vector <int> _preferences, vector <int> _cakes){
        C = _C, G = _G, I = _I, S = _S, preferences = _preferences, cakes = _cakes;
    }

};

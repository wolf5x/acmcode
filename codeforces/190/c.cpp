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

struct NODE{
    int ch[2];
    int x;
    void clear(){x = 0;}
}tr[1000000];
int sz;
char buf[1000000];
istringstream is;

bool dfs(NODE &p)
{
    string w;
    REP(c, 2){
        if( c == 1 && (&p) == (&tr[0])) break;
        if(is >> w){
            p.x = c+1;
            p.ch[c] = sz;
            tr[sz++].clear();
            if(w[0] == 'p'){
                if(!dfs(tr[p.ch[c]])) return false;
            }
        } else{
            return false;
        }
    }
    if(&p == &tr[0] && is >> w){
        return false;
    } else{
        return true;
    }
}

void show(int x)
{
    if(tr[x].x == 0){
        cout << "int";
        return ;
    } else{
        cout << "pair<";
        show(tr[x].ch[0]);
        cout << ",";
        show(tr[x].ch[1]);
        cout << ">";
    }
}

int main()
{
    int n;
    while(cin >> n){
        is.clear();
        sz = 0;
        tr[sz++].clear();
        fgets(buf, sizeof(buf), stdin);
        fgets(buf, sizeof(buf), stdin);
        is.str(string(buf));
        if(dfs(tr[0]))
            show(tr[0].ch[0]), cout << "\n";
        else
            cout << "Error occurred\n";
    }
    return 0;
}

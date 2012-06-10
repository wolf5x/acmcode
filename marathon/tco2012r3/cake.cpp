//#define DEBUG
#define LOCAL
//#define PRINT
#define USE_TESTER

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <stdarg.h>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())

typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

typedef vector<int> vint;
typedef pair<int,int> ipair;
typedef pair<int64,int64> i64pair;
typedef vector<ipair> vipair;


// orz ACRush begin

#ifdef DEBUG
#define ASSERT(_Expression) (void)((!!(_Expression)||(__assert((#_Expression),__LINE__),0)));
void __assert(const char *_Message,const unsigned _Line)
{
    fprintf(stderr, "ASSERTION FAILED\n");
    fprintf(stderr, "Message = %s\n",_Message);
    fprintf(stderr, "Line = %u\n",_Line);
    exit(0);
}
#define DPRINT(format,args...) fprintf(stderr, format, ##args)
#endif

uint64 rdtsc()
{
#ifdef _MSC_VER
    __asm { rdtsc }
#else
    uint64 time;
    __asm__ volatile ("rdtsc" : "=A" (time));
    return time;
#endif
}

#ifdef LOCAL
    #define TIMES_PER_SEC (3.19e9)
#else
    #define TIMES_PER_SEC (3.589e9)
#endif

uint64 starttime_acrush=0;
const double timelimit = TIMES_PER_SEC*9.8;
void starttime()
{
    starttime_acrush=rdtsc();
}
uint64 gettime()
{
    return rdtsc()-starttime_acrush;
}

#ifdef DEBUG
class Timer
{
public:
    static uint64 timeUsed[1000];
    int id;
    uint64 startTime;
    Timer(int id=0) { this->id=id; startTime=rdtsc(); }
    ~Timer() { timeUsed[id]+=(rdtsc()-startTime); }
    
    static void show()
    {
#ifdef PRINT
        for (int i=0;i<1000;i++) if (timeUsed[i]>0)
        {
            char str[100];
            sprintf(str,"%.6lf",timeUsed[i]/TIMES_PER_SEC);
            string s=str;
            if (LENGTH(s)<15) s=" "+s;
            DPRINT("%4d %s\n",i,s.c_str());
        }
#endif
    }
};
uint64 Timer::timeUsed[1000]={0};

class Counter
{
public:
    static int cnt[1000];
    Counter(int id=0) { cnt[id]++; }
    ~Counter() { }
    static void show()
    {
#ifdef PRINT
        for (int i=0;i<1000;i++) if (cnt[i]>0) DPRINT("Counter %d %d\n",i,cnt[i]);
#endif
    }
};
int Counter::cnt[1000]={0};
#endif

// orz ACRush end

const int INF_INT = 0x7fffffff;
const ipair NULL_PAIR = MP(-1,-1);
const int DR[] = {0,0,-1,1};
const int DC[] = {-1,1,0,0};

const double R_TEMPERATURE_CAKE = 0.9;
const double R_TEMPERATURE_ALL = 0.9;
const double START_TEMPERATURE_CAKE = 1000;
const double START_TEMPERATURE_ALL = 1000;

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

vint preferences, cakes;

int C, G, I, S;

int cake[MAXC][MAXS][MAXS][MAXI];
int pref[MAXG][MAXI];
int joy[MAXG][MAXC][MAXS][MAXS];

int try_each_low;
int try_total;
bool time_up;
int max_joy;
int min_joy;

double temperature_all;
double temperature_cake[MAXC];

//sa config
ipair last_start_cell[MAXG];
ipair now_start_cell[MAXG];

//runtime
int now_score_guest[MAXG];

int now_value_cell[MAXG][MAXS][MAXS];

//heap
int guest_of_cake[MAXC][MAXG];
int tot_guest_of_cake[MAXC];
ipair cell_of_guest[MAXG][MAXS*MAXS];
int tot_cell_of_guest[MAXG];
ipair bound_of_guest[MAXG][MAXS*MAXS];
int tot_bound_of_guest[MAXG];
//heap end
int now_cake_state[MAXC][MAXS][MAXS];
int cake_preflag[MAXC][MAXS][MAXS];

int last_score_cake[MAXC];
int now_score_cake[MAXC];

//sa ans
int best_score_cake[MAXC];
int best_cake_state[MAXC][MAXS][MAXS];

int cake_round[MAXC];

//sa config
int last_guest_of_cake[MAXC][MAXG];
int last_tot_guest_of_cake[MAXC];
int last_in_cake[MAXG];
int now_guest_of_cake[MAXC][MAXG];
int now_tot_guest_of_cake[MAXC];
int now_in_cake[MAXG];

int now_score_all;
int last_score_all;


int best_score_all;
int best_state_all[MAXC][MAXS][MAXS];

int round_count;

uint64 atime_cake_round = 0.5*TIMES_PER_SEC;
uint64 atime_all_round = 1*TIMES_PER_SEC;

double myrand(double l, double r)
{
    return (r-l)*(double)rand()/32768;
}

bool has_time_cake()
{
    return (timelimit-gettime() > atime_cake_round);
}

bool has_time_all()
{
    return (timelimit-gettime() > atime_all_round);
}

int get_value(int gg, int cc, int row, int col)
{
    // TODO
    return joy[gg][cc][row][col];
}

void check_best_cake(int cc)
{
    if(now_score_cake[cc] > best_score_cake[cc]){
        best_score_cake[cc] = now_score_cake[cc];
        #ifdef DEBUG
        int sum[MAXG] = {0};
        #endif
        REP(i,S) REP(j,S){
            best_cake_state[cc][i][j] = now_cake_state[cc][i][j];
            #ifdef DEBUG
            int gg = now_cake_state[cc][i][j];
            sum[gg] += joy[gg][cc][i][j];
            #endif
        }
        #ifdef DEBUG
        int tb = INF_INT;
        REP(i, now_tot_guest_of_cake[cc]){
            tb = min(tb, sum[now_guest_of_cake[cc][i]]);
        }
        DPRINT("cake %d : %d (..%d)\n", cc, now_score_cake[cc], tb);
        #endif
    }
}

void save_now_to_last_cake(int cc)
{
    last_score_cake[cc] = now_score_cake[cc];
    REP(i, tot_guest_of_cake[cc]){
        int gg = guest_of_cake[cc][i];
        last_start_cell[gg] = now_start_cell[gg];
    }
}

inline bool is_in_cake(int r, int c)
{
    return r>=0 && r<S && c>=0 && c<S;
}

inline void set_preflag(int cid, ipair cell, int gid)
{
    cake_preflag[cid][cell.first][cell.second] |= 1<<gid;
}

inline void remove_preflag(int cid, ipair cell, int gid)
{
    cake_preflag[cid][cell.first][cell.second] &= ~(1<<gid);
}

inline bool check_preflag(int cc, ipair cell, int gg)
{
    return (cake_preflag[cc][cell.first][cell.second]&(1<<gg))!=0;
}

inline bool check_connect_cell(int cc, ipair cell, int gid)
{
    REP(k,4){
        int tr = cell.first + DR[k], tc = cell.second + DC[k];
        if(is_in_cake(tr,tc) && now_cake_state[cc][tr][tc] == gid)
            return true;
    }
    return false;
}

bool mycmp_guest_of_cake(int g1, int g2)
{
    return now_score_guest[g1] > now_score_guest[g2];
}

int cmp_gg;
bool mycmp_cell_of_guest(ipair c1, ipair c2)
{
    return now_value_cell[cmp_gg][c1.first][c1.second] < now_value_cell[cmp_gg][c2.first][c2.second];
}


double get_next_temperature_cake(int cc)
{
    double ret = temperature_cake[cc];
    temperature_cake[cc] *= R_TEMPERATURE_CAKE;
    return ret;
}

double myexp_cake(int det, double temp)
{
    return exp(det/temp);
}

void init_cake(int cc)
{
    best_score_cake[cc] = 0;
    REP(row, S) REP(col, S){
        best_cake_state[cc][row][col] = -1;
    }
    
    last_score_cake[cc] = now_score_cake[cc] = 0;
    
    //TODO cal value
    REP(i, now_tot_guest_of_cake[cc]){
        int gg = now_guest_of_cake[cc][i];
        REP(j,S)REP(k,S){
            now_value_cell[gg][j][k] = get_value(gg, cc, j, k);
        }
    }
    
    temperature_cake[cc] = START_TEMPERATURE_CAKE;
}

void choose_init_state_cake(int cc) // choose start cell of each guest
{
    // TODO
    REP(i, now_tot_guest_of_cake[cc]){
        int gg = now_guest_of_cake[cc][i];
        now_start_cell[gg] = MP(rand()%S, rand()%S);
    }
    save_now_to_last_cake(cc);
}

void generate_new_state_cake(int cc)
{
    // TODO
//    REP(i, now_tot_guest_of_cake[cc]){
//        int gg = now_guest_of_cake[cc][i];
//        now_start_cell[gg] = last_start_cell[gg];
//    }
//    REP(i, now_tot_guest_of_cake[cc]){
//        int g1 = now_guest_of_cake[cc][i], g2 = now_guest_of_cake[cc][rand()%now_tot_guest_of_cake[cc]];
//        swap(now_start_cell[g1], now_start_cell[g2]);
//    }
    REP(i, now_tot_guest_of_cake[cc]){
        int gg = now_guest_of_cake[cc][i];
        now_start_cell[gg] = MP(rand()%S, rand()%S);
    }
    
}

void reset_cake(int cc)
{
    REP(row, S) REP(col, S){
        now_cake_state[cc][row][col] = -1;
        cake_preflag[cc][row][col] = 0;
    }
    
    tot_guest_of_cake[cc] = 0;
    
    REP(i, now_tot_guest_of_cake[cc]){
        int gg = now_guest_of_cake[cc][i];
        now_score_guest[gg] = 0;
        tot_cell_of_guest[gg] = 0;
        tot_bound_of_guest[gg] = 0;
        
        // init queue
        tot_cell_of_guest[gg] = 0;
        cell_of_guest[gg][tot_cell_of_guest[gg]++] = now_start_cell[gg];
        cmp_gg = gg;
        push_heap(cell_of_guest[gg], cell_of_guest[gg]+tot_cell_of_guest[gg],mycmp_cell_of_guest);
        
        guest_of_cake[cc][tot_guest_of_cake[cc]++] = gg;
        push_heap(guest_of_cake[cc], guest_of_cake[cc]+tot_guest_of_cake[cc], mycmp_guest_of_cake);
    }
    
}

void solve_now_cake(int cc)
{
    #ifdef DEBUG
    #ifdef PRINT
    DPRINT("solve cake #%d start ..\n", cc);
    #endif
    #endif
    reset_cake(cc);

    bool run = true;
    while(tot_guest_of_cake[cc] > 0) {
        int gid = guest_of_cake[cc][0];
        pop_heap(guest_of_cake[cc], guest_of_cake[cc]+tot_guest_of_cake[cc], mycmp_guest_of_cake);
        tot_guest_of_cake[cc]--;
        ipair cell;
        // TODO pop a cell , must change to guest queue
        if(tot_cell_of_guest[gid] > 0){
            cell = cell_of_guest[gid][0];
            cmp_gg = gid;
            pop_heap(cell_of_guest[gid], cell_of_guest[gid]+tot_cell_of_guest[gid], mycmp_cell_of_guest);
            tot_cell_of_guest[gid]--;
            
//            #ifdef DEBUG
//            DPRINT(" pop cell (%d,%d) of cell %d\n", cell.first, cell.second, gid);
//            DPRINT(" \\ value = %lld\n", now_value_cell[gid][cell.first][cell.second]);
//            #endif
            
            if(now_cake_state[cc][cell.first][cell.second] == gid){ // already this guest
                ;
            } else{
                if(true || check_connect_cell(cc, cell, gid)){ // is connected
                    if(now_cake_state[cc][cell.first][cell.second] == -1){ // empty, found
//#ifdef DEBUG
//    DPRINT(" set cell (%d,%d) to guest %d, values %lld\n", cell.first, cell.second, gid, now_value_cell[gid][cell.first][cell.second]);
//#endif
                        remove_preflag(cc, cell, gid);
                        now_cake_state[cc][cell.first][cell.second] = gid;
                        // add score
                        now_score_guest[gid] += joy[gid][cc][cell.first][cell.second];
                        
                        REP(k,4){
                            int tr = cell.first + DR[k], tc = cell.second + DC[k];
                            ipair tcell = MP(tr, tc);
                            if(is_in_cake(tr,tc) && !check_preflag(cc, tcell, gid) && now_cake_state[cc][tr][tc]!=gid){
                                set_preflag(cc, tcell, gid);
                                cell_of_guest[gid][tot_cell_of_guest[gid]] = tcell;
                                tot_cell_of_guest[gid]++;
                                cmp_gg = gid;
                                push_heap(cell_of_guest[gid], cell_of_guest[gid]+tot_cell_of_guest[gid], mycmp_cell_of_guest);
                            }
                        }
                    } else{ // bound, add to bound queue
                        remove_preflag(cc, cell, gid);
                        bound_of_guest[gid][tot_bound_of_guest[gid]] = cell;
                        tot_bound_of_guest[gid]++;
                        cmp_gg = gid;
                        push_heap(bound_of_guest[gid], bound_of_guest[gid]+tot_bound_of_guest[gid], mycmp_cell_of_guest);
                    }
                } else{ // not connected
                    remove_preflag(cc, cell, gid);
                }
            }
            
            guest_of_cake[cc][tot_guest_of_cake[cc]] = gid;
            tot_guest_of_cake[cc]++;
            push_heap(guest_of_cake[cc], guest_of_cake[cc]+tot_guest_of_cake[cc], mycmp_guest_of_cake);
        } else{
            // adjust
        }
    }
    
    now_score_cake[cc] = INF_INT;
    REP(i, now_tot_guest_of_cake[cc]){
        int gg = now_guest_of_cake[cc][i];
        now_score_cake[cc] = min(now_score_cake[cc], now_score_guest[gg]);
    }
    
    #ifdef DEBUG
    #ifdef PRINT
    DPRINT("solve cake #%d end\n", cc);
    #endif
    #endif
}

#ifdef DEBUG
void show_state_cake(int cc)
{
    DPRINT("Cake #%d state:\n", cc);
    DPRINT("Start cell:");
    REP(i,now_tot_guest_of_cake[cc]){
        int gg = now_guest_of_cake[cc][i];
        DPRINT(" %d(%d,%d)", gg, now_start_cell[gg].first, now_start_cell[gg].second);
    }
    DPRINT("\n");
    DPRINT("Temp = %lf\n", temperature_cake[cc]);
    DPRINT("\n");
}
#endif

void sa_cake(int cc)
{
    init_cake(cc);
    cake_round[cc] = 0;
    while(has_time_cake()){
        
//        #ifdef DEBUG 
        // TODO
        if(cake_round[cc] > (int)(now_tot_guest_of_cake[cc]*1.5))break;
//        #endif
        
        if(cake_round[cc] == 0){
            choose_init_state_cake(cc);
        } else{
            generate_new_state_cake(cc);
        }
        
#ifdef DEBUG
//        show_state_cake(cc);
#endif
        
        solve_now_cake(cc);
        check_best_cake(cc);
        
        if(cake_round[cc] > 0){
            int det = now_score_cake[cc] - last_score_cake[cc];
            if(det > 0){
                save_now_to_last_cake(cc);
            } else{
                if(myexp_cake(det, get_next_temperature_cake(cc)) > myrand(0,1)){
                    save_now_to_last_cake(cc);
                }
            }
        } else{
            save_now_to_last_cake(cc);
        }
        
    #ifdef DEBUG
//        DPRINT("-- Cake #%d, Round = %d, Score = %d\n", cc, cake_round[cc], best_score_cake[cc]);
//        DPRINT("\n");
    #endif
        
        cake_round[cc]++;
    }
}

void check_best_all()
{
    if(now_score_all > best_score_all){
        #ifdef DEBUG
//        int ss[MAXG] = {0};
        #endif
        best_score_all = now_score_all;
        REP(i,C) REP(j,S) REP(k,S){
            best_state_all[i][j][k] = best_cake_state[i][j][k];
            #ifdef DEBUG
//            int gg = best_cake_state[i][j][k];
//            ss[gg] += joy[gg][i][j][k];
            #endif
        }
        #ifdef DEBUG
//        int tbest = INF_INT;
//        REP(i,G) tbest = min(tbest, ss[i]);
//        DPRINT("DEBUG best = %d\n", tbest);
        #endif
    } 
}

void save_now_to_last_all()
{
    last_score_all = now_score_all;
    REP(i,G) {
        last_in_cake[i] = now_in_cake[i];
    }
    REP(i,C) {
        last_tot_guest_of_cake[i] = now_tot_guest_of_cake[i];
        REP(j,now_tot_guest_of_cake[i]){
            last_guest_of_cake[i][j] = now_guest_of_cake[i][j];
        }
    }
}

double get_next_temperature_all()
{
    double ret = temperature_all;
    temperature_all *= R_TEMPERATURE_ALL;
    return ret;
}

double myexp_all(int det, double temp)
{
    return exp(det/temp);
}

void init_all()
{
    #ifdef DEBUG
//    DPRINT("init_all .. ");
    #endif
    int s = 0;
    REP(i,G)REP(j,I) pref[i][j] = preferences[s++];
    s = 0;
    REP(i,C)REP(row,S)REP(col,S)REP(j,I) cake[i][row][col][j] = cakes[s++];
    
    REP(i,G)REP(j,C)REP(row,S)REP(col,S){
        joy[i][j][row][col] = 0;
        REP(k,I) joy[i][j][row][col] += cake[j][row][col][k]*pref[i][k];
    }

    now_score_all = last_score_all = best_score_all = 0;
    REP(i,C)REP(j,S)REP(k,S) {
        best_state_all[i][j][k] = -1;
    }
    
    atime_cake_round = 0;
    atime_all_round = 0;
    
    temperature_all = START_TEMPERATURE_ALL;
    
    #ifdef DEBUG
//    DPRINT("done\n");
    #endif
}



void choose_init_state_all() // choose guests of each cake
{
    //TODO
    REP(i,C){
        now_tot_guest_of_cake[i] = 0;
    }
    REP(i,G){
        int cc = rand()%C;
        now_guest_of_cake[cc][now_tot_guest_of_cake[cc]] = i;
        now_tot_guest_of_cake[cc]++;
        now_in_cake[i] = cc;
    }
    save_now_to_last_all();
}

void generate_new_state_all()
{
    // TODO
    REP(i,C){
        now_tot_guest_of_cake[i] = 0;
    }
    REP(i,G){
        int cc = rand()%C;
        now_guest_of_cake[cc][now_tot_guest_of_cake[cc]] = i;
        now_tot_guest_of_cake[cc]++;
        now_in_cake[i] = cc;
    }
}

void reset_all()
{
    now_score_all = 0;
    REP(i,C){
        last_score_cake[i] = now_score_cake[i] = best_score_cake[i] = 0;
        REP(j,S)REP(k,S){
            now_cake_state[i][j][k] = best_cake_state[i][j][k] = -1;
        }
    }
}

void solve_now_all()
{
    reset_all();
    now_score_all = INF_INT;
    REP(cc, C){
        sa_cake(cc);
        now_score_all = min(now_score_all, best_score_cake[cc]);
    }
}

#ifdef DEBUG
void show_state_all()
{
    DPRINT("All Round #%d:\n", round_count);
    REP(i,C){
        DPRINT("Cake #%d(%d Guests):", i, now_tot_guest_of_cake[i]);
        REP(j,now_tot_guest_of_cake[i]){
            DPRINT(" %d", now_guest_of_cake[i][j]);
        }
        DPRINT("\n");
    }
    DPRINT("Temp = %lf\n", temperature_all);
    DPRINT("\n");
}
#endif

#ifdef DEBUG
void show_current_best_all()
{
    DPRINT("------------------------ %d\n", round_count);
//    REP(i,C){
//        REP(j,now_tot_guest_of_cake[i]){
//            int gg = now_guest_of_cake[i][j];
//            DPRINT("Guest #%d = %d\n", gg, now_score_guest[gg]);
//        }
//        DPRINT(" ***\n");
//    }
    DPRINT("Current Best Score = %d\n", best_score_all);
//    DPRINT("\n");
}
#endif

void sa_all()
{
    init_all();
    
    round_count = 0;
    while(has_time_all()){
        #ifdef DEBUG
//        if(round_count > 10) break;
        #endif
        if(round_count == 0){
            choose_init_state_all();
        } else{
            generate_new_state_all();
        }
#ifdef DEBUG
//        show_state_all();
#endif
        
        solve_now_all();
        check_best_all();
#ifdef DEBUG
        show_current_best_all();
#endif
        
        int det = now_score_all - last_score_all;
        if(det > 0){
            save_now_to_last_all();
        } else{
            if(myexp_all(det, get_next_temperature_all()) > myrand(0,1)){
                save_now_to_last_all();
            }
        }
        

        
        round_count++;
    }
}

vint god_is_in_the_tv()
{
    sa_all();
    vint ret(C*S*S);
    int ss = 0;
    REP(i,C) REP(j,S) REP(k,S)
        ret[ss++] = best_state_all[i][j][k];
        
    #ifdef DEBUG
    DPRINT("Time cost: %lf\n", (double)gettime()/TIMES_PER_SEC);
    #endif
    return ret;
}


class Cakes
{
public:
    vector <int> split(int _C, int _G, int _I, int _S, vector <int> _preferences, vector <int> _cakes){
        starttime_acrush = gettime();
        time_up = false;
        C = _C, G = _G, I = _I, S = _S, preferences = _preferences, cakes = _cakes;
        return god_is_in_the_tv();
    }

};

#ifdef LOCAL
inline int getInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

void input()
{
    C = getInt();
	G = getInt();
	I = getInt();
	S = getInt();
    preferences.clear();
    cakes.clear();
	for (int i=0; i < G*I; i++)
		preferences.PB(getInt());

	for (int i=0; i < C*S*S*I; i++)
		cakes.PB(getInt());
}

int main()
{
#ifdef DEBUG
//    freopen("cake.log","w",stderr);
#endif
    Cakes hello;
    input();
#ifdef DEBUG
    DPRINT("%d %d %d %d\n", C, G, I, S);
#endif
    vint ret = hello.split(C, G, I, S, preferences, cakes);
#ifdef DEBUG
    Timer::show();
#endif

    for (int i=0; i < ret.size(); i++)
        printf("%d\n", ret[i]);
    fflush(stdout);
    return 0;
}
#endif

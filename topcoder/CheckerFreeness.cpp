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
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

struct point {
	int x, y;
	point(int _x = 0, int _y = 0)
		:x(_x), y(_y)
	{}
	
	void show() const { cout << x << "," << y << endl; }
};

inline int xmul2(int x1, int y1, int x2, int y2)
{
    long long t = (long long)x1*y2-(long long)y1*x2;
    return t==0 ? 0 
            : t > 0 ? 1 : -1;
}

point cmpo;
struct comparator {
    bool operator()(const point &i, const point &j) {
        return xmul2(i.x-cmpo.x, i.y-cmpo.y, j.x-i.x, j.y-i.y) > 0;
    }
};

vector<int> wx, wy, bx, by;
vector<point> wp, bp;

void cat(vector<string> vs, vector<int> &vl) {
	istringstream is(accumulate(vs.begin(), vs.end(), string("")));
	int t;
	vl.clear();
	while(is >> t) 
		vl.push_back(t);
}

void readpoint(vector<int> &vx, vector<int> &vy, vector<point> &vp) {
	vp.clear();
	REP(i, vx.size())
		vp.push_back(point(vx[i], vy[i]));
}

class CheckerFreeness {
    public: 
    string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
		cat(whiteX, wx);
		cat(whiteY, wy);
		cat(blackX, bx);
		cat(blackY, by);

		readpoint(wx, wy, wp);
		readpoint(bx, by, bp);
		if(wp.size() > bp.size())
            swap(wp, bp);

		for(int i = 0; i < wp.size(); i++)
            for(int j = i+1; j < wp.size(); j++)
                if(count(wp[j], wp[i])) 
                    return "NO";
		return "YES";
    }

	bool count(point s, point t) {
//	    cout << "white pair (" << s.x << "," << s.y << ") (" << t.x << "," << t.y << ")\n";
		vector<point> l, r;
		l.reserve(255), r.reserve(255);
		REP(i, bp.size()) {
			int cc = xmul2(t.x-s.x, t.y-s.y, bp[i].x-t.x, bp[i].y-t.y);
			if(cc > 0) {
				l.push_back(bp[i]);
			} else if(cc < 0) {
			    r.push_back(bp[i]);
			}
		}
		if(l.empty() || r.empty())
            return false;
        cmpo = t;
		sort(l.begin(), l.end(), comparator());
		sort(r.begin(), r.end(), comparator());
//		cout << " left:\n";
//		REP(i, l.size()) l[i].show();
//		cout << " right:\n";
//		REP(i, r.size()) r[i].show();
		cmpo = s;
		set<point, comparator> ar;
		int pl = l.size()-1, pr = r.size()-1;
		while(pr >= 0) {
            while(pl >= 0 && xmul2(t.x-r[pr].x, t.y-r[pr].y, l[pl].x-t.x, l[pl].y-t.y) > 0){
//                cout << "+l ";
//                l[pl].show();
                ar.insert(l[pl--]); 
                while(ar.size() > 1)
                    ar.erase(--ar.end());
            }
            if(!ar.empty() && xmul2(s.x-(*ar.begin()).x, s.y-(*ar.begin()).y, r[pr].x-s.x, r[pr].y-s.y) > 0) {
//                (*ar.rbegin()).show();
//                r[pr].show();
                return true;
            }
            pr--;
		}
		return false;
	}


    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "NO"; verify_case(0, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"2", "5", "3", " ", "1", "7", "3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"180 254"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"32", "5 1", "42"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"462 423"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(1, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1 10000000 9999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 9999999 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 5000000 9999998"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2 5000001 9999999"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(2, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(3, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
,"93 5922 714 2258 4369 9524 302 8417 6620 1143"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "NO"; verify_case(4, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"219211 1996214 1706774 3634920 909831 1774128 8503"
,"52 2233050 2099138 3380396 1128982 3682525 1483700"
," 763080 487867 8203 1791027 463556 1103323 1406861"
," 6374234 760949 4340236 727393 2073832 1289052 103"
,"8147 4448130 151066 412440 1068735 377239 2677933 "
,"1299598 339843 289973 3707319 555280 230418 431719"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1638083 5698739 3105504 9726902 9745795 5049444 15"
,"80592 3952120 6606668 7460527 7239299 8726128 4913"
,"547 6264100 5701660 8865937 4969114 8014845 327236"
,"1 6389154 9739755 2561669 9412417 5452337 3150506 "
,"5832197 1571976 8779325 3306446 948271 5133709 949"
,"394 6919798 7525636 3568024 6833196 9237472 733313"
,"1 9939064 9720014"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"5860334 8007503 7455523 4864927 9573526 2718360 81"
,"12104 6684287 9921506 4840886 5415948 3451454 5320"
,"996 9268757 9261724 8254668 2292750 8035828 233352"
,"1 7676906 5234406 8533320 6562751 4884098 4971897 "
,"5569360 8519168 3100295 9351613 7733878 7579030 32"
,"46775 7297460 8370542 7099759 5782969 2978083 3390"
,"488 7482758 1332401 6094629 9717305 5503121 572842"
,"1 4903563 6331656 2867455 3410007 7751527 7228221 "
,"4111694 5171296 6847697 4601273 7599828 5515929 94"
,"60593 9332762 5389080 4512091 8668538 5711743 5838"
,"534 4825079 8145628 3810005 2964724 5594550 785748"
,"3 6283769"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"5911694 8009943 212555 5838688 9896256 607434 5857"
,"663 4616750 1477573 7168026 3090917 4379806 326465"
,"7 4189076 2104028 3279691 94211 8503556 78457 4394"
,"360 3344176 3223317 2624498 4883494 1532240 732937"
,"1 1518674 1353567 892134 5536454 8527392 2603965 6"
,"623264 8830827 2030444 3002706 83058 4475866 20876"
,"25 1790695 4034441 5409379 3571098 4600050 736561 "
,"250475 3733256 3011439 2144994 4523046 3119883 607"
,"582 8361403 6525451 7518329 926803 4884524 8424659"
," 7088689 5762049 9532481 4914186 7314621 4339084 3"
,"741685 3837953 3177252 612550 9688871 5872931"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(5, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }

    void test_case_6() { string Arr0[] = {
        "3359696 6111410 6095715 5598796 6265151 3399058 53", "99133 6071850 3362551 5613428 6240987 3431316 5265", "775 6091765 5444720 5414366 6047603 6035340 556937", "3 3412799 5474916 3374264 6288703 3390608 6043526 ", "3355260 5276107 3380230 6295318 5623153 5559520 60", "63810 3354422 6075854 5589011 5564449 6119192 3434", "885 6123066 3357873 3402002 5332731 5484944 538895", "8 6067835 3384002 6153658 3360631 3381472 5296739 ", "6149874 3382729 5383864 6157431 6172409 5342986 54", "29562 6161193 5286429 5514913 6168682 3409636 5539", "747 6292017 3361583 6271943 6176125 5327599 339336", "1 3440353 6237486 3364536 3444076 3424365 3429555 ", "5394047 6039438 3414405 5378767 5584110 5312183 60", "27113 5439671 6146078 6126929 6183522 5603679 5291", "586 6103585 6261736 6247953 3365552 3379005 628537", "6 6087803 5499951 3406535 6212637 6142270 6083831 ", "5317325 3369779 6282037 5322463 5593906 6219797 54", "09292 6138452 5363454 3391977 6226909 3420982 3349", "008 3411210 3400522 6194529 3436692 3375425 335698", "6 6251417 3442207 5489951 5494953 3351231 3433093 ", "3394762 3377796 6275320 5628006 6031232 5270942 54", "34619 6107503 5260604 3408077 3403497 5464869 3358", "776 6164943 5504943 6233973 5424500 5608556 622335", "9 5301890 6198174 3387918 3422666 5337860 3368698 ", "6134622 6209039 5348108 6079848 6268553 5373666 55", "29829 6179829 3363535 6278685 3349733 5353227 5454", "803 5549644 3397610 5469894 6190871 6258309 547993", "2 5579203 3427809 3405008 3385292 3367633 6022985 ", "3366585 3438515 3386597 5419435 6205430 5509930 56", "18293 5574291 3352004 3396178 5459838 6187202 3389", "255 5534791 3373119 6254869 3370876 6059774 605572", "7 3371989 5519890 5554585 5368562 6244476 3353600 ", "6099655 3419314 6130781 5544699 5281269 5358342 62", "30447 5404214 6115306 5449764 3376602 3417662 6216", "223 3356115 5307038 3426079 3350473 5524862 605167", "1 6201808 3352794 3416026"
        }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {
            "5295259 6241991 6255859 3444616 6084973 5463424 33", "81831 6276288 5310706 3450328 6112530 5563034 3354", "661 6259295 3393762 3385665 6296264 6306080 343360", "6 5508498 3402429 5367095 6056891 5433167 6299549 ", "5269458 3356363 5392586 6048773 3454213 3430059 62", "82997 5264290 6272914 3440884 3431825 6234983 5572", "879 6231461 5284947 5473474 3366884 3405445 337935", "5 6279649 5407834 6202849 5300411 5397672 3359963 ", "6206468 5402755 3378141 6199219 6184580 3369007 33", "89642 6195577 3358131 3414869 6188257 5498516 3423", "152 6052837 5305560 6077002 6180891 3365847 544327", "0 5587604 6116423 5320988 5597392 5543277 5558103 ", "3380585 6302821 5513482 3376944 3439041 3362832 63", "12559 3392373 6210074 6227927 6173478 3446505 3359", "038 6248949 6088942 6104711 5326124 5387495 606093", "4 6262718 3410086 5488514 6143365 6213669 6266130 ", "3363821 5346637 6064967 3364826 3442742 6135723 33", "84371 6217251 3373446 5438221 6128037 5533366 5228", "041 5503510 5468451 6162271 5577793 5372201 527978", "7 6100785 5592501 3406976 3408523 5243591 5567959 ", "5448315 5382401 6073001 3456178 6309326 3355504 33", "90999 6245476 3353834 5493517 5478492 3399477 5290", "105 6191923 3411665 6120306 3388300 3448409 613188", "6 3360903 6158513 5423046 5538324 3367938 5341514 ", "6220822 6147169 3370093 6269528 6080993 3375762 34", "19792 6177190 5315848 6068989 5233226 3371194 3396", "588 3426575 5458392 3400945 6166018 6092900 340392", "9 3437214 5553166 5483505 5412909 5336387 6315779 ", "5331257 5582701 5417979 3386975 6150962 3413259 34", "52263 3435402 5248769 5453356 3398024 6169754 5428", "108 3421464 5361986 6096848 5351757 6286333 628965", "6 5356873 3416494 3428309 3374596 6108626 5259119 ", "6252410 5528403 6224380 3424856 3357239 3372312 61", "24177 3383093 6238493 3395167 5377302 5523435 6139", "550 5274624 3361859 5548224 5238410 3418135 629296", "6 6154743 5253945 5518461"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
    "8200999 7978793 7216394 7174055 9361 7411312 44463", " 7117303 73060 22908 8249013 7694829 7641693 73004", "77 7991394 7327820 27634 7574197 7707567 8029020 7", "915347 16012 1036 7272538 7520130 7601079 48741 80", "66378 36494 7145721 7588139 24434 8176802 6857914 ", "7451988 40380 10347 32803 6755390 7506551 6843321 ", "54 5 5173 7383743 7614967 7074519 7654532 7851183 ", "495 3252 6784771 7864072 7060217 6666835 7825319 8", "016508 7889767 7131523 7928094 7953502 7299970 56 ", "7614481 7574686 8128033 6959539 7694348 67806 6814", "082 6973981 6945078 305 3866 1394 5912 84151 5199 ", "31031 7773258 8140272 38412 7667831 7045894 747931", "9 1790 7258536 6901580 7547214 7328325 8152480 807", "8770 46577 1774 8225070 6872488 156 7538 7601566 6", "725939 60291 7031551 7812345 7479814 2729 7681584 ", "78508 6681636 70409 6887043 7202302 2235 7313906 1", "1381 7356080 7940813 7655016 17293 7355577 8425 44", "84 7438287 34624 7369421 2710 8041503 7760174 6 80", "53955 7438785 7799344 7507045 503 7520623 8091131 ", "12465 7452486 21430 18623 8115763 7492947 1048 724", "4510 6799436 8003966 7902571 6740673 7533685 2218 ", "4508 57883 6770089 7733925 7534177 7397539 299 682", "8711 50953 7088801 7668313 7560718 7410812 65253 7", "493442 7369923 7188189 55525 7966162 7159899 77863", "15 7561208 53215 6711188 6916099 13598 7641208 768", "1103 7466162 7314412 7465666 3843 75760 26010 7876", "934 8237057 7103063 8164657 7017189 7425060 20002 ", "7230463 7341710 14781 151 7587651 7342214 6988403 ", "7424561 42397 6701 7547705 6696420 62747 7627857 2", "9308 6930598 7397038 8213050 7002806 741 81305 728", "6519 7838265 7383241 8103463 751 3273 7628343 7720", "759 7747063 8188916 1381"
}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {
    "8841041 9015817 518081 497391 5305828 619866 56653", "23 470427 5851626 5478076 8800514 788362 754831 56", "0652 9006439 9425071 5524962 9286432 9203460 89780", "69 9062111 5399840 5101809 546286 9318441 9270174 ", "5696447 8949344 5602999 483820 721970 5493709 8861", "078 358001 9357493 5634174 5321505 5571801 318269 ", "9326337 352187 5023276 5007568 5227401 604801 7383", "16 450673 9237151 9107402 5070398 5180317 329390 9", "098424 444179 286014 9125235 8987565 9080348 47710", "1 9052932 9034454 9439609 4976152 9261981 713861 8", "900693 399977 9211945 5820652 340697 406156 393844", " 4944737 4803415 4881915 5243092 5913471 4772028 5", "556193 9160413 8890846 5618590 9228791 437729 9342", "001 4866212 539168 375717 9302522 575194 8880962 8", "939692 5680888 5133216 8820853 363860 4960445 5274", "466 730122 307332 5774132 431324 9134091 658281 48", "34811 779916 5882566 291274 5836143 369766 511140 ", "4850511 9432362 5337179 589911 9043713 763151 5415", "496 9410357 5290148 5211708 9365175 5587403 940293", "5 5164618 8968533 9169104 4991860 8958958 635103 9", "142906 673948 4929031 681845 8930000 5352850 64278", "6 5462437 5431147 8910500 9334190 4897620 532095 3", "35020 8997022 9071249 312777 9310503 5148918 47877", "20 5758609 323806 9186365 689785 612312 5054691 34", "6419 5711998 457213 771513 9294498 9380409 5805153", " 666093 597334 504243 5743080 9025156 490583 91516", "80 705793 5727542 301933 381714 5368517 9245470 92", "20389 650512 567901 9349768 5196013 5867100 550933", "8 9089406 8810702 463798 8871039 424964 627462 544", "6794 525066 9417736 5384180 5038984 9278324 582531", " 412380 9372813 5649752 5258780 697768 296580 5789", "646 9253746 5540580 387756 9387961 8830966 418650 ", "5086104 5898023 553447 9116339 9395470 8920270 491", "3325 4819112 746553 9194933 9177755 8851078 511751", "3"
}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YES"; verify_case(6, Arg4, isFree(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CheckerFreeness ___test;
    ___test.run_test(6);
    return 0;
}
// END CUT HERE

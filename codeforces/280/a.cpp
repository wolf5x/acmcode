#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 3.1415926535897932384626;

double w, h;
int a;
pair<double, double> rotate(pair<double, double> p, double a) {
	return make_pair(p.first*cos(a)-p.second*sin(a),
			p.second*cos(a)+p.first*sin(a));
}

double dist(pair<double,double> p1, pair<double,double> p2) {
	double dx = p1.first-p2.first;
	double dy = p1.second-p2.second;
	return sqrt(dx*dx+dy*dy);
}

int main() {
	while(cin >> w >> h >> a) {
		if(w < h) swap(w, h);
		if(a >= 180) a-=180;
		if(a > 90) a = 180-a;
		double ans = 0;
		if(a == 0) {
			ans = w*h;
		} else if(a == 90) {
			ans = h*h;
		} else {
			double th = (double)a*PI/180;
			pair<double,double> A = rotate(make_pair(w/2, h/2), th);
			pair<double,double> B = rotate(make_pair(-w/2, h/2), th);
			pair<double,double> C = rotate(make_pair(w/2, -h/2), th);
			if(C.second <= h/2) {
				double PX = B.first+(A.first-B.first)*(h/2-B.second)/(A.second-B.second);
				double PY = h/2;
				double L1 = dist(A, make_pair(PX, PY));
				double S1 = L1*L1*tan(th)/2;
				double RX = w/2;
				double RY = C.second+(A.second-C.second)*(C.first-w/2)/(C.first-A.first);
				double L2 = dist(C, make_pair(RX, RY));
				double S2 = L2*L2*tan(th)/2;
				ans = w*h-S1*2-S2*2;
			} else {
				ans = h*h/sin(th);
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}


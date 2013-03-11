#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int x, y, n;
long long a, b;

long long gcd(long long a, long long b) {
	return b?gcd(b, a%b):a;
}

void check(long long p, long long q) {
	long long s1 = abs(x*b-y*a), t1 = y*b, g1 = gcd(s1,t1);
	long long s2 = abs(x*q-y*p), t2 = y*q, g2 = gcd(s2,t2);
	s1 /= g1, t1 /= g1;
	s2 /= g2, t2 /= g2;
	long long d = s1*t2-s2*t1;
	if(d > 0
			|| d == 0 && q < b 
			|| d == 0 && q == b && p < a)
		a = p, b = q;
}

int main() {
	while(cin >> x >> y >> n) {
		a = 0, b = 1;
		for(long long q = 1; q <= n; ++q) {
			check((long long)x*q/y, q);
			check((long long)x*q/y+1, q);
		}
		long long g = gcd(a, b);
		cout << a/g << "/" << b/g << endl;
	}
	return 0;
}


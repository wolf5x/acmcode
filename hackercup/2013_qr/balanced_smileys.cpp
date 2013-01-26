#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
string s;
int ok[510][510];

int solve(int pos, int open) {
	if(open < 0) return 0;
	int &r = ok[pos][open];
	if(r >= 0) return r;
	if(pos == s.length())
		return r = (open == 0);
	r = 0;
	if(s[pos] == '(') 
		r = r || solve(pos+1, open+1);
	if(s[pos] == ')') 
		r = r || solve(pos+1, open-1);
	if(pos+1 < s.length() && s[pos] == ':' && s[pos+1] == ')')
		r = r || solve(pos+2, open);
	if(pos+1 < s.length() && s[pos] == ':' && s[pos+1] == '(')
		r = r || solve(pos+2, open);
	if(s[pos] != ')' && s[pos] != '(') 
		r = r || solve(pos+1, open);

	return r;
}

int main() {
	cin >> T;
	getline(cin, s);
	for(int cas = 1; cas <= T; ++cas) {
		getline(cin, s);
		memset(ok, -1, sizeof(ok));
		cout << "Case #" << cas << ": " << (solve(0, 0)?"YES":"NO") << endl;
	}
	return 0;
}


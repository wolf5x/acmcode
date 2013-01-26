#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int m, c[26];
string s;

int main() {
	cin >> m;
	getline(cin, s);
	for(int cas = 1; cas <= m; ++cas) {
		fill(c, c+26, 0);
		getline(cin, s);
		for(int i = 0; i < s.length(); ++i) 
			if(isalpha(s[i] = tolower(s[i])))
				++c[s[i]-'a'];
		sort(c, c+26);
		int ans = 0;
		for(int i = 0; i < 26; ++i) 
			ans += (i+1)*c[i];
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}


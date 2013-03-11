#include <iostream>
#include <cstdio>
using namespace std;

char s[1111];
int main() {
	while(~scanf("%s", s)) {
		for(int i = 0; s[i]; i++) {
			if(i == 0) putchar(toupper(s[i]));
			else putchar(s[i]);
		}
		puts("");
	}
	return 0;
}


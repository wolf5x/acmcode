#include <string.h>
#include <stdio.h>

int pos[10][10];
int a, b, n, T;

int main() {
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++) {
		scanf("%d%d%d", &a, &b, &n);
		int x, y, ans;
TRY:
		memset(pos, 0, sizeof(pos));
		pos[a][b] = 2;
		x = a, y = b, ans = -1;
		while(true) {
			if(pos[x][y] == n) {
				ans = y; break;
			} else if(pos[x][y] == n+1) {
				ans = x; break;
			}
			int s = y, t = x+y, d = 1;
			if(t >= 10) {
				s = t/10, t = t%10, d = 0;
			}
			if(pos[s][t] > 0) {
				n -= pos[s][t]-2;
				n = (n-1)%(pos[x][y] - (pos[s][t]-2) - d) + 1;
				a = s, b = t;
				goto TRY;
			}
			pos[s][t] = pos[x][y] + 2-d;
			x = s, y = t;
		}
		printf("Case #%d: %d\n", cas, ans);
	}

	return 0;
}

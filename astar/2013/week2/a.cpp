#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, M, H;
int X[100010];

int main() {
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++) {
		scanf("%d%d%d", &N, &M, &H);
		for(int i = 0; i < M; i++) {
			scanf("%d", &X[i]);
		}
		sort(X, X+M);
		M = unique(X, X+M)-X;
		int p = 0;
		for(int i = 1; i <= N; i++) {
			while(p<M && X[p]<i) p++;
			int d = H;
			if(p>0) d = min(d, abs(i-X[p-1]));
			if(p<M) d = min(d, abs(X[p]-i));
			printf("%d\n", max(0, H-d));
		}
	}
	return 0;
}


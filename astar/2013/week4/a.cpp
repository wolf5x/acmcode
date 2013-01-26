#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int N, d[111];

int main() {
	while(~scanf("%d", &N) && N > 0) {
		--N;
		for(int i = 0; i < N; i++)
			scanf("%d", &d[i]), --d[i];
		bool ok = true;
		for(int i = 0; ok && i < N ; i++) {
			sort(d+i, d+N, greater<int>());
			ok = true;
			for(int j = i+1; ok && j < N && d[i] > 0; j++) {
				if(d[j] <= 0)
					ok = false; 
				else 
					--d[j], --d[i];
			}
			if(d[i]) 
				ok = false;
		}
		puts(ok ? "Maybe truth" : "Lie absolutely");
	}
	return 0;
}


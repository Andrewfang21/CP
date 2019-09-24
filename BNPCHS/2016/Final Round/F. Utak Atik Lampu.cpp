#include<bits/stdc++.h>
using namespace std;

const int n = 1005;

int N, X;
bool isON[n];

void solve (int tc) {
	scanf("%d %d", &N, &X);
	
	memset(isON, false, sizeof(isON));
	for (int i = 1; i <= X; i ++) {
		for (int j = 1; j <= N; j ++) {
			if (j % i == 0) {
				if (isON[j])
					isON[j] = false;
				else
					isON[j] = true;
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i ++)
		if (isON[i])
			res ++;

	printf("Kasus #%d: %d\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve (i);		
	}

return 0;
}
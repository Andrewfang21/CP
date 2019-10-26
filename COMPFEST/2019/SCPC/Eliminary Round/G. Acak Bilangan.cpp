#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
int currMax[2], sum[N][2];

void solve(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 2; i ++) {
		for (int j = 0; j < n; j ++) {
			int x;
			cin >> x;
			sum[x][i] ++;

			if (sum[x][i] > sum[currMax[i]][i])
				currMax[i] = x;
		}
	}

	if (currMax[0] == currMax[1] && sum[currMax[0]][0] + sum[currMax[1]][1] - n > k)
		printf("Tidak\n");
	else
		printf("Ya\n");
}

int main() {
	
	solve();

return 0;
}
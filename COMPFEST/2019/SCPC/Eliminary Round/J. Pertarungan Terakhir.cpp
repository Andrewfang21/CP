#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2005, MOD = 1e9 + 7;

int n, m;
int A[N], B[N], dp[N][N][2], MAX[N];

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf("%d", &A[i]);

	for (int i = 0; i < m; i ++)
		scanf("%d", &B[i]);
}

ll solve(int pos_x, int pos_y, int isActive) {
	if (pos_y == m - 1)
		return (MAX[pos_x] == B[pos_y] ? 1 : 0);
	if (pos_x == n)
		return 0;
	if (A[pos_x] > B[pos_y])
		return 0;
	if (dp[pos_x][pos_y][isActive] != -1)
		return dp[pos_x][pos_y][isActive];

	ll res = 0;
	if ((A[pos_x] == B[pos_y]) || isActive == 1)
		res = (solve(pos_x + 1, pos_y, 1) + solve(pos_x + 1, pos_y + 1, 0)) % MOD;
	else
		res = solve(pos_x + 1, pos_y, 0) % MOD;

return dp[pos_x][pos_y][isActive] = res;
}

void work() {
	for (int i = n - 1; i >= 0; i --)
		MAX[i] = max(MAX[i + 1], A[i]);

	memset(dp, -1, sizeof(dp));
	ll res = solve(0, 0, 0);

	printf("%lld\n", res);
}	

int main() {
	read();
	work();

return 0;
}
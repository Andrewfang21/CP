#include<bits/stdc++.h>
using namespace std;

const int n = 1005;

int N, sum;
int dp[n][n][2], A[n];

void read ()
{
	sum = 0;
	for (int i = 1; i <= N; i ++)
	{
		scanf("%d" ,&A[i]);
		sum += A[i];
	}
}

int solve (int L, int R, int turn)
{
	if (L > R)
		return 0;
	if (dp[L][R][turn] != -1)
		return dp[L][R][turn];

	int ans = 0;

	if (turn == 1)
	{
		ans = max(solve(L + 1, R, 0) + A[L],
				  solve(L, R - 1, 0) + A[R]);
	}
	else
	{
		if (A[L] >= A[R])
			ans = solve(L + 1, R, 1);
		else
			ans = solve(L, R - 1, 1);
	}

return dp[L][R][turn] = ans;
}

void work (int tc)
{
	memset(dp, -1, sizeof(dp));
	
	int ans, P[2];
	P[0] = solve(1, N, 1);
	P[1] = sum - P[0];

	ans = P[0] - P[1];

	printf("In game %d, the greedy strategy might lose by as many as %d points.\n", tc, ans);
}

int main ()
{
	int tc = 0;

	while (cin >> N)
	{
		if (N == 0)			return 0;

		read ();
		work (++ tc);
	}

return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll n = 2 * 1e3 + 5, INF = LLONG_MAX;

int N, M;
ll A[n], B[n], dp[n][n][2];

void read () {
	cin >> M >> N;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];

	for (int i = 1; i <= N; i ++)
		cin >> B[i];
}

ll solve (int i, int j, int turn) {
	if (i == N && j == N)
		return 0;
	if (i > N || j > N)
		return INF;
	if (dp[i][j][turn] != -1)
		return dp[i][j][turn];

	ll ans = INF, turns, pos[2];

	if (turn == 0){
		pos[0] = A[i];		pos[1] = (pos[0] + M / 2) % M;
	} else {
		pos[1] = B[j];		pos[0] = (pos[1] + M / 2) % M;
	}

	if (i < N) {
		turns = min (abs (A[i + 1] - pos[0]), abs (M - abs (A[i + 1] - pos[0])));
		ans = min (ans, solve (i + 1, j, 0) + turns);
	}

	if (j < N) {
		turns = min (abs (B[j + 1] - pos[1]), abs (M - abs (B[j + 1] - pos[1])));
		ans = min (ans, solve (i, j + 1, 1) + turns);
	}

	dp[i][j][turn] = ans;

return dp[i][j][turn];
}


void work ()
{
	memset (dp, -1, sizeof(dp));

	A[0] = 0;			B[0] = M / 2;
	ll ans = solve (0, 0, 0);
	cout << ans << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);			cout.tie(0);

	read ();
	work ();

return 0;
}
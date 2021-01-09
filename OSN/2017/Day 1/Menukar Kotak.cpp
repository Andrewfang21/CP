#include<bits/stdc++.h>
using namespace std;

const int N = 205;
const int K = 2000;

int n;
int dp[2][N][K], candy[N];
long long k;
vector<int> person;

void read() {
	string subs;
	cin >> subs;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++) {
		char c;
		cin >> c;
		candy[i] = c - '0';
	}
	
	for (int i = 1; i <= n; i ++) {
		char c;
		cin >> c;
		if (c == '1')
			person.push_back(i);
	}
}

void solve() {
	const int MAKS = 9 * n;
	memset(dp, -1, sizeof(dp));
	
	for (int candy_pos = 0; candy_pos <= n; candy_pos ++)
		dp[0][candy_pos][0] = dp[1][candy_pos][0] = 0;

	for (int person_pos = 0; person_pos < person.size(); person_pos ++) {
		for (int candy_pos = 1; candy_pos <= n; candy_pos ++) {
			for (int profit = 0; profit <= MAKS; profit ++) {
				dp[person_pos & 1][candy_pos][profit] = dp[person_pos & 1][candy_pos - 1][profit];
				if (profit - candy[candy_pos] >= 0) {
					if (dp[(person_pos + 1) & 1][candy_pos - 1][profit - candy[candy_pos]] != -1) {
						if (dp[person_pos & 1][candy_pos][profit] != -1)
							dp[person_pos & 1][candy_pos][profit] = min(
								dp[(person_pos + 1) & 1][candy_pos - 1][profit - candy[candy_pos]] + abs(candy_pos - person[person_pos]),
								dp[person_pos & 1][candy_pos][profit]
							);
						else
							dp[person_pos & 1][candy_pos][profit] = dp[(person_pos + 1) & 1][candy_pos - 1][profit - candy[candy_pos]] + abs(candy_pos - person[person_pos]);
					}
				}
			}
		}
	}

	int res = 0;
	for (int profit = 0; profit <= MAKS; profit ++) {
		if (dp[(person.size() + 1) & 1][n][profit] <= k && dp[(person.size() + 1) & 1][n][profit] != -1)
			res = profit;
	}

	printf("%d\n", res);
}

int main() {
	ios_base::sync_with_stdio(false);
	read();
	solve();

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 105, K = 25, MAX_STATE = 5000;

int n, k, Smask;
int attack[K], dp[N][MAX_STATE];

map<int, int> toIndex, toMask;
vector<int> trans[MAX_STATE];
vector<vector<int>> battle;

void read() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 4; i ++) {
		int x;
		scanf("%d", &x);
		x --;
		Smask |= (1 << x);
	}

	for (int i = 0; i < k; i ++) {
		char buff[K];
		scanf("%s", buff);

		int mask = 0;
		for (int j = 0; j < k; j ++) {
			if (buff[j] == '1')
				mask |= (1 << j);
		}
		attack[i] = mask;
	}
}

int fight(vector<int> enemy, int mask) {
	int res = 0;
	for (int i = 0; i < enemy.size(); i ++) {
		if (enemy[i] == 0)
			continue;

		for (int j = 0; j < k; j ++) {
			bool isOff = (mask & (1 << j)) == 0;
			if (isOff)
				continue;

			bool canWin = (attack[j] & (1 << i)) != 0;
			if (canWin) {
				res += enemy[i];
				break;
			}
		}
	}

	return res;
}

int solve(int pos, int maskIdx) {
	if (pos >= battle.size())
		return 0;
	if (dp[pos][maskIdx] != -1)
		return dp[pos][maskIdx];

	int mask = toMask[maskIdx];
	int res = fight(battle[pos], mask);
	int nextRes = INT_MIN;

	for (int n : trans[maskIdx]) {
		nextRes = max(nextRes, solve(pos + 1, n));
	}

	return dp[pos][maskIdx] = res + nextRes;
}

void buildTrans() {
	for (int i = 0; i < toMask.size(); i ++) {
		int mask = toMask[i];
		trans[i].push_back(i);

		for (int j = 0; j < k; j ++) {
			bool isOff = (mask & (1 << j)) == 0;
			if (isOff)
				continue;

			int removed = mask ^ (1 << j);
			for (int l = 0; l < k; l ++) {
				bool isOn = (removed & (1 << l)) != 0;
				if (isOn)
					continue;

				int nextMask = removed | (1 << l);
				if (nextMask == mask)
					continue;
				int idx = toIndex[nextMask];
				trans[i].push_back(idx);
			}
		}
	}
}

void solve() {
	int cnt = 0;
	for (int mask = 0; mask < (1 << k); mask ++) {
		if (__builtin_popcount(mask) != 4)
			continue;
		toIndex[mask] = cnt;
		toMask[cnt] = mask;
		cnt ++;
	}

	battle.push_back(vector<int>(k, 0));
	while (n --) {
		int a, b;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			b --;
			battle.back()[b] ++;
		}
		else battle.push_back(vector<int>(k, 0));
	}

	buildTrans();

	memset(dp, -1, sizeof(dp));
	int res = solve(0, toIndex[Smask]);
	printf("%d\n", res);
}

int main() {
	read();
	solve();

	return 0;
}
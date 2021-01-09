#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
const int K = 30;

int n, r, juri, bonus;
int cnt[N], score[K][2];
bool used[K];
char movement[K][2];
 
void process(int x) {
	int tmp[x + 5];
	memset(tmp, 0, sizeof(tmp));

	bool has = false;
	for (int i = 1; i < x; i ++)
		tmp[i] = score[i][1];

	int sum = 0;
	for (int i = 1; i < x; i ++) {
		if (i > 1) {
			if (movement[i - 1][1] == 'L')
				tmp[i] /= 2;
			else if (movement[i - 1][1] == 'P')
				tmp[i] *= 2;
			else if (movement[i - 1][1] == 'Y')
				has = true;
			if (has)	tmp[i] += bonus;
		}

		sum += tmp[i];
	}

	cnt[sum] ++;
}

void permute(int l, int n, int r) {
	if (l > r)
		process(l);
	else {
		for (int i = 1; i <= n; i ++) {
			if (used[i])
				continue;

			used[i] = true;
			movement[l][1] = movement[i][0];
			score[l][1] = score[i][0];

			permute(l + 1, n, r);
			used[i] = false;
		}
	}
}

void read() {
	string str;
	getline(cin, str);
	cin >> n >> r >> bonus >> juri;
	for (int i = 1; i <= n; i ++)
		cin >> score[i][0] >> movement[i][0];
}

void solve() {
	memset(used, false, sizeof(used));
	memset(cnt, 0, sizeof(cnt));

	permute(1, n, r);

	while (juri --) {
		int query;
		cin >> query;
		if (query > 21000)
			puts("0");
		else {
			int res = 0;
			for (int j = query + 1; j <= 21000; j ++)
				res += cnt[j];
			cout << res << "\n";
		}		
	}
}

int main() {
	read();
	solve();

	return 0;
}
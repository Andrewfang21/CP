#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, TC;
char petak[N][N];

void draw(int row, int len) {
	if (row > (n + 1) / 2)
		return;

	for (int i = row; i <= row + len - 1; i ++) {
		petak[row][i] = '#';
		petak[row + len - 1][i] = '#';
	}

	for (int j = row; j <= row + len - 1; j ++) {
		petak[j][row] = '#';
		petak[j][row + len - 1] = '#';
	}

	draw(row + 2, len - 4);
}

void solve(int tc) {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			petak[i][j] = '.';

	draw(1, n);

	cout << "Kasus #" << tc << ":\n";
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			cout << petak[i][j];
		cout << "\n";
	}

	if (tc != TC)
		cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> TC;

	for (int i = 1; i <= TC; i ++)
		solve(i);

return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5, k = 25;

int N;
int sparse[n][k], logg[n], pangkat[k], res[n];

void read () {
	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> sparse[i][0];
}

void build_sparse () {
	int power = 1;
	for (int j = 1; j < 17; j ++) {
		for (int i = 0; i < N; i ++) {
			if (i + power >= N)		break;
			sparse[i][j] = max(sparse[i][j - 1], sparse[i + power][j - 1]);
		}
		power *= 2;
	}
}

int query (int L, int R) {
	if (L > R)		return 0;
	int K = logg[R - L + 1];

return max(sparse[L][K], sparse[R - pangkat[K] + 1][K]);
}

void work (int tc) {
	memset(res, 0, sizeof(res));
	build_sparse ();

	for (int i = 0; i < N; i ++ ) {
		int L, R, up, low;

		up = low = 0;

		L = 1;			R = i;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (query(i - mid, i - 1) < sparse[i][0]) {
				low = mid;
				L = mid + 1;
			}
			else	R = mid - 1;
		}

		L = i + 1;		R = N - 1;
		while (L <= R) {
			int mid = (L + R) / 2;
			if (query(i + 1, mid) < sparse[i][0]) {
				up = mid - i;
				L = mid + 1;
			}
			else	R = mid - 1;
		}

		res[i] = up + low;
	}

	cout << "Kasus #" << tc << ": ";
	for (int i = 0; i < N; i ++) {
		if (i == N - 1)
			cout << res[i] << "\n";
		else
			cout << res[i] << " ";
	}
}

void precompute () {
	memset(pangkat, 0, sizeof(pangkat));
	memset(logg, -1, sizeof(logg));

	logg[1] = 0;
	logg[2] = 1;
	for (int i = 2; i <= 100000; i *= 2) {
		logg[i] = logg[i / 2] + 1;
	}

	int MAXX = 0;
	for (int i = 1; i <= 100000; i ++) {
		logg[i] = max(logg[i], MAXX);
		MAXX = logg[i];
	}

	pangkat[0] = 1;
	for (int i = 1; i <= 20; i ++) {
		pangkat[i] = pangkat[i - 1] * 2;
	}
}

int main () {
	ios_base::sync_with_stdio(false);

	precompute ();
	int TC;			cin >> TC;

	for (int i = 1; i <= TC; i ++) {
		read ();
		work (i);
	}
return 0;
}
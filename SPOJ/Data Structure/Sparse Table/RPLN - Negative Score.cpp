#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define LL long long
using namespace std;

const int n = 1e5 + 5, k = 25;

int N, Q;
LL sparse[n][k], logg[n], pangkat[k];

void read () {
    cin >> N >> Q;
    for (int i = 0; i < N; i ++) {
 		cin >> sparse[i][0];
    }   
}

void build_sparse () {
    int power = 1;

    for (int j = 1; j < 17; j ++) {
        for (int i = 0; i < N; i ++) {
            if (i + power >= N)       break;
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + power][j - 1]);  
        }
        power *= 2;   
    }
}

LL query (int L, int R) {
	int len = logg[R - L + 1];

return min(sparse[L][len], sparse[R - pangkat[len] + 1][len]);
}

void work (int tc) {
	build_sparse();
	// cout << sparse[1][0] << "TES|n";

	cout << "Scenario #" << tc << ":\n";
	while (Q --) {
		int L, R;
		cin >> L >> R;

		LL res = query(L - 1, R - 1);
		cout << res << "\n";
	}
}

void precompute () {
	logg[1] = 0;
	logg[2] = 1;

	for (int i = 2; i <= 100000; i *= 2)
		logg[i] = logg[i / 2] + 1;

	LL MAXX = 0;
	for (int i = 1; i <= 100000; i ++) {
		logg[i] = max(MAXX, logg[i]);
		MAXX = logg[i];
	}

	pangkat[0] = 1;
	for (int i = 1; i < 20; i ++) {
		pangkat[i] = pangkat[i - 1] * 2;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
//	cin.tie(0);				cout.tie(0);
	precompute ();

	int TC;		cin >> TC;
	for (int i = 1; i <= TC; i ++) {
		read ();
		work (i);
	}
return 0;
}
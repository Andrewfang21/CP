#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 5e6 + 5;

int A, N, M, set_max;
int total[n];

void read () {
	memset(total, 0, sizeof(total));
	cin >> N >> M;

	set_max = -1;
	for (int i = 1; i <= N; i ++) {
		cin >> A;
		set_max = max(set_max, A);

		total[A] ++;
	}
}

void work () {
	LL base = 1, res = -1;

	while (base <= set_max) {
		LL p = 1, curr_sum = 0;

		while (base * p <= 5e6) {
			int curr_val = base * p;

			if (total[curr_val] != 0)
				curr_sum += total[curr_val];
			p ++;
		}
//		cout << base << "  " << curr_sum << "\n";

		if (curr_sum >= M)
			res = max(res, base);

		base ++;
	}
	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}
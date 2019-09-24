#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int x[N], y[N];

vector<int> A[N];

void read () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &x[i], &y[i]);
		A[max(0, x[i] - y[i])].push_back(i);
	}
}

void solve (int tc) {
	int res = 0;
	for (int i = 0; i < N; i ++) {
		if (A[i].empty())		continue;

		int pos = i, bound = N;
		while (true) {
			for (int next : A[pos]) {
				bound = min(bound, x[next] + y[next]);
			}

			if (bound > pos) {
				pos ++;
			} else break;
		}		

		i = bound;
		res ++;
	}

	for (int i = 0; i < N; i ++)
		A[i].clear();

	printf("Kasus #%d: %d\n", tc, res);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve (i);
	}

return 0;
}
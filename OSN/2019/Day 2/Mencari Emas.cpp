#include<bits/stdc++.h>
using namespace std;

const int N = 4;

int n, m, q;

struct state {
	int x, y;
};

int ask(state query) {
	printf("? %d %d\n", query.x, query.y);
	fflush(stdout);

	int ans;
	scanf("%d", &ans);

return ans;
}

bool inside(int i, int j) {return (i >= 1 && i <= n && j >= 1 && j <= m);}

int main () {
	scanf("%d %d %d", &n, &m, &q);

	state query[N] = {{1, 1}, {1, m}, {n, 1}, {n, m}};
	int resp[N];
	for (int i = 0; i < N; i ++) {
		resp[i] = ask(query[i]);
	}

	int x[2], y[2];

	// First Case
	x[0] = (resp[0] + resp[1] + 3 - m) / 2;
	y[0] = resp[0] - x[0] + 2;

	x[1] = (2 * n + m - 1 - resp[2] - resp[3]) / 2;
	y[1] = resp[2] - n + 1 + x[1];

	if (inside(x[0], y[0]) && inside(x[1], y[1])) {
		int ans = ask(state{x[0], y[0]});
		if (ans == 0) {
			printf("! %d %d %d %d\n", x[0], y[0], x[1], y[1]);
			fflush(stdout);
	
			return 0;
		}
		else {
			// Second Case
			x[0] = (resp[0] - resp[2] + n + 1) / 2;
			y[0] = resp[0] + 2 - x[0];

			x[1] = (resp[1] - resp[3] + n + 1) / 2;
			y[1] = x[1] - 1 + m - resp[1];
		}
	} else {
		// Second Case
		x[0] = (resp[0] - resp[2] + n + 1) / 2;
		y[0] = resp[0] + 2 - x[0];

		x[1] = (resp[1] - resp[3] + n + 1) / 2;
		y[1] = x[1] - 1 + m - resp[1];	
	}

	printf("! %d %d %d %d\n", x[0], y[0], x[1], y[1]);
	fflush(stdout);

return 0;
}
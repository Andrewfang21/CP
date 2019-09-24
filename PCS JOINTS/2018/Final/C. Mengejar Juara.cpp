#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9 + 7;

int n, v;
int d[N], s[N];

vector<int> V[2];

void read () {
	scanf("%d %d", &n, &v);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &d[i], &s[i]);
	}
}

int query (int target, int idx) {
	int l, r;
	l = 0, r = V[idx].size() - 1;

	int res = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (V[idx][mid] <= target) {
			res = mid;
			l = mid + 1;
		} else r = mid - 1; 
	}

return res + 1;
}

void solve () {
	int need, currRank = 1;
	for (int i = 1; i <= n; i ++) {
		if (d[i] < 0) {
			if (s[i] <= v)
				need = INF;
			else {
				need = ceil( (double) d[i] / (double) (v - s[i]));

				if (v * need == d[i] + s[i] * need)
					need ++;
			}

			if (need != INF) {
				V[0].push_back(need);
			}

		} else {
			currRank ++;

			if (s[i] >= v) 
				need = INF;
			else {
				need = ceil( (double) d[i] / (double) (v - s[i]));
			}

			if (need != INF) {
				V[1].push_back(need);
			}
		}
	}

	sort(V[0].begin(), V[0].end());
	sort(V[1].begin(), V[1].end());

	int Q;
	scanf("%d", &Q);

	while (Q --) {
		int currTime;
		scanf("%d", &currTime);

		int bef, aft;
		bef = query(currTime, 0);
		aft = query(currTime, 1);

		int res = currRank + bef - aft;
		printf("%d\n", res);
	}
}

int main () {
	read ();
	solve ();

return 0;
}
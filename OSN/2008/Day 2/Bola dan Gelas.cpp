#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct cup {
	int origin;
} A[N];


int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i ++)
		A[i].origin = i;

	while (m --) {
		int x, y;
		scanf("%d %d", &x, &y);
		swap(A[x], A[y]);
	}

	int q;
	scanf("%d", &q);

	while (q --) {
		int x;
		scanf("%d", &x);

		printf("%d\n", A[x].origin);
	}

return 0;
}
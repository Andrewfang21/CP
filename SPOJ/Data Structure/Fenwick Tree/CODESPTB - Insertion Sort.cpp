#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5;

int n;
int A[N], BIT[N];

void read() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &A[i]);
}

void update(int pos) {
	while (pos < N) {
		BIT[pos] ++;
		pos += (pos & -pos);
	}
}

ll query(int pos) {
	ll res = 0;
	while (pos > 0) {
		res += BIT[pos];
		pos -= (pos & -pos);
	}

return res;
}

void solve() {
	memset(BIT, 0, sizeof(BIT));

	ll res = 0;
	for (int i = n; i >= 1; i --) {
		res += query(A[i] - 1);
		update(A[i]);
	}

	printf("%lld\n", res);
}

int main() {

	int tc;
	scanf("%d", &tc);

	while (tc --) {
		read();
		solve();
	}

return 0;
}
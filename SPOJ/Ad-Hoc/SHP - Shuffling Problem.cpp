#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
int A[N], pos[N];

void read() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &A[i]);
		pos[A[i]] = i;
	}
}

void solve() {
	for (int i = 0; i < n; i ++) {
		int largest = n - i;
		int idx_largest = pos[largest];
		int now = A[i];

		if (k == 0)
			break;

		if (largest != now) {
			swap(A[i], A[idx_largest]);
			pos[largest] = i;
			pos[now] = idx_largest;

			k --;
		}
	}

	if (k != 0 && k % 2 == 1) {
		swap(A[n - 1], A[n - 2]);
	}

	for (int i = 0; i < n; i ++)
		printf("%d%c", A[i], i == n - 1 ? '\n' : ' ');
}

int main() {
	read();
	solve();

return 0;
}
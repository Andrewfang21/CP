#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k;
int A[N];

void read() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 2 * n; i ++)
		scanf("%d", A + i);
}

void solve() {
	bool canMake = true;
	sort(A, A + 2 * n);

	for (int i = 0; i < 2 * n; i += 2) {
		if (A[i + 1] - A[i] > k) {
			canMake = false;
			break;
		}
	}

	printf("%s\n", canMake ? "Ya" : "Tidak");
}

int main() {
	read();
	solve();

return 0;
}
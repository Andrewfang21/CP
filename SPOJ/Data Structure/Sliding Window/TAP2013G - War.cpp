#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int A[N], B[N];

void read() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> A[i];
	for (int i = 0; i < n; i ++)
		cin >> B[i];
}

void solve() {
	sort(A, A + n + 1, greater<int>());
	sort(B, B + n + 1, greater<int>());

	int res = 0;
	int aLeft, bLeft, bRight;

	aLeft = bLeft = 0, bRight = n - 1;
	while (bLeft <= bRight) {
		if (A[aLeft] >= B[bLeft])
			aLeft ++, bRight --;
		else
			aLeft ++, bLeft ++, res ++;
	}

	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	read();
	solve();

return 0;
}
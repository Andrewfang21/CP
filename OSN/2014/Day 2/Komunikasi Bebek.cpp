#include<bits/stdc++.h>
using namespace std;

const int N = 6000;

int n;
int A[N];
bool exists[N];

void read() {
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> A[i];
		A[i] += 2500;
		exists[A[i]] = true;
	}
}

void solve() {
	if (n <= 2) {
		puts("0");
		return;
	}

	int res = n - 2;
	int tmp = 0;
	for (int i = 0; i < n; i ++) {
		for (int step = 1; step < 5000; step ++) {
			int rem = n;
			int curr = 0;
			for (int j = A[i]; j <= 5000; j += step) {
				if (exists[j])
					rem --;
				else
					curr ++;

				tmp = rem + curr;
				res = min(res, tmp);
			}
		}
	}

	cout << res << "\n";
}

int main() {
	read();
	solve();

	return 0;
}
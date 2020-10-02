#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
char A[N];

void read() {
	scanf("%d", &n);
	scanf("%s", A);
}

void solve() {
	vector<int> v;
	for (int i = 0; i < n; i ++) {
		if (A[i] == '0')
			v.push_back(i);
	}

	int l = 0;
	int r = n;

	while (l < r) {
		int mid = (l + r) / 2;
		bool flag = true;
		int pos = 0;

		for (int x : v) {
			while (pos < n && A[pos] == '0')
				pos ++;

			int sum = 0;
			if (pos < x) {
				sum += x - pos;
				pos = x + 1;
			}

			if (sum > mid) {
				flag = false;
				break;
			}

			if (pos == x + 1) {
				int rem = mid - sum;
				while (pos < n && rem > 0 && A[pos] == '1') {
					pos ++;
					sum ++;
					rem --;
				}				
			}

			if (sum > mid) {
				flag = false;
				break;
			}
		}

		if (pos != n)
			flag = false;

		if (flag)
			r = mid;
		else
			l = mid + 1;
	}

	printf("%d\n", l);
}

int main() {
	read();
	solve();

	return 0;
}
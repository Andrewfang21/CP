#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N = 1e5 + 5;

int n;

struct state {
	int left, right;
}A[N];

bool cmp (state lhs, state rhs) {
	if (lhs.left == rhs.left)
		return lhs.right < rhs.right;

return lhs.left < rhs.left;
}

void read () {
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> A[i].left >> A[i].right;
}

void solve () {
	sort(A, A + n, cmp);

	int currLeft, currRight;
	currLeft = currRight = 0;

	ll res = 0;
	for (int i = 0; i < n; i ++) {
		if (A[i].left > currRight) {
			if (i != 0) {
				ll totNum = currRight - currLeft + 1;
				res = res + (totNum * (currLeft + currRight)) / 2;
			}

			currLeft = A[i].left;
			currRight = A[i].right;
		}

		currRight = max(currRight, A[i].right);

		if (i == n - 1) {
			ll totNum = currRight - currLeft + 1;
			res = res + (totNum * (currLeft + currRight)) / 2;
		}
	}

	cout << res << "\n";	
}


int main () {
	ios_base::sync_with_stdio(false);

	read ();
	solve ();

return 0;
}
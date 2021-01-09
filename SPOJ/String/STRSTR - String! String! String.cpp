#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int Z[2 * N];
string s[N];

void read() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
}

int get(string s, string t) {
	string str = t + '$' + s;
	int pos = t.length() + 1;
	int n = str.length();
	int l, r;
	l = r = 0;
	for (int k = 1; k < n; k ++) {
		if (k > r) {
			l = r = k;
			while (r < n && str[r] == str[r - l])
				r ++;
			Z[k] = r - l;
			r --;
		} else {
			int k1 = k - l;
			if (Z[k] < r - k + 1)
				Z[k] = Z[k1];
			else {
				l = k;
				while (r < n && str[r] == str[r - l])
					r ++;
				Z[k] = r - l;
				r --;
			}
		}
	}

	return Z[pos];
}

void solve(int tc) {
	vector<int> res(n, INT_MIN);
	for (int i = 0; i < n; i ++) {
		int curr = 0;
		int choose = i;
		for (int j = 0; j < n; j ++) {
			if (i == j)
				continue;

			int sim = get(s[i], s[j]);
			if (sim > curr) {
				choose = j + 1;
				curr = sim;
			}
		}
		res[i] = (curr != 0 ? choose : -1);
	}

	printf("Case %d:\n", tc);
	for (int r : res)
		printf("%d\n", r);
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i ++) {
		read();
		solve(i);
	}

	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 105;

int n, m;
ll len[N];

char A[N], C[N];
string B[N];

void read () {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> A[i];

	for (int i = 1; i <= m; i ++) 
		cin >> C[i] >> B[i];
}

void solve () {
	for (int i = 0; i < 26; i ++)
		len[i] = 1;

	for (int i = m; i >= 1; i --) {
		ll tot = 0;

		for (int j = 0; j < B[i].length(); j ++)
			tot += len[B[i][j] - 'A'];

		len[C[i] - 'A'] = tot;
	}

	ll res = 0;
	for (int i = 1; i <= n; i ++)
		res += len[A[i] - 'A'];

	cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}
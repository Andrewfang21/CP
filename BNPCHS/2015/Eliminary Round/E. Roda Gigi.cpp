#include<bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;

int N;
char A[n], S[2][n], dir[2] = {'L', 'R'};

void read () {
	cin >> N;
	for (int i = 0; i < N; i ++)
		cin >> A[i];
}

void solve (int tc) {
	for (int i = 0; i < N; i ++) {
		S[0][i] = dir[i % 2];
		S[1][i] = dir[(i + 1) % 2];
	}

	int res[2] = {0, 0};
	for (int k = 0; k < 2; k ++) {
		for (int i = 0; i < N; i ++) {
			if (A[i] != S[k][i])
				res[k] ++;;
		}
	}

	cout << "Kasus #" << tc << ": " << min(res[0], res[1]) << "\n";  
}

int main () {
	int TC;		cin >> TC;

	for (int i = 1; i <= TC; i ++) {
		read ();
		solve (i);
	}

return 0;
}
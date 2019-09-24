#include<bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;
	for (int i = 1; i <= TC; i ++) {
		int N, A, B, K;
		cin >> N >> A >> B >> K;

		N = N + (B - A) * K;
		cout << "Kasus #" << i << ": " << N << "\n";
	}
return 0;
}
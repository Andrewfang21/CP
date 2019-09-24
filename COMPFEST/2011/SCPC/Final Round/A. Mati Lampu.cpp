#include<bits/stdc++.h>
using namespace std;

const int n = 1e3 + 5;

int TC, N;
char A[n];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> TC;
	while (TC --) {
		cin >> N;

		bool foundP, foundN;
		foundN = foundP = false;

		for (int i = 1; i <= N; i ++) {
			cin >> A[i];

			if (A[i] == 'P')
				foundP = true;
			if (A[i] == 'N')
				foundN = true;
		}

		if (foundP) {
			if (foundN)
				cout << "tidak mungkin mati lampu\n";
			else
				cout << "mungkin mati lampu\n";
		} else
			cout << "tidak mati lampu\n";
	}

return 0;
}
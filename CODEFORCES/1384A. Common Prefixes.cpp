#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int A[N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
		scanf("%d", &A[i]);
}

char getNext(char c) {
	return (c == 'b' ? 'z' : c - 1);
}

void solve() {
	vector<string> res;
	char trash = 'z';

	for (int i = 0; i < n; i ++) {
		string curr = "";

		if (i > 0) {
			if (A[i] < A[i - 1]) {
				curr = res[i - 1].substr(0, A[i - 1]);
				for (int j = curr.length() + 1; j <= A[i]; j ++) {
					curr += trash;
				}
				if (curr == "")
					curr = trash;

				trash = getNext(trash);
			} else {
				curr = res[i - 1].substr(0, A[i - 1]);
				if (curr == "") {
					curr = trash;
					trash = getNext(trash);
				}
			}

			if (curr.length() < A[i]) {
				for (int j = curr.length() + 1; j <= A[i]; j ++)
					curr += trash;
				trash = getNext(trash);
			}

		} else {
			for (int j = 0; j < A[i]; j ++) 
				curr += 'a';

			if (curr == "") {
				curr = trash;
				trash = getNext(trash);
			}
		}

		res.push_back(curr);
	}

	string curr = res.back().substr(0, A[n - 1]);
	for (int i = curr.length() + 1; i < A[n - 1]; i ++)
		curr += trash;
	if (curr == "") {
		curr = trash;
	}
	res.push_back(curr);

	for (string r : res) {
		cout << r << "\n";
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		read();
		solve();
	}

return 0;
}
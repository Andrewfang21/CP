#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int lps[N];
string S, X;

vector<int> V;

void generateLPS() {
	int k = 0;
	for (int i = 1; i < X.length(); i ++) {
		while (k > 0 && X[i] != X[k])
			k = lps[k - 1];

		if (X[i] == X[k])
			k ++;

		lps[i] = k;
	}
}

void solve(int tc) {
	cin >> S >> X;

	generateLPS();

	for (int i = 0, k = 0; i < S.length(); i ++) {
		while (k > 0 && S[i] != X[k])
			k = lps[k - 1];

		if (S[i] == X[k])
			k ++;

		if (k == X.length()) {
			V.push_back(i - k + 2);
			k = lps[k - 1];
		}
	}

	sort(V.begin(), V.end());
	if (V.empty())
		cout << "Not Found\n"; 
	else {
		cout << V.size() << "\n";
		for (int i = 0; i < V.size(); i ++) {
			i == V.size() - 1 ? cout << V[i] << "\n" : cout << V[i] << " ";
		}
	}

	if (tc != 0)
		puts("");

	V.clear();
	memset(lps, 0, sizeof(lps));
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;

	while (tc --) {
		solve(tc);
	}

return 0;
}
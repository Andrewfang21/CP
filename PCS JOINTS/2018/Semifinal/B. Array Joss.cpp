#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n;
string S[2] = {"TIDAK", "YA"};

map<int, int> cnt;

int main () {
	ios_base::sync_with_stdio(false);

	cin >> n;

	int totNum = 0;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;

		if (cnt[x] == 0) 
			totNum ++;

		cnt[x] ++;
	}

	char op;
	cin >> op;

	vector<int> pos, neg;
	for (int i = 1; i <= N; i ++) {
		if (op == 'x' && i == 1)
			continue;

		if (cnt[i] != 0) 
			pos.push_back(i);
	}

	for (int i = -1; i >= -N; i --) {
		if (op == 'x' && i == -1)
			continue;

		if (cnt[i] != 0)
			neg.push_back(i);
	}

	bool res = false;
	if (op == '+' || op == '-') {
		if (pos.empty() && neg.empty())
			res = true;
	}
	else if (op == '/') {
		if (cnt[0] == 0) {
			if (pos.size() == 1 && neg.size() == 1 && cnt[0] == 0) {
				if (pos[0] == 1 && neg[0] == -1)
					res = true;
			}
			else if (pos.size() == 1 && neg.empty()) {
				if (pos[0] == 1)
					res = true;
			}			
		}
	}
	else {
		if (pos.empty() && neg.empty()) {
			if (cnt[-1] == 0 || cnt[-1] != 0 && cnt[1] != 0)
				res = true;
		}
	}

	cout << S[res] << "\n";

return 0;
}
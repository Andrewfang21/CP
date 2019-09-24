#include<bits/stdc++.h>
using namespace std;

const int n = 5005;

int main () {
	ios_base::sync_with_stdio(false);
	int TC;		cin >> TC;

	for (int tc = 1; tc <= TC; tc ++) {
		int N;		cin >> N;

		string s[n];
		for (int i = 1; i <= N; i ++) {
			cin >> s[i];
			sort(s[i].begin(), s[i].end());
		}
		
		sort (s + 1, s + N + 1);
		
		int res = 0, currVal = 1;
		vector<int> V;

		for (int i = 1; i <= N; i ++) {
			if (s[i] == s[i - 1])
				currVal ++;
			else {
				V.push_back(currVal);
				currVal = 1;
			}
		}
		if (currVal != 0)		V.push_back(currVal);
		
		for (int i = 0; i < V.size(); i ++)
			res += (V[i] * (V[i] - 1) / 2);
			
		cout << "Kasus #" << tc << ": " << res << "\n";
	}
}
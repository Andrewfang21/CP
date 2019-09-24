#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 105;

int N, K;
int res[n];
bool taken[n], found;

vector<int> vec[n];

void read () {
	cin >> N >> K;
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= i; j ++) {
			int X;		cin >> X;
			vec[i].push_back(X);
		}
}

void dfs (int i) {
	if (i > N)		found = true;
	if (found)		return;

	for (int it = 0; it < vec[i].size(); it ++) {
		int now = vec[i][it];

		if (found)		return;		
		if (taken[now])		continue;

		taken[now] = true;
		res[i] = now;

		dfs(i + 1);
		taken[now] = false;
	}
}

void work (int tc) {
	for (int i = 1; i <= N; i ++)		sort(vec[i].begin(), vec[i].end());

	found = false;
	dfs(1);
	
	cout << "Kasus #" << tc << ":";
	for (int i = 1; i <= N; i ++) 
		cout << " " << res[i];
	cout << "\n";

	for (int i = 1; i <= N; i ++)		vec[i].clear();
}

int main () {
	ios_base::sync_with_stdio(false);
	
	int TC;		cin >> TC;
	for (int i = 1; i <= TC; i ++) {
		read ();
		work (i);
	}
return 0;
}
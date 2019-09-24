#include<bits/stdc++.h>
using namespace std;

int N, M, totalCount;

vector<int> faktor, temp;
vector<vector<int> > pref;

void read() {
	cin >> N >> M;
	
	for (int i = 0; i <= M; i ++)	temp.push_back(0);
	for (int i = 0; i <= N; i ++)	pref.push_back(temp);

	totalCount = 0;
	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= M; j ++) {
			char maze;		cin >> maze;
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + maze - '0';

			if (maze == '1')	totalCount ++;
		}
	}
}

void solve() {
	for (int i = 1; i <= totalCount; i ++) {
		if (totalCount % i == 0)
			faktor.push_back(i);
	}

	int res = INT_MAX;
	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= M; j ++) {
			for (int k = 0; k < faktor.size(); k ++) {
				int dr, dc;
				dr = faktor[k];		dc = totalCount / dr;

				if (i + dr - 1 > N || j + dc - 1 > M)		continue;
				int currPeople = pref[i + dr - 1][j + dc - 1] - pref[i + dr - 1][j - 1] - pref[i - 1][j + dc - 1] + pref[i - 1][j - 1];

				res = min(res, totalCount - currPeople);
			}
		}
	}
	res == INT_MAX ? cout << "-1\n" : cout << res << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read();
	solve();

return 0;
}

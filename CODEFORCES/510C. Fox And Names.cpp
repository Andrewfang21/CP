#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n, vis[N], maxLength;
string s[N];

bool DAG;

vector<int> adj[N];

void read () {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];

		int currLength = s[i].length();
		maxLength = max(maxLength, currLength);
	}
}

void dfs (int pos, stack<int> &st) {
	if (!DAG)
		return;

	vis[pos] = 1;

	for (int next : adj[pos]) {
		if (vis[next] == 1) {
			DAG = false;
			return;
		} else
		if (vis[next] == 0) {
			dfs(next, st);
		}
	}

	st.push(pos);
	vis[pos] = 2;
}

void solve () {
	DAG = true;

	for (int i = 1; i < n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			// First char is same
			if (s[i][0] == s[j][0]) {
 				for (int it = 0; it < min(s[i].length(), s[j].length()); it ++) {
					if (s[i][it] != s[j][it]) {
						int u, v;
						u = s[i][it] - 'a';
						v = s[j][it] - 'a';

						adj[u].push_back(v);
						break;
					}

					if (it == min(s[i].length(), s[j].length()) - 1) {
						if (s[i] > s[j]) {
							DAG = false;
							break;
						}
					}
				}
			} else {
				int u, v;
				u = s[i][0] - 'a';
				v = s[j][0] - 'a';

				adj[u].push_back(v);
			}
		}
	}

	stack<int> st;
	memset(vis, 0, sizeof(vis));

	if (DAG) {
		for (int i = 0; i < 26; i ++) {
		if (vis[i] == 0)
			dfs(i, st);
		}
	}

	if (!DAG) {
		cout << "Impossible\n";
	} else {
		while (!st.empty()) {
			cout << char('a' + st.top());
			st.pop();
		}
		cout << "\n";
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 777777;
const int K = 6;

int s, t;
int vis[N];

const char x[] = "TBSU";
const char y[] = "BTUS";

void read() {
	string str;
	getline(cin, str);

	for (int i = 0; i < K; i ++) {
		int x;
		cin >> x;
		s = s * 10 + x;
	}
	for (int i = 0; i < K; i ++) {
		int x;
		cin >> x;
		t = t * 10 + x;
	}
}

int get(vector<int> v) {
	int res = 0;
	for (int x : v)
		res = res * 10 + x;

	return res;
}

void rotate(vector<int> &v, char dir) {
	vector<int> tmp(K);
	for (int i = 0; i < K; i ++)
		tmp[i] = v[i];

	if (dir == 'T') {
		v[1] = tmp[3];
		v[0] = tmp[5];
		v[5] = tmp[1];
		v[3] = tmp[0];
	} else if (dir == 'B') {
		v[0] = tmp[3];
		v[1] = tmp[5];
		v[5] = tmp[0];
		v[3] = tmp[1];
	} else if (dir == 'S') {
		v[1] = tmp[4];
		v[4] = tmp[0];
		v[0] = tmp[2];
		v[2] = tmp[1];
	} else {
		v[4] = tmp[1];
		v[0] = tmp[4];
		v[2] = tmp[0];
		v[1] = tmp[2];
	}
}

void solve() {
	memset(vis, -1, sizeof(vis));

	queue<tuple<int,int>> q;
	q.emplace(s, 0);

	while (!q.empty()) {
		int curr, step;
		tie(curr, step) = q.front();
		q.pop();

		if (vis[curr] != -1)
			continue;

		vis[curr] = step;
		if (curr == t) {
			cout << step << "\n";
			break;
		}

		vector<int> v(K);
		for (int i = 0; i < K; i ++) {
			v[K - i - 1] = curr % 10;
			curr /= 10;
		}

		for (int i = 0; i < 4; i ++) {
			rotate(v, x[i]);
			int nxt = get(v);
			q.emplace(nxt, step + 1);
			rotate(v, y[i]);
		}
	}
}

int main() {
	read();
	solve();

	return 0;
}
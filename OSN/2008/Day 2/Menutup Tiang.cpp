#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

typedef pair<int, int> point;
vector<point> P;

double area (point a, point b, point c) {
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
}

bool isCCW (point a, point b, point c) {
	return area(a, b, c) <= 0;	
}

void read () {
	int start, finish, n, d;
	scanf("%d %d %d %d", &start, &finish, &n, &d);
	for (int i = 1; i <= n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);

		P.push_back(make_pair(x - d / 2.0, y));
		P.push_back(make_pair(x + d / 2.0, y));
	}
	P.push_back(make_pair(start, 0));
	P.push_back(make_pair(finish, 0));
}

void solve () {
	sort(P.begin(), P.end());

	stack<point> st;
	for (int i = 0; i < 3; i ++)
		st.push(P[i]);

	int pos = 3;
	while (pos < (int) P.size()) {
		if (st.size() == 1) {
			st.push(P[pos ++]);
		} else {
			point now, prev;
			now = st.top();
			st.pop();

			prev = st.top();
			st.push(now);

			if (isCCW(prev, now, P[pos])) {
				st.push(P[pos ++]);
			} else st.pop();
		}
	}

	vector<point> V;
	while (!st.empty()) {
		point now = st.top();
		st.pop();

		V.push_back(now);
	}

	reverse(V.begin(), V.end());

	double res = 0.0;
	for (int i = 0; i < V.size() - 1; i ++) {
		res += hypot(V[i + 1].first - V[i].first, V[i + 1].second - V[i].second);
	}

	printf("%.3lf\n", res);
}

int main () {
	read ();
	solve ();

return 0;
}
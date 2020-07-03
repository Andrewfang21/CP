#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 25;

int n, k;
vector<int> V;
vector<pair<int, int>> S, segments;
map<int, int> pos;

void read() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++) {
		int x;
		scanf("%d", &x);

		V.push_back(x);
		S.push_back(make_pair(x, i));
	}
}

void solve() {
	sort(S.begin(), S.end());
	for (int i = 0; i < n; i ++) {
		pos[S[i].second] = i;
	}

	int start = -1;
	int finish = -1;

	for (int i = 0; i < n; i ++) {
		if (start != -1)
			finish = max(finish, pos[i]);

		if (V[i] != S[i].first && start == -1) {
			start = i;
			finish = pos[i];
		}

		if (finish == i) {
			segments.push_back(make_pair(start, finish));
			start = finish = -1;
		}
	}

	int res = 0;
	if (segments.size() <= k) {
		for (pair<int, int> segment : segments)
			res += (segment.second - segment.first + 1);

		res += (k - segments.size());
	} else {
		vector<int> temp;
		for (int i = 1; i < segments.size(); i ++)
			temp.push_back(segments[i].first - segments[i - 1].second - 1);

		for (pair<int, int> segment : segments)
			res += (segment.second - segment.first + 1);

		sort(temp.begin(), temp.end());
		k = segments.size() - k;

		for (int i = 0; i < k; i ++)
			res += temp[i];
	}

	printf("%d\n", res);
}

int main() {
	char subs[K];
	scanf("%s", subs);

	read();
	solve();

return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, h;
int A[N], nexts[N];
long long pref[N];

pair<int, int>  seg[5 * N];
vector<tuple<int, int, int>> ranges;

struct state {
	int l, r, h;
};

void buildTree(int pos, int l, int r) {
	if (l == r) {
		seg[pos] = make_pair(A[l], l);
		return;
	}

	int mid = (l + r) / 2;
	buildTree(2 * pos, l, mid);
	buildTree(2 * pos + 1, mid + 1, r);

	if (seg[2 * pos].first == seg[2 * pos + 1].first) {
		seg[pos] = make_pair(seg[2 * pos].first, min(seg[2 * pos].second, seg[2 * pos + 1].second));
	} else {
		seg[pos] = (seg[2 * pos].first < seg[2 * pos + 1].first)
			? seg[2 * pos]
			: seg[2 * pos + 1];
	}
}

pair<int, int> query(int pos, int l, int r, int ql, int qr) {
	if (l > qr || r < ql)
		return make_pair(INT_MAX, INT_MAX);
	if (ql <= l && qr >= r)
		return seg[pos];

	int mid = (l + r) / 2;
	pair<int, int> ll = query(2 * pos, l, mid, ql, qr),
				   rr = query(2 * pos + 1, mid + 1, r, ql, qr);

   if (ll.first < rr.first)
   		return ll;
   	else if (ll.first > rr.first)
   		return rr;
   	else {
   		if (ll.second < rr.second)
   			return ll;
   		return rr;
   	}
}

void read() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &A[i]);
	}
	A[n + 1] = 0;

	memset(nexts, -1, sizeof(nexts));
	stack<int> st;
	int pos = 2;
	while (pos <= n) {
		if (A[pos] != A[pos - 1]) {
			nexts[pos - 1] = pos;
			while (!st.empty()) {
				int x = st.top();
				st.pop();
				nexts[x] = pos;
			}
		}
		else st.push(pos - 1);

		pos ++;
	}
}

void rec(int l, int r, int h) {
	if (r < l || r == -1 || l == -1)
		return;

	pair<int, int> curr = query(1, 1, n, l, r);
	if (curr.first - h > 0)
		ranges.emplace_back(l, r, curr.first - h);

	if (curr.second - 1 != -1 && curr.second - 1 >= l) {
		rec(l, curr.second - 1, curr.first);
	}
	if (r >= nexts[curr.second] && nexts[curr.second] != -1)
		rec(nexts[curr.second], r, curr.first);
}

void solve() {
	buildTree(1, 1, n);

	pair<int, int> curr = query(1, 1, n, 1, n);
	if (curr.first != 0)
		ranges.emplace_back(1, n, curr.first);
	rec(1, curr.second - 1, curr.first);
	rec(nexts[curr.second], n, curr.first);

	sort(ranges.begin(), ranges.end(), [&](tuple<int,int,int> &l, tuple<int,int,int> &r) {
		if (get<0> (l) != get<0> (r))
			return get<0>(l) < get<0>(r);
		return get<1>(l) > get<1>(r);
	});

	memset(pref, 0, sizeof(pref));
	for (int i = 0; i < ranges.size(); i ++) {
		long long l, r, h;
		tie(l, r, h) = ranges[i];
		if (i == 0)
			pref[i] = (r - l + 1) * h;
		else
			pref[i] = pref[i - 1] + (r - l + 1) * h;
	}

	int q;
	scanf("%d", &q);
	while (q --) {
		long long x;
		scanf("%lld", &x);

		int l = 0, r = ranges.size() - 1;
		int up = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (pref[mid] >= x) {
				up = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		tie(l, r, ignore) = ranges[up];
		if (up != 0)
			x -= pref[up - 1];
		x %= (r - l + 1);
		if (x == 0)
			printf("%d\n", r);
		else
			printf("%lld\n", l + x - 1);
	}
}

int main() {
	read();
	solve();

	return 0;
}
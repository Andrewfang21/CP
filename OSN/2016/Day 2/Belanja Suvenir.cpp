#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n;
int A[N];

vector<tuple<int,int>> v;
pair<int,int> x, y;

void read() {
	char s[20];
	scanf("%s", s);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &A[i]);
}

tuple<int,int,int,int> get() {
	if (v.size() <= 1)
		return make_tuple(-1,-1,-1,-1);

	int curr = get<1>(v[0]);
	for (int i = 1; i < v.size(); i ++) {
		if (curr < get<0>(v[i]))
			return make_tuple(get<0>(v[0]), get<1>(v[0]), get<0>(v[i]), get<1>(v[i]));
	}

	return make_tuple(-1,-1,-1,-1);
}

bool can(int len) {
	v.clear();

	int same = 0;
	int cnt[N];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= len; i ++) {
		cnt[A[i]] ++;
		if (cnt[A[i]] > 1)
			same ++;
	}

	int l = 1, r = len;
	while (r <= n) {
		if (same == 0)
			v.emplace_back(l, r);

		if (cnt[A[l]] > 1)
			same --;
		
		cnt[A[l]] --;
		l ++, r ++;
		if (r > n)
			break;
		cnt[A[r]] ++;
		if (cnt[A[r]] > 1)
			same ++;
	}

	tuple<int,int,int,int> tmp = get();
	int a, b, c, d;
	tie(a,b,c,d) = tmp;
	if (a == -1)
		return false;

	x = make_pair(a, b);
	y = make_pair(c, d);

	return true;
}

void solve() {
	int l = 1;
	int r = n / 2;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (can(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	printf("%d %d %d %d\n", x.first, x.second, y.first, y.second);
}

int main() {
	read();
	solve();

	return 0;
}
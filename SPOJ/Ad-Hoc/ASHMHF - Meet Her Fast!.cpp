#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 1e5 + 5;

LL N, sum;
LL pref[n];

pair<LL, LL> X[n];

void read ()
{
	cin >> N;

	sum = 0;
	for (int i = 1; i <= N; i ++)
	{
		LL A;

		cin >> A;
		X[i] = make_pair(A, i);

		sum += A;
	}
}

void work (int tc)
{
	sort (X + 1, X + N + 1);

	pref[0] = 0;
	for (int i = 1; i <= N; i ++)
		pref[i] = pref[i - 1] + X[i].first;

	pair<LL, LL> res = make_pair(LLONG_MAX, -1);
	for (int i = 1; i <= N; i ++)
	{
		LL kiri, kanan;

		kiri = i - 1;			kanan = N - i;

		LL curr_val = (X[i].first * kiri - pref[kiri]) + (pref[N] - pref[i] - kanan * X[i].first);

//		cout << curr_val << "  " << X[i].second << "\n";

		if (res.first > curr_val)
			res = make_pair(curr_val, X[i].second);
		else
		if (res.first == curr_val)
			res.second = min(res.second, X[i].second);
	}

	cout << "Case " << tc <<": " << res.second << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc ++)
	{
		read ();
		work (tc);
	}
return 0;
}
#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL n = 1e5 + 5, INF = 9 * 1e18;

LL N, M, K;
LL A[2][n], seg[2][1000 * n];

void read ()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i ++)
		cin >> A[0][i];
}

LL GET (int type, int pos, int L, int R, int QL, int QR)
{
	if (QL > R || QR < L)
	{
		if (type == 1)		return -INF;
		return INF;
	}
	if (QL <= L && QR >= R)
		return seg[type][pos];

	int mid = (L + R) / 2;

	if (type == 0)
		return	min(GET(type, 2 * pos, L, mid, QL, QR),
		   			GET(type, 2 * pos + 1, mid + 1, R, QL, QR));
	else
		return  max(GET(type, 2 * pos, L, mid, QL, QR),
			   		GET(type, 2 * pos + 1, mid + 1, R, QL, QR));
}

void build_segtree (int type, int pos, int L, int R)
{
	if (L == R)
	{
		seg[type][pos] = A[type][L];
		return;
	}

	int mid = (L + R) / 2;

	build_segtree(type, 2 * pos, L, mid);
	build_segtree(type, 2 * pos + 1, mid + 1, R);

	if (type == 0)
		seg[type][pos] = min(seg[type][2 * pos], seg[type][2 * pos + 1]);
	else
		seg[type][pos] = max(seg[type][2 * pos], seg[type][2 * pos + 1]);
}

void query (int tc)
{
	cout << "Case " << tc << ":\n";

	int Q;
	cin >> Q;

	while (Q --)
	{
		int L, R;
		cin >> L >> R;

		if (R - L + 1 >= K)
			cout << GET(1, 1, 1, M, L, R - K + 1) << "\n";
		else
			cout << "Impossible\n";
	}
}

void work (int tc)
{
	LL L, R, curr_val;

	build_segtree(0, 1, 1, N);

	M = 0;
	for (int i = 1; i <= N - K + 1; i ++)
		A[1][++ M] = GET(0, 1, 1, N, i, i + K - 1);

	// for (int i = 1; i <= M; i ++)
	// 	cout << A[1][i] << " ";
	// cout << "\n";

	build_segtree(1, 1, 1, M);
	query(tc);
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
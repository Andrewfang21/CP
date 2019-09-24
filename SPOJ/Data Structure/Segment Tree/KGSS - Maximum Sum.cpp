#include<bits/stdc++.h>
using namespace std;

const int n = 1e5 + 5;

int N, Q;
int A[n];

pair<int, int> seg[5 * n];

void build_seg (int pos, int L, int R)
{
	if (L == R)
	{
		seg[pos].first = A[L];		seg[pos].second = -1;
		return;
	}

	int mid = (L + R) / 2;

	build_seg (2 * pos, L, mid);
	build_seg (2 * pos + 1, mid + 1, R);

	vector<int> V;
	for (int i = 0; i < 2; i ++)
	{
		V.push_back(seg[2 * pos + i].first);		
		V.push_back(seg[2 * pos + i].second);
	}
	sort(V.begin(), V.end(), greater<int>() );

seg[pos] = make_pair(V[0], V[1]);
}

pair<int, int> GET (int pos, int L, int R, int QL, int QR)
{
	if (L > QR || R < QL)
		return make_pair(-1, -1);
	
	if (QL <= L && QR >= R)
		return make_pair(seg[pos].first, seg[pos].second);

	pair<int, int> temp[2];
	int mid = (L + R) / 2;

	temp[0] = GET (2 * pos, L, mid, QL, QR);
	temp[1] = GET (2 * pos + 1, mid + 1, R, QL, QR);

	vector<int> V;
	for (int i = 0; i < 2; i ++)
	{
		V.push_back(temp[i].first);		V.push_back(temp[i].second);
	}
	sort(V.begin(), V.end(), greater<int>() );

return make_pair(V[0], V[1]);
}

void update (int pos, int L, int R, int idx, int val)
{
	if (L > idx || R < idx)
		return;
	if (L == idx && R == idx)
	{
		seg[pos].first = val;
		return;
	}

	int mid = (L + R) / 2;

	update (2 * pos, L, mid, idx, val);
	update (2 * pos + 1, mid + 1, R, idx, val);

	vector<int> V;
	for (int i = 0; i < 2; i ++)
	{
		V.push_back(seg[2 * pos + i].first);		
		V.push_back(seg[2 * pos + i].second);
	}
	sort(V.begin(), V.end(), greater<int>() );

seg[pos] = make_pair(V[0], V[1]);	
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);			cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];

	build_seg (1, 1, N);

	// for (int i = 1; i < 10; i ++)
	// 	cout << i << ":   " << seg[i].first << " " << seg[i].second << "\n";

	cin >> Q;
	while (Q --)
	{
		char query;
		int A, B;

		cin >> query >> A >> B;

		if (query == 'Q')
		{
			pair<int, int>  curr_val = GET (1, 1, N, A, B);

			// cout << curr_val.first << " " << curr_val.second << "    ";
			int res = curr_val.first + curr_val.second;
			cout << res << "\n";
		}
		else
			update (1, 1, N, A, B);
	}

return 0;
}
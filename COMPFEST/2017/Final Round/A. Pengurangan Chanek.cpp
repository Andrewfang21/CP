#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 1e5 + 5;

LL N, res, temp;
LL A[n];

deque<LL> V;

int main ()
{
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i ++)
		cin >> A[i];

	res = 0;
	sort (A + 1, A + N + 1);

	if (N == 1)
		cout << A[1] << "\n";
	else
	{
		res = A[N] - A[1];

		for (int i = 2; i < N; i ++)
			res += abs(A[i]);

		cout << res << "\n";
	}

return 0;
}
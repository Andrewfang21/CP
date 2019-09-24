#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL TC, N, M;

int main ()
{
	ios_base::sync_with_stdio(false);

	cin >> TC;

	for (int tc = 1; tc <= TC; tc ++)
	{
		cin >> N;

		LL M = sqrtl(N);

		cout << "Case " << tc << ": ";

		if (M * M == N)
			cout <<"Yes\n";
		else
			cout <<"No\n";
	}
return 0;
}
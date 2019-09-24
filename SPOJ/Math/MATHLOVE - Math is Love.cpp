#include<bits/stdc++.h>
#define LL unsigned long long
using namespace std;

LL Sn, N;

int main ()
{
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC --)
	{
		cin >> Sn;

		N = sqrt(2 * Sn);

		if (N * (N + 1) == 2 * Sn)
			cout << N << "\n";
		else
			cout << "NAI\n";
	}
return 0;
}
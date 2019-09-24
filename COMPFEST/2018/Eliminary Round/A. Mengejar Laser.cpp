#include<bits/stdc++.h>
using namespace std;

int main () {
	long long N;
	cin >> N;

	long long M, res = 0;
	if (N > 0)
		M = 2 * N - 1;
	else
	if (N < 0) 
		M = 2 * abs(N);

	res = M * (M + 1) / 2;
	cout << res << "\n";

return 0;
}
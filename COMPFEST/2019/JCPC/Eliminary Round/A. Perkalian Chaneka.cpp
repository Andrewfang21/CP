#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
	ll A, B;
	cin >> A >> B;

	ll res;
	if (A % 11 == 0)
		A /= 11;
	else
		B /= 11;

	res = A * B;

	cout << res << "\n";

return 0;
}
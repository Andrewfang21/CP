#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n, k;
ll A[N], imba[N];


int main () {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++)
		cin >> A[i];
		
	sort(A + 1, A + n + 1);

	for (int i = 2; i <= n; i ++) {
		imba[i - 1] = A[i] - A[i - 1];
	}
		
	sort(imba + 1, imba + n);
	
	ll res = 0;
	for (int i = 1; i <= n - k; i ++)
		res += imba[i];
		
	cout << res <<"\n";

return 0;	
}
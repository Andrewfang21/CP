#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
string A;

void read() {
	cin >> n >> k;
	cin >> A;
}

void solve() {
	sort(A.begin(), A.end());
	cout << A[k - 1] << "\n";		
}

int main() {
	read();
	solve();

return 0;
}
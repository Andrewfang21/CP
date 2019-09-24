#include<bits/stdc++.h>
using namespace std;
 
const int n = 1e4 + 5;
 
int N;
int BIT[n], A[n], sameNumPos[n];
bool paired[n];
 
void read() {
	cin >> N;
 
	memset(sameNumPos, -1, sizeof(sameNumPos));
	for (int i = 1; i <= 2 * N; i ++) {
		cin >> A[i];
		sameNumPos[A[i]] = i;
 
	}
}
 
int query(int idx) {
	int res = 0;
	while (idx < n) {
		res += BIT[idx];
		idx += (idx & -idx);
	}
return res;
}
 
void update(int idx) {
	while (idx > 0) {
		BIT[idx] ++;
		idx -= (idx & -idx);
	}
}
 
void solve() {
	int res = 0;
 
	for (int i = 1; i <= 2 * N; i ++) {
		if (!paired[A[i]] && A[i] != A[i + 1]) {
			res += (sameNumPos[A[i]] + query(sameNumPos[A[i]]) - query(i) - i - 1);
			update(sameNumPos[A[i]]);
		}
		paired[A[i]] = true;
	}
	cout << res << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
 
	read();
	solve();
 
return 0;
}
  

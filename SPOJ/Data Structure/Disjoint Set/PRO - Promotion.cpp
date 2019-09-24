#include<bits/stdc++.h>
#define LL long long
using namespace std;

int N;
multiset<int> A;

int main () {
	ios_base::sync_with_stdio(false);

	LL res = 0;
	int TC;		cin >> TC;
	while (TC --) {
		cin >> N;
		for (int i = 1; i <= N; i ++) {
			int val;		cin >> val;
			A.insert(val);
		}

		pair<int, int> temp = make_pair(*A.begin(), *(-- A.end()));
		res += temp.second - temp.first;
		A.erase(A.begin());			A.erase(-- A.end());
	}
	cout << res << "\n";
return 0;
}
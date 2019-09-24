#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve () {
	int Q;
	cin >> Q;

	ordered_set S;

	while (Q --) {
		char tipe;
		int x;

		cin >> tipe >> x;
		if (tipe == 'I') {
			if (S.find(x) == S.end())
				S.insert(x);
		} else
		if (tipe == 'D') {
			if (S.find(x) != S.end())
				S.erase(S.find(x));
		} else
		if (tipe == 'K') {
			if (x > S.size())
				cout << "invalid\n";
			else
				cout << *(S.find_by_order(x - 1)) << "\n";
		} else {
			cout << S.order_of_key(x) << "\n";
		}
	}
}

int main () {
	solve ();

return 0;
}
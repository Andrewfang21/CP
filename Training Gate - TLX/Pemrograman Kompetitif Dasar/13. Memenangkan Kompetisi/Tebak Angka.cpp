#include<bits/stdc++.h>
using namespace std;

int getAns (int num) {
	cout << num << endl;

	string resp[2];
	cin >> resp[0];

	if (resp[0][0] == 's')
		return 0;

	cin >> resp[1];
	if (resp[1][0] == 'b')
		return 1;

return -1;
}

void solve () {
	int l, r;
	cin >> l >> r;

	while (l <= r) {
		int mid = (l + r) / 2;
		int res = getAns(mid);

		if (res == 0)
			break;
		else if (res == -1)
			l = mid + 1;
		else
			r = mid - 1;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	solve ();

return 0;
}
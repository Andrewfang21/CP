#include<bits/stdc++.h>
using namespace std;

void solve(int tc, string str) {
	int res, sum;
	res = sum = 0;

	for (char x : str) {
		int pos = (x == '{' ? 1 : -1);

		sum += pos;
		if (sum < 0) {
			sum += 2;
			res ++;
		}
	}

	if (sum != 0) {
		res += (sum / 2);
	}

	cout << tc << ". " << res << "\n";
}

bool isEnd(string str) {
	for (char x : str) {
		if (x == '-')
			return true;
	}

return false;
}

int main() {
	string str;
	int tc = 0;

	while (cin >> str) {
		if (isEnd(str))
			break;

		solve(++ tc, str);
	}

return 0;
}
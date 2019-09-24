#include<bits/stdc++.h>
using namespace std;

void print(int tc, int X, int Y) {
	cout << "Kasus #" << tc << ": ";
	if (X > 9)
		cout << X;
	else cout << "0" << X;
	cout << ":";
	if (Y > 9)
		cout << Y << "\n";
	else
		cout << "0" << Y << "\n";
}

void solve(int tc) {
	int hour, mins, x, y, rem;
	string waktu;
	cin >> waktu >> x >> y >> rem;
	hour = (waktu[0] - '0') * 10 + (waktu[1] - '0');
	mins = (waktu[3] - '0') * 10 + (waktu[4] - '0');

	int res = 0;
	while (true) {
		if (rem <= x) {
			res += rem;
			break;
		} else {
			res += x + y;
			rem -= x;
		}
	}

	int resHour, resMins;
	resMins = (mins + res) % 60;
	resHour = (hour + (mins + res) / 60) % 24;

	print(tc, resHour, resMins);
}

int main () {
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}
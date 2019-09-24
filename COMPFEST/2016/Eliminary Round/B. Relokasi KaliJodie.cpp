#include<bits/stdc++.h>
using namespace std;

const int n = 2e4 + 5;

int N;
double K, A[n];

void read () {
	cin >> N >> K;
	for (int i = 1; i <= N; i ++)
		cin >> A[i];
}

double getCost (double point) {
	double sum = 0.0;
	for (int i = 1; i <= N; i ++) {
		if (A[i] < (point - K / 2))
			sum += pow(point - K / 2 - A[i], 2);
		else
		if (A[i] > (point + K / 2))
			sum += pow(A[i] - point - K / 2, 2);
	}
	return sum;
}

void solve () {
	double left, right;
	left = 1;		right = 25000;

	double firstBound, secondBond;
	for (int i = 1; i <= 100; i ++) {
		firstBound = left + (right - left) / 3.0;
		secondBond = left + 2 * (right - left) / 3.0;

		if (getCost(firstBound) < getCost(secondBond))
			right = secondBond;
		else
			left = firstBound;
	}
	cout << setprecision(7) << fixed << getCost(firstBound) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	read ();
	solve ();

return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i ++) {
		if (num % i == 0)
			return false;
	}

return true;
}

bool almostPrime(int num) {
	if (isPrime(num))
		return false;

	for (int i = 2; i <= sqrt(num); i ++) {
		if (num % i == 0) {
			int div[2];
			div[0] = i;
			div[1] = num / i;

			if (isPrime(div[0]) && isPrime(div[1]))
				continue;
			else
				return false;
		}
	}

return true;
}

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int A, B;
		cin >> A >> B;

		int res = 0;
		for (int i = A; i <= B; i ++) {
			if (almostPrime(i))
				res ++;
		}

		cout << res << "\n";
	}

return 0;
}
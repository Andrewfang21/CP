#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXX_VAL = 15000005;

int n;
bool notPrime[MAXX_VAL];

void generatePrime () {
	int p = 2;

	notPrime[1] = true;
	while (p * p < MAXX_VAL) {
		int multiple = 2;

		while (p * multiple < MAXX_VAL) {
			notPrime[p * multiple] = true;
			multiple ++;
		}

		p ++;
		while (notPrime[p])
			p ++;
	}
}

int main () {
	scanf("%d", &n);

	generatePrime();
	vector<int> V;

	for (int i = 1; i < MAXX_VAL; i ++) {
		if (!notPrime[i])
			V.push_back(i);

		if (V.size() == n)
			break;
	}

	for (int i = 0; i < V.size(); i ++)
		printf("%d%c", V[i], i == V.size() - 1 ? '\n' : ' ');

return 0;
}

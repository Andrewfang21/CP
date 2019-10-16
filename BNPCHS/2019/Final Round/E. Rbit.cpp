#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int n;
bool A[N];

void solve (int tc) {
	int step = 1;
	scanf("%d", &n);

	while(true) {
		ll sum = step * (step + 1) / 2;
		if (sum < n || (sum % 2) != (n % 2))
			step ++;
		else
			break;
	}

	for (int i = 0; i < step; i ++)
		A[i] = true;

	ll rem = step * (step + 1) / 2 - n;
	rem /= 2;

	for (int i = step; i > 0; i --) {
		if (rem >= i) {
			rem -= i;
			A[step - i] = false; 
		}
	}

	printf("Case #%d: %d ", tc, step);
	for (int i = 0; i < step; i ++) {
		printf("%c", A[i] ? '+' : '-');
	}
	puts("");
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}
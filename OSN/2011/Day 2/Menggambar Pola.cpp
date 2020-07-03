#include<bits/stdc++.h>
using namespace std;

int n, m;

void solve(int n, int m) {
	for (int i = 1; i <= n; i ++) {
		char c;
		for (int j = 1; j <= m; j ++) {
			if (i % 2 == 0 && j % 2 == 0)
				c = '#';
			else if (i % 2 == 0 || j % 2 == 0)
				c = '$';
			else c = '*';

			printf("%c", c);
		}
		puts("");
	}
}

int main() {
	scanf("%d %d", &n, &m);
	solve(n, m);

return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

int n, m;
int text[N], pattern[N], diffText[N], diffPatt[N], Z[N];

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf("%d", &text[i]);
	for (int i = 0; i < m; i ++)
		scanf("%d", &pattern[i]);
}

void getDiff(int src[N], int copy[N], int n) {
	for (int i = 1; i < n; i ++)
		copy[i - 1] = src[i] - src[i - 1];
}

int ZAlgorithm(vector<int> V) {
	int left, right;
	left = right = 0;

	int n = V.size();
	for (int k = 1; k < n; k ++) {
		if (k > right) {
			left = right = k;
			while (right < n && V[right] == V[right - left])
				right ++;

			Z[k] = right - left;
			right --;
		}
		else {
			int k1 = k - left;

			if (Z[k1] < right - k + 1)
				Z[k] = Z[k1];
			else {
				left = k;
				while (right < n && V[right] == V[right - left])
					right ++;

				Z[k] = right - left;
				right --;
			}
		}
	}

	int res = 0;
	for (int i = m - 1; i < n; i ++) {
		if (Z[i] >= m - 1)
			res ++;
	}

return res;
}

void solve() {
	int diffText[N], diffPatt[N];
	
	memset(diffText, 0, sizeof(diffText));
	memset(diffPatt, 0, sizeof(diffPatt));

	getDiff(text, diffText, n);
	getDiff(pattern, diffPatt, m);

	vector<int> V;
	for (int i = 0; i < m - 1; i ++)
		V.push_back(diffPatt[i]);

	for (int i = 0; i < n - 1; i ++)
		V.push_back(diffText[i]);

	int res = 0;
	if (m == 1)
		res = n;
	else
		res = ZAlgorithm(V);

	printf("%d\n", res);
}

int main() {
	read();
	solve();

return 0;
}

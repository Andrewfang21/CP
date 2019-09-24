#include<bits/stdc++.h>
using namespace std;

const int n = 2e5 + 5;

int K;
string S, temp;

int sizes[n], parent[n], height[n], ANS[n];

struct state {
	int tipe, idx;
}Q[n];

void read () {
	cin >> S >> K;

	temp = S;
	for (int i = 1; i <= K; i ++) {
		cin >> Q[i].tipe >> Q[i].idx;

		if (Q[i].tipe == 2)
			S[Q[i].idx] = '#';
	}
}

int findSet (int pos) {
	if (pos == parent[pos])
		return parent[pos];
	else {
		int x = findSet(parent[pos]);
		parent[pos] = x;

		return x;
	}
}

void unionSet (int A, int B) {
	int x, y;
	x = findSet(A);			y = findSet(B);

	if (height[x] >= height[y]) {
		sizes[x] += sizes[y];		sizes[y] = 0;
		parent[y] = x;
	}
	else {
		sizes[y] += sizes[x];		sizes[x] = 0;
		parent[x] = y;
	}

	if (height[x] == height[y])		height[x] ++;
}

int getSize (int pos) {
	return sizes[findSet(pos)];
}

void precompute () {
	for (int i = 0; i < S.length(); i ++) {
		height[i] = sizes[i] = 1;
		parent[i] = i;

		if (i >= 1 && S[i] != '#' && S[i] == S[i - 1])
			unionSet(i, i - 1);
	}
}

void work (int tc) {
	cout << "Case " << tc << ":\n";

	precompute ();

	int currIdx = 0;
	for (int i = K; i >= 1; i --) {
		if (Q[i].tipe == 1)
			ANS[++ currIdx] = getSize(Q[i].idx);
		else {
			S[Q[i].idx] = temp[Q[i].idx];

			if (Q[i].idx >= 1 && S[Q[i].idx] == S[Q[i].idx - 1])
				unionSet(Q[i].idx, Q[i].idx - 1);

			if (Q[i].idx < S.length() - 1 && S[Q[i].idx] == S[Q[i].idx + 1])
				unionSet(Q[i].idx, Q[i].idx + 1);
		}
	}

	for (int i = currIdx; i >= 1; i --)
		cout << ANS[i] << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;
	
	for (int i = 1; i <= TC; i ++) {
		read ();
		work (i);
	}

return 0;
}
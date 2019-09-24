#include<bits/stdc++.h>
using namespace std;

const int n = 1e6 + 5;

int N, M, block;
int freq[n], ANS[n], A[n];

struct state {
	int left, right, idx;
}Q[n];

bool operator< (const state& LHS, const state& RHS) {
	if ((LHS.left - 1) / block != (RHS.left - 1) / block) 
		return LHS.left < RHS.left;

	return LHS.right < RHS.right;
}

void read () {
	cin >> N;

	block = ceil(sqrt(N));
	for (int i = 1; i <= N; i ++)
		cin >> A[i];

	cin >> M;
	for (int i = 0; i < M; i ++) {
		cin >> Q[i].left >> Q[i].right;
		Q[i].idx = i;
	}
}

void work () {
	sort(Q, Q + M);

	int currLeft, currRight, res;
	res = currLeft = currRight = 0;

	// for (int i = 0; i < M; i ++)
	// 	cout << i << "   " << Q[i].left << " " << Q[i].right << "\n";

	for (int i = 0; i < M; i ++) {
		
//		cout << i << "\t" << Q[i].left << " " << Q[i].right << "\n";

		while (currLeft < Q[i].left) {
			freq[A[currLeft]] --;
			if (freq[A[currLeft]] == 0)
				res --;

			currLeft ++;
		}

		while (currRight > Q[i].right) {
			freq[A[currRight]] --;
			if (freq[A[currRight]] == 0)
				res --;

			currRight --;
		}

		while (currLeft > Q[i].left) {
			currLeft --;
			freq[A[currLeft]] ++;

			if (freq[A[currLeft]] == 1)
				res ++;		
		}

		while (currRight < Q[i].right) {
			currRight ++;
			freq[A[currRight]] ++;

			if (freq[A[currRight]] == 1)
				res ++;
		}
		// cout << freq[1] << " " << freq[2] << " " << freq[3] << "\n";

		ANS[Q[i].idx] = res;
	}

	for (int i = 0; i < M; i ++)
		cout << ANS[i] << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}
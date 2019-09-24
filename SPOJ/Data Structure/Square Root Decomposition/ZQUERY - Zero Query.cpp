#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e5 + 500;

int N, M, block;
int A[n], ANS[n];

deque<int> Q[n];
multiset<int> res;

struct state {
	int left, right, idx;
}X[n];

bool operator < (const state& LHS, const state& RHS) {
	if ( (LHS.left - 1) / block != (RHS.left - 1) / block)
		return LHS.left < RHS.left;
	return LHS.right < RHS.right;
}

void read () {
	cin >> N >> M;

	A[0] = 50050;
	for (int i = 1; i <= N; i ++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}

	for (int i = 1; i <= M; i ++) {
		cin >> X[i].left >> X[i].right;
		X[i].left --;
		X[i].idx = i;
	}
}

void work () {
	block = ceil(sqrt(N));
	sort(X + 1, X + M + 1);

	int currLeft, currRight;
	currLeft = currRight = 0;

	Q[A[0]].push_front(0);
	for (int i = 1; i <= M; i ++) {
		
		while (currRight < X[i].right) {
			currRight ++;

			if (Q[A[currRight]].size() > 1) {
				int currAns = Q[A[currRight]].back() - Q[A[currRight]].front();
				res.erase(res.find(currAns));
			}

			Q[A[currRight]].push_back(currRight);

			if (Q[A[currRight]].size() > 1) {
				int currAns = Q[A[currRight]].back() - Q[A[currRight]].front();
				res.insert(currAns);
			}
		}

		while (currLeft > X[i].left) {
			currLeft --;

			if (Q[A[currLeft]].size() > 1) {
				int currAns = Q[A[currLeft]].back() - Q[A[currLeft]].front();
				res.erase(res.find(currAns));
			}

			Q[A[currLeft]].push_front(currLeft);

			if (Q[A[currLeft]].size() > 1) {
				int currAns = Q[A[currLeft]].back() - Q[A[currLeft]].front();
				res.insert(currAns);
			}
		}

		while (currLeft < X[i].left) {
			
			if (Q[A[currLeft]].size() > 1) {
				int currAns = Q[A[currLeft]].back() - Q[A[currLeft]].front();
				res.erase(res.find(currAns));
			}

			Q[A[currLeft]].pop_front();

			if (Q[A[currLeft]].size() > 1) {
				int currAns = Q[A[currLeft]].back() - Q[A[currLeft]].front();
				res.insert(currAns);
			}
			currLeft ++;
		}

		while (currRight > X[i].right) {

			if (Q[A[currRight]].size() > 1) {
				int currAns = Q[A[currRight]].back() - Q[A[currRight]].front();
				res.erase(res.find(currAns));
			}

			Q[A[currRight]].pop_back();

			if (Q[A[currRight]].size() > 1) {
				int currAns = Q[A[currRight]].back() - Q[A[currRight]].front();
				res.insert(currAns);
			}
			currRight --;
		}

		
		if (!res.empty()) 
			ANS[X[i].idx] = *res.rbegin();
	}

	for (int i = 1; i <= M; i ++)
		cout << ANS[i] << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}
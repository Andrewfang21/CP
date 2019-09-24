#include <bits/stdc++.h>
using namespace std;

const int n = 2e5 + 5;

struct state {
	int left, right, time, queryIDX;
}Q[n];

int N, M, query2Tot, block;
int A[n], freq[n], ANS[n], temp[n];

pair<int, int> Q1[n];


bool cmp (state lhs, state rhs) {
	if ((lhs.left - 1) / block != (rhs.left - 1) / block)
		return lhs.left < rhs.left;
	if ((lhs.right - 1) / block != (rhs.right - 1) / block)
		return lhs.right < rhs.right;

return lhs.time < rhs.time;
}

void del (int pos, int &res) {
	freq[A[pos]] --;

	if (freq[A[pos]] == 0)		res --;
	if (freq[A[pos]] == 1)		res ++;
}

void add (int pos, int &res) {
	freq[A[pos]] ++;

	if (freq[A[pos]] == 1)		res ++;
	if (freq[A[pos]] == 2)		res --;
}

void undo (int &res, int currLeft, int currRight, int &currTime) {
	currTime = 0;
	for (int i = 1; i <= N; i ++) {
		if (A[i] != temp[i]) {
			if (i >= currLeft && i <= currRight)
				del(i, res);

			A[i] = temp[i];

			if (i >= currLeft && i <= currRight)
				add (i, res);
		}
	}
}

void update (int &res, int currLeft, int currRight, int &currTime) {
	int QPos = Q1[currTime].first;

	if (QPos >= currLeft && QPos <= currRight)
		del (QPos, res);

	A[QPos] = Q1[currTime].second;

	if (QPos >= currLeft && QPos <= currRight)
		add (QPos, res);

	currTime ++;
}

void read () {
	cin >> N >> M;

	block = (double) pow (N, (double) 2 / 3);

	for (int i = 1; i <= N; i ++) {
		cin >> A[i];
		temp[i] = A[i];
	}

	int currTime = 0;
	for (int i = 1; i <= M; i ++) {
		int tipe;		cin >> tipe;

		if (tipe == 1) {
			cin >> Q1[currTime].first >> Q1[currTime].second;
			Q1[currTime].first ++;

			currTime ++;
		} else {
			int idx = query2Tot;
			cin >> Q[idx].left >> Q[idx].right;
			Q[idx].left ++, Q[idx].right ++;

			Q[idx].time = currTime;
			Q[idx].queryIDX = idx;

			query2Tot ++;
		}
	}
}

void solve () {
	sort(Q, Q + query2Tot, cmp);

	int res = 0;
	int currLeft, currRight, currTime;
	currLeft = 1, currRight = currTime = 0;

	for (int i = 0; i < query2Tot; i ++) {
		int L, R, Time;
		L = Q[i].left, R = Q[i].right, Time = Q[i].time;

		while (currLeft < L) {
			del (currLeft, res);
			currLeft ++;
		}

		while (currRight > R) {
			del (currRight, res);
			currRight --;
		}

		while (currLeft > L) {
			currLeft --;
			add (currLeft, res);
		}

		while (currRight < R) {
			currRight ++;
			add (currRight, res);
		}

		while (currTime > Time)
			undo(res, currLeft, currRight, currTime);

		while (currTime < Time)
			update(res, currLeft, currRight, currTime);

		ANS[Q[i].queryIDX] = res;
	}

	for (int i = 0; i < query2Tot; i ++)
		cout << ANS[i] << "\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	read ();
	solve ();

return 0;
}
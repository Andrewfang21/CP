#include<bits/stdc++.h>
#define LL long long
#pragma GCC Optimize("O3")
using namespace std;

const int n = 1e5 + 5, MAXX = 1e6 + 5;

LL N;
LL BIT[MAXX], conv[MAXX];

struct state {
	LL value, pos, original;
}A[MAXX], B[MAXX];

void read () {
	cin >> N;
	for (int i = 1; i <= N; i ++) {
		cin >> A[i].value;
		A[i].pos = i;
	}
}

bool cmp_pos (state LHS, state RHS) {
	return LHS.pos < RHS.pos;
}

bool cmp_val (state LHS, state RHS) {
	return LHS.value < RHS.value;
}

void update (LL idx, LL val) {
	while (idx < n) {
		BIT[idx] += conv[val];
		idx += (idx & -idx);
	}
}

LL GET (LL idx) {
	LL res = 0;
	while (idx > 0) {
		res += BIT[idx];
		idx -= (idx & -idx);
	} 

return res;
}

void work () {
	sort(A + 1, A + N + 1, cmp_val);
	
	int curr_pos = 1;

	B[1].value = 1;		B[1].original = A[1].value;		B[1].pos = A[1].pos;
	conv[curr_pos] = A[1].value;

	for (int i = 2; i <= N; i ++) {
		if (A[i].value > A[i - 1].value)
			curr_pos ++;
		B[i].value = curr_pos;		B[i].original = A[i].value;			B[i].pos = A[i].pos;

		conv[curr_pos] = A[i].value;
	}

	LL res = 0;
	sort (B + 1, B + N + 1, cmp_pos);

	// for (int i = 1; i <= N; i ++)
	// 	cout << i << " :  " << B[i].value << " " << conv[B[i].value] << "     " << B[i].original << "\n";

	for (int i = 1; i <= N; i ++) {
		if (i == 1) {
			update(B[i].value, B[i].value);
			continue;
		}

		LL curr_val = GET(B[i].value - 1);
		res += curr_val;

//		cout << i << "  " << curr_val << "\n";
		update (B[i].value, B[i].value);
	}

	cout << res << "\n";
	memset(BIT, 0, sizeof(BIT));
	memset(conv, 0, sizeof(conv));
}

int main () {
	ios_base::sync_with_stdio(false);

	int TC;		cin >> TC;
	while (TC --) {
		read ();
		work ();
	}

return 0;
}
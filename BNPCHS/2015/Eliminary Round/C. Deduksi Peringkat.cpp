#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<int> V;

void read () {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i ++) {
		int X;
		scanf("%d", &X);

		V.push_back(X);
	}
	V.push_back(M);
}

void solve (int tc) {
	sort(V.begin(), V.end(), greater<int>() );

	bool hasSolved = false;
	int currRank = 1;

	for (int i = 0; i < V.size(); i ++) {
		if (i == 0)
			continue;

		if (V[i] != V[i - 1])
			currRank = i + 1;

		if (V[i] == M) {
			hasSolved = true;
			printf("Kasus #%d: %d\n", tc, currRank);
			break;
		}
	}

	if (!hasSolved)
		printf("Kasus #%d: 1\n", tc);

	V.clear();
}

int main () {
	int TC;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i ++) {
		read ();
		solve (i);	
	}

return 0;
}
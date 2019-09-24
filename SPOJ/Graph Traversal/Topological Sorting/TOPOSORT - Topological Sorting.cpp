#include<bits/stdc++.h>
using namespace std;

const int n = 5e4 + 5;

int N, M;
int inDegree[n];

vector<int> adj[n], ANS;

void read () {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		inDegree[v] ++;
	}
}

void solve () {
	priority_queue<int, vector<int>, greater<int> > Q;
	for (int i = 1; i <= N; i ++)
		if (inDegree[i] == 0) 
			Q.push(i);

	int res = 0;
	while (!Q.empty()) {
		int pos = Q.top();		Q.pop();

		res ++;
		ANS.push_back(pos);

		for (int i = 0; i < adj[pos].size(); i ++) {
			int next = adj[pos][i];
			inDegree[next] --;

			if (inDegree[next] == 0)
				Q.push(next);
		}
	}

	if (res != N) {
		printf("Sandro fails.\n");
	} else {
		for (int i = 1; i <= N; i ++)
			i == N ? printf("%d\n", ANS[i - 1]) : printf("%d ", ANS[i - 1]);
	}
}

int main () {
	read ();
	solve ();

return 0;
}
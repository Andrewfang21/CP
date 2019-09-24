#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int dist[N];

struct state {
	int from, to, weight;
}edge[N];

void read () {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		edge[i].from = u, edge[i].to = v, edge[i].weight = w;
	}
}

void solve () {
	for (int i = 0; i < n; i ++)
		dist[i] = INT_MAX;

	dist[0] = 0;
	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int u = edge[j].from;
			int v = edge[j].to;
			int w = edge[j].weight;

			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	bool cycleExist = false;
	for (int i = 0; i < m; i ++) {
		int u = edge[i].from;
		int v = edge[i].to;
		int w = edge[i].weight;

		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
			cycleExist = true;
			break;
		}
	}

	if (cycleExist)
		printf("Pak Dengklek tidak mau pulang\n");
	else if (dist[n - 1] == INT_MAX)
		printf("Tidak ada jalan\n");
	else printf("%d\n", dist[n - 1]);
}

int main () {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		read ();
		solve ();
	}	

return 0;
}
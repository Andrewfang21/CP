#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 100005;

LL N, K, Q, cycle;
LL nxt[n], dist[n];

void read ()
{
	cin >> N >> K >> Q;
	
	for (int i = 1; i <= N; i ++)
		cin >> nxt[i];
	nxt[0] = 1;
}

void DFS (int node, int step)
{
	if (dist[node] != -1)
		return;
		
	dist[node] = step;
	cycle = step;
	
	DFS(nxt[node], step + 1);
}

void solve ()
{
	memset(dist, -1, sizeof(dist));
	DFS(0, 0);
	
	while (Q --)
	{
		LL query, res, rem;
		
		cin >> query;
		
		if (dist[query] == -1)
			cout << "0\n";
		else
		{
			res = (K + 1) / cycle;
			rem = (K + 1) % cycle;
			
			if (dist[query] <= rem)
				res ++;
				
			cout << res << "\n";
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}

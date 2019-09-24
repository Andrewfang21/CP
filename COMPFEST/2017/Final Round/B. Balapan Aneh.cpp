#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int n = 50005, nn = 10005;

LL N, M, K;
LL dist[n][2], S[nn], a[nn], b[nn], c[nn], total[2], res[2];

vector<LL> adj[n];

struct state
{
	LL node, step;
};

void read ()
{
	cin >> N >> M >> K;
	
	for (int i = 1; i <= M; i ++)
	{
		int u, v;	
		
		cin >> u >> v;
		adj[u].push_back(v);				adj[v].push_back(u);
	}
	
	for (int i = 1; i <= K; i ++)
		cin >> S[i] >> a[i] >> b[i] >> c[i];
}

void BFS()
{
	queue<state> q;
	
	q.push({N, 0});
	
	while (!q.empty())
	{
		state u = q.front();				q.pop();
		
		if (dist[u.node][u.step & 1] != -1)		continue;
		
		dist[u.node][u.step & 1] = u.step;
		
		for (int i = 0; i < adj[u.node].size(); i ++)
		{
			int nexts = adj[u.node][i];
			q.push({nexts, u.step + 1});
		}
	}
}

void solve ()
{
	memset(dist, -1, sizeof(dist));
	BFS();
	
	for (int i = 1; i <= K; i ++)
	{
		LL opt_dist, genap, ganjil, temp;
		
		opt_dist = (-1 * b[i]) / (2 * a[i]);
		genap = dist[S[i]][0];			ganjil = dist[S[i]][1];
		
		res[0] = res[1] = LLONG_MAX;
		
		if (genap != -1)
		{
			if (opt_dist < genap)
				total[0] = genap;
			else
			{	
				temp = opt_dist - genap;
				if (temp %2 != 0)		temp ++;
					
				total[0] = genap + temp;
			}
			res[0] = a[i] * total[0] * total[0] + b[i] * total[0] + c[i];
		}
		
		if (ganjil != -1)
		{
			if (opt_dist < ganjil)
				total[1] = ganjil;
			else
			{
				temp = opt_dist - ganjil;
				if (temp %2 != 0)		temp ++;
				
				total[1] = ganjil + temp;
			}
			
			res[1] = a[i] * total[1] * total[1] + b[i] * total[1] + c[i];
		}
		
		cout << min(res[0], res[1]) << "\n";
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();
	
return 0;
}

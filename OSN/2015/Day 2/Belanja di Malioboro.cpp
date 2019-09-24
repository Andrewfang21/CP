#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int M, N, Q, res;
int pos[MAXN], arah[MAXN];
int jarak_1, jarak_2, ganjil;

int dist[600000][5];

bool tambah;

struct lol
{
	int now, boo, dist;
};

queue<lol> q;

void read()
{
	string subs;
	cin >> subs;
	
	cin >> M >> N >> Q;
	
	for (int i=1;i<=N;i++)
		cin >> pos[i] >> arah[i];
	
	memset(dist, -1, sizeof(dist));				res = INT_MAX;
}

void BFS()
{
	if (q.empty())
		return ;
		
	while (!q.empty())
	{
		lol u = q.front();		q.pop();
		
		if (dist[u.now][u.boo] != -1)
			continue;
			
		dist[u.now][u.boo] = u.dist;
		
		if (u.boo == 0)
		{
			q.push({u.now, u.boo + 1, u.dist + 1});
			
			if (u.now == 0)
				q.push({M - 1, u.boo + 1, u.dist + 1});
			else
				q.push({u.now - 1, u.boo + 1, u.dist + 1});
		}
		else
		if (u.boo == 1)
		{
			if (u.now == M - 1)
				q.push({0, u.boo - 1, u.dist + 1});
			else
				q.push({u.now + 1, u.boo - 1, u.dist + 1});
			
			q.push({u.now, u.boo - 1, u.dist + 1});
		}
	}
}

void precompute()
{
	for (int i=1;i<=N;i++)
		for (int j=i+1;j<=N;j++)
		{
			if (arah[i] != arah[j])
			{
				ganjil = 0;				tambah = false;
				
				if (arah[i] == 1)
				{
					if (pos[i] > pos[j])
					{
						tambah = true;
						pos[j] += M;
					}
					
					jarak_1 = pos[j] - pos[i];
					
					if (jarak_1 % 2 != 0)
						ganjil = 1;
					
					q.push({jarak_1 / 2, ganjil, 0});	
					
					ganjil = 0;					
					
					if (tambah)
					{
						tambah = false;
						pos[j] -= M;
					}		
						
					jarak_2 = (M - jarak_1);
					
					if (jarak_2 % 2 !=0)
						ganjil = 1;
						
					q.push({jarak_1 + jarak_2 / 2, ganjil, 0});	
				}
				else
				{
					if (pos[i] < pos[j])
					{
						tambah = true;
						pos[i] += M;
					}
					
					jarak_1 = pos[i] - pos[j];
					
					if (jarak_1 % 2 != 0)
						ganjil  = 1;
						
					q.push({jarak_1 / 2, ganjil, 0});	
					
					ganjil = 0;
					
					if (tambah)
					{
						tambah = false;
						pos[i] -= M;
					}
						
					jarak_2 = (M - jarak_1);
					
					if (jarak_2 % 2 != 0)
						ganjil = 1;
						
					q.push({jarak_1 + jarak_2 / 2, ganjil, 0});	
				}
			}
			else
			{
				jarak_1 = min(abs(pos[i] - pos[j]),
							  abs(min(pos[i], pos[j]) + M - max(pos[i], pos[j])));
							  
				res = min(res, jarak_1);
			}
		}
	BFS();
}

void print()
{
	int query;
	
	while (Q--)
	{
		cin >> query;
		
		query %= M;
		
		if (dist[query][0] == -1)
			cout << res << "\n";
		else
			cout << min(res, dist[query][0]) << "\n";
	}
}

int main()
{
//	freopen("file.txt","r",stdin);
//	freopen("file_1.txt","w",stdout);
	
	ios_base::sync_with_stdio(false);
	read();
	precompute();
	print();
	
return 0;	
}

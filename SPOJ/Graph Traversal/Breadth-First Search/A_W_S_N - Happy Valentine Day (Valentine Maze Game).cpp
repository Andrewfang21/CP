#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;

const int n = 105, k = 1 << 10;

int N, M, K, res;
int C[n][n];
bool vis[n][n][k];

int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

char maze[n][n];

pair<int, int> start;

struct state
{
	int x, y, mask, step;
};

void read ()
{
	cin >> N >> M;

	K = 0;
	memset(C, 0, sizeof(C));
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= M; j ++)
		{
			cin >> maze[i][j];

			if (maze[i][j] == 'C')
				C[i][j] = ++ K;

			if (maze[i][j] == 'T')
				start = make_pair(i, j);
		}
}

bool inside (int i, int j)
{
	return (i >= 1 && i <= N && j >= 1 && j <= M);
}

void BFS ()
{
	queue<state> q;

	q.push({start.first, start.second, 0, 0});

	while (!q.empty())
	{
		state now = q.front();				q.pop ();

		if (vis[now.x][now.y][now.mask])
			continue;

		vis[now.x][now.y][now.mask] = true;

		if (maze[now.x][now.y] == 'W' && now.mask == (1 << K) - 1)
		{
			res = now.step;
			break;
		}

		for (int i = 0; i < 4; i ++)
		{
			state nexts;

			nexts.x = now.x + movex[i];			nexts.y = now.y + movey[i];
			nexts.mask = now.mask;

			if (inside(nexts.x, nexts.y) && maze[nexts.x][nexts.y] != '#')
			{
				if (maze[now.x][now.y] == 'C')
				{
					int pos = C[now.x][now.y];
					nexts.mask = now.mask | (1 << (pos - 1));
				}

				if (vis[nexts.x][nexts.y][nexts.mask])
					continue;

				q.push({nexts.x, nexts.y, nexts.mask, now.step + 1});
			}
		}
	}
}

void work ()
{
	memset(vis, false, sizeof(vis));

	res = -1;
	BFS ();

	if (res == -1)
		cout << "Mission Failed!\n";
	else
		cout << res << "\n";
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);			cout.tie(0	);

	int TC;
	cin >> TC;

	while (TC --)
	{
		read ();
		work ();		
	}
return 0;
}
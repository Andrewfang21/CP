#include<bits/stdc++.h>
using namespace std;

const int n = 1 << 17, k = 20;
typedef pair <int, int> ii;

int vis[n], val[k];

int adj[16][4] = { {2, 3, 5, 9}, {1, 4, 6, 10}, {1, 4, 7, 11}, {2, 3, 8, 12},
			 	   {1, 6, 7, 13}, {2, 5, 8, 14}, {3, 5, 8, 15}, {4, 6, 7, 16},
			  	   {1, 10, 11, 13}, {2, 9, 12, 14}, {3, 9, 12, 15}, {4, 10, 11, 16},
			       {5, 9, 14, 15}, {6, 10, 13, 16}, {7, 11, 13, 16}, {8, 12, 14, 15}
};

int convert ()
{
	int res = 0;
	for (int i = 16; i >= 1; i --)
	{
		if (val[i] == 1)
			res += (1 << (16 - i));
	}

return res;
}

void parse (int value)
{
	for (int i = 16; i >= 1; i --)
	{
		val[i] = value & 1;
		value /= 2;
	}
}

void precompute ()
{
	memset(vis, -1, sizeof(vis));
	int curr_state = (1 << 8) - 1;

	queue<ii> q;
	q.push(make_pair(curr_state, 0));

	while (!q.empty())
	{
		ii now = q.front();			q.pop();

		if (vis[now.first] != -1)
			continue;
		if (now.second > 3)
			continue;

		vis[now.first] = now.second;

		parse (now.first);

		for (int i = 1; i <= 16; i ++)
		{
			for (int j = 0; j < 4; j ++)
			{
				int nexts, next_state;

				nexts = adj[i - 1][j];
				if (val[nexts] == val[i])		continue;

				swap(val[nexts], val[i]);
				
				next_state = convert();
				q.push(make_pair(next_state, now.second + 1));

				swap(val[nexts], val[i]);
			}
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);

	precompute ();

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc ++)
	{
		int curr_state = 0;
		for (int i = 1; i <= 16; i ++)
		{
			int A;
			cin >> A;

			if (A == 1)
				curr_state += (1 << (16 - i));
		}
		cout << "Case #" << tc << ": ";

		if (vis[curr_state] == -1)
			cout << "more\n";
		else
			cout << vis[curr_state] << "\n";
	}
return 0;
}
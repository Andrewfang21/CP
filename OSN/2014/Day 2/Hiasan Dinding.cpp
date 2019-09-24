#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int MAXN = 105;

ll N, K, candidate, curr_ans, curr_size, curr_pos, MAXX = 3000000000;
ll parent[MAXN], children[MAXN][5], C[MAXN][MAXN], dp[MAXN], size[MAXN];
bool printed[MAXN];
vector<int> ans;
string subs;


void debug()
{
	for (int i=1;i<=N;i++)
		cout<<"Node : "<<i<<"  "<<dp[i]<<"    Size : "<<size[i]<<"\n";
		
	for (int i=1;i<=N;i++)
		cout<<i<<"     Left Child : "<<children[i][0]<<"      Right Child : "<<children[i][1]<<"\n";
			
}

void precompute()
{
	for (int i=0;i<=101;i++)
		for (int j=0;j<=i;j++)
		{
			if (j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = min(C[i-1][j-1] + C[i-1][j], MAXX);
		}
	memset(parent, -1, sizeof(parent));
	memset(children, 0, sizeof(children));
	
	memset(printed, false, sizeof(printed));
	memset(size, 0, sizeof(size));
}

void read()
{
	cin >> subs;
	
	cin >> N >> K;
	for (int i=1;i<N;i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		
		parent[v] = u;
		children[u][t] = v;
	}
}

void DFS(int node)
{
	if (node == 0)
		return ;
	if (children[node][0] == 0 && children[node][1] == 0)
	{
		size[node] = dp[node] = 1;
		return;
	}
	
	int left_child, right_child, now_size = 0;
	
	left_child = children[node][0];				right_child = children[node][1];
	
	DFS(left_child);			DFS(right_child);

	if (left_child != 0)		now_size += size[left_child];
	if (right_child != 0)		now_size += size[right_child]; 
	
	dp[node] = 1;
	for (int i=0;i<=1;i++)
		if (children[node][i] != 0)
			dp[node] = min(dp[node] * dp[ children[node][i] ], MAXX);
			
	dp[node] = min(dp[node] * C[now_size][ size[left_child] ], MAXX);
	
	size[node] = now_size + 1;	
}

void search(int now)
{
	if (now == 0 || now == curr_pos)
		return;
	
	if (!printed[now])		//belum dipake
	{
		curr_ans = min(curr_ans * dp[now], MAXX);
		curr_ans = min(curr_ans * C[ curr_size + size[now] ][size[now]], MAXX);
		
		curr_size += size[now];
		
//		cout << now << "  " << curr_ans << "   " << curr_size << "\n";
	}
	else
	{
		search(children[now][0]);
		search(children[now][1]);
	}
}


void solve()
{	
	int root;
	
	for (int i=1;i<=N;i++)
		if (parent[i] == -1)		root = i;
	
	DFS(root);		// Hitung Size suatu node + DP
		
//	debug();
	
	ans.pb(root);			printed[root] = true;
	
	while (ans.size() != N)
	{
		for (int i=1;i<=N;i++)
		{
			if (printed[i])					continue;
			if (!printed[parent[i]])		continue;
			
			curr_pos = i;
			curr_ans = dp[i];			curr_size = size[i] - 1;
			
			search(root);
			
//			cout << i << "    " << curr_ans << "\n\n";
			
			if (K > curr_ans)
				K -= curr_ans;
			else
			{
				ans.pb(i);				printed[i] = true;
				break;
			}
		}
	}
}

void print()
{
	for (int i=0;i<ans.size();i++)
		if (i == ans.size() - 1)
			cout << ans[i] << "\n";
		else
			cout << ans[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	precompute();
	read();
	solve();
	print();
	
return 0;
}

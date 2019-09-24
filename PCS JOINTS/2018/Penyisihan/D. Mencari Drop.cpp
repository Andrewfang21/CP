#include<bits/stdc++.h>
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;

ll res,N,M,K;
vector<ll>v;
bool visited[400][400];
char maze[400][400];
map<char,ll>sign;
int movex[]={0,0,1,-1};
int movey[]={1,-1,0,0};

bool inside(int i, int j)
{
	if (i>=1 && i<=N && j>=1 && j<=M)
		return true;
return false;
}

void DFS(int i, int j)
{
	if (!inside(i,j))
		return;
	if (visited[i][j] || maze[i][j]=='#')
		return;

	visited[i][j]=true;
	res+=sign[maze[i][j]];
	
	for (int it=0;it<4;it++)
	{
		pair<int, int> nexts=mp(i+movex[it], j+movey[it]);
		
		if (!visited[nexts.fi][nexts.sec])
			DFS(nexts.fi, nexts.sec);
	}
}

void check()
{
	sign['A']=1;
	sign['B']=2;
	sign['C']=4;
	sign['D']=8;
	sign['E']=16;
	
	memset(visited,false,sizeof(visited));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M>>K;
	
	check();
		
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			cin>>maze[i][j];
	
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			if (!visited[i][j] && maze[i][j]!='#')
			{
				res=0;
				DFS(i,j);
				v.push_back(res);
			}
		}
		
	res=0;
	sort(v.begin(), v.end(), greater<int>() );
	for (int i=0;i<K;i++)
		res+=v[i];
		
	cout<<res<<"\n";
	
return 0;
}

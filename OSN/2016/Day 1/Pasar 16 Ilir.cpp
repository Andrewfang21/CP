#include<bits/stdc++.h>
using namespace std;
long long N,M,maze[40][40],i,j,Q,a,b;
bool visited[40][40];
vector<long long>vec;

bool inside(int x, int y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M))
		return true;
return false;
}

long long binser(long long bawah, long long atas)
{
	long long kiri,kanan,mid,up,low;
	up=low=-1;
	
	kiri=0;		kanan=vec.size()-1;
	while (kiri<=kanan)
	{
		mid=(kiri+kanan)/2;
		if (vec[mid]>=bawah)
		{
			low=mid;
			kanan=mid-1;	
		}	
		else
			kiri=mid+1;
	}	
	
	kiri=0;		kanan=vec.size()-1;
	while (kiri<=kanan)
	{
		mid=(kiri+kanan)/2;
		if (vec[mid]>atas)
			kanan=mid-1;
		else
		{
			up=mid;
			kiri=mid+1;
		}
	}
	if ((up>=0)&&(low>=0)&&(up-low+1>0))
		return (up-low+1);
	else
		return 0;
}

void dfs(int x, int y, long long sum)
{
	if (inside(x,y)&&(!visited[x][y]))
	{
		visited[x][y]=true;
		if ((x==N)&&(y==M))
			vec.push_back(sum);
		else
		{
			dfs(x+1,y,sum+maze[x+1][y]);
			dfs(x-1,y,sum+maze[x-1][y]);
			dfs(x,y+1,sum+maze[x][y+1]);
			dfs(x,y-1,sum+maze[x][y-1]);
		}
		visited[x][y]=false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy;
	cin>>dummy;
	cin>>N>>M;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			cin>>maze[i][j];
	memset(visited,false,sizeof(visited));
	dfs(1,1,maze[1][1]);
	sort(vec.begin(),vec.end());
	
	/*for (i=0;i<vec.size();i++)
		cout<<vec[i]<<"\n";
	cout<<"\n";*/
	
	cin>>Q;
	while (Q--)
	{
		cin>>a>>b;
		long long x=binser(a,b);
		cout<<x<<"\n";
	}
return 0;
}

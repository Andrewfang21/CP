#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,cnt=1,ans,num[1005][1005];
bool visited[1005][1005];
char maze[1005][1005];

void dfs(int a, int b)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M))
	{
		if (!visited[a][b])	//belum pernah dikunjungi
		{
			visited[a][b]=true;
			num[a][b]=cnt;		// jumlah bom min. dipasang
			
			if (maze[a][b]=='S')
				dfs(a+1,b);
			if (maze[a][b]=='N')
				dfs(a-1,b);
			if (maze[a][b]=='E')
				dfs(a,b+1);
			if (maze[a][b]=='W')
				dfs(a,b-1);
		}
		else
		{
			if (num[a][b]==cnt)		//jika sama
				return ;
			else
			{
				ans--;		// tidak perlu 2x pasang bom karna membentuk cycle
			}
		}
	}
}

int main()
{
	cin>>N>>M;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			cin>>maze[i][j];
	
	memset(visited,false,sizeof(visited));
	memset(num,0,sizeof(num));
	
	ans=0;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
		{
			if (!visited[i][j])
			{
				dfs(i,j);
				cnt++;
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	
	/*for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			if (j==M)
				cout<<num[i][j]<<"\n";
			else
				cout<<num[i][j]<<" ";*/
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int N,M,cnt,i,j;
char maze[255][255];
bool visited[255][255];
map<int,int>frek;
map<int,bool>printed;

void floodfill(int x, int y)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)&&(maze[x][y]=='1')&&(!visited[x][y]))
	{
		visited[x][y]=true;
		cnt++;
		floodfill(x+1,y);
		floodfill(x-1,y);
		floodfill(x,y+1);
		floodfill(x,y-1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	while (cin>>N>>M)
	{
		if ((N==0)&&(M==0))	return 0;
		
		for (i=1;i<=N;i++)
			for (j=1;j<=M;j++)
				cin>>maze[i][j];
		cnt=0;		
		vector<int>ans;
		memset(visited,false,sizeof(visited));
		frek.clear();	printed.clear();	ans.clear();
		
		for (i=1;i<=N;i++)
		{
			for (j=1;j<=M;j++)
			{
				if (!visited[i][j])
				{
					if (cnt>0)	ans.push_back(cnt);
					frek[cnt]++;
					cnt=0;
					floodfill(i,j);
				}
			}
		}
		if (cnt>0)
		{
			ans.push_back(cnt);
			frek[cnt]++;
		}
	
		if (ans.size()==0)
			cout<<"0\n";
		else
		{
			sort(ans.begin(),ans.end());
			cout<<ans.size()<<"\n";
			for (i=0;i<ans.size();i++)
			{
				if (!printed[ans[i]])
				{
					cout<<ans[i]<<" "<<frek[ans[i]]<<"\n";
					printed[ans[i]]=true;
				}
			}
		}
	}
return 0;
}

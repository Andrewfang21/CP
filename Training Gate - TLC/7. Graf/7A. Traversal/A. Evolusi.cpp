#include<bits/stdc++.h>
using namespace std;
map<string,int>convert;
vector<int>adj[100025];
bool found,visited[100025];
int M,N,i,temp,source,akhir;
string a,b,daftar[1000000],evolution[1000000];

void dfs(int a, int b, int time)
{
	if ((!found)&&(!visited[a]))
	{
		daftar[time]=evolution[a];
		
		if (a==b)
		{
			for (int temp=0;temp<=time;temp++)
			{
				cout<<daftar[temp]<<"\n";
				found=true;
			}
		}
		else
		for (int temp=0;temp<adj[a].size();temp++)
		{
			visited[a]=true;
			dfs(adj[a][temp],b,time+1);
			visited[a]=false;
		}
	}
}

int main()
{
	temp=0;
	scanf("%d %d",&M,&N);
	memset(visited,false,sizeof(visited));
	for (i=0;i<N;i++)
	{
		cin>>a>>b;
		if (convert[a]==0)
		{
			temp++;
			convert[a]=temp;
			evolution[temp]=a;
		}
		if (convert[b]==0)
		{
			temp++;
			convert[b]=temp;
			evolution[temp]=b;
		}
		adj[convert[a]].push_back(convert[b]);
	}
	cin>>a>>b;
	source=convert[a];
	akhir=convert[b];
	found=false;
	dfs(source,akhir,0);
	if (!found)
	{
		memset(visited,false,sizeof(false));
		dfs(akhir,source,0);
		if (!found)
			printf("TIDAK MUNGKIN\n");
	}
return 0;
}

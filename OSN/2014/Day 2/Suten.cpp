#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
vector<pair<int,int> >adj[105];
bool visited[105];
int INF=2*pow(10,7);

int DFS(int now, int finish, int dist)
{	
	int lol;
	//printf("%d %d %d    %d\n",now,dist,adj[now].size(),finish);
	if (now==finish)
	{
		int tmp=dist;
		if (tmp<0)
		{
			int temp1=abs(tmp);
			int kali=ceil(double(temp1)/3.0);
			int ans=(kali*3)-temp1;
			//printf("%d %d     %d\n",now,ans,finish);
			return (ans%3);	
		}	
		else
			return (dist%3);
	}
	if (adj[now].size()==0)
		return INF;
	
	if (!visited[now])
	{	
		visited[now]=true;
		for (int tmp=0;tmp<adj[now].size();tmp++)
		{
			int next,jarak;
			next=adj[now][tmp].first;		jarak=adj[now][tmp].second;
			if (!visited[next])
			{
				lol=DFS(next,finish,dist+jarak);
				if (lol!=INF)
				{
					visited[now]=false;
					return lol;
				}
			}
		}
		visited[now]=false;
	}
return INF;
}

int main()
{
	char dummy[20];
	scanf("%s",dummy);
	int N,i,a,b,x;
	scanf("%d",&N);
	
	for (i=1;i<=(N*(N-1))/2;i++)
	{
		scanf("%d %d",&a,&b);
		x=DFS(a,b,0);
		
		//printf("%d\n",x);
		if (x==0)
		{
			printf("SERI\n");
			fflush(stdout);
		}
		else
		if (x==1)
		{
			printf("%d MENANG\n",a);
			fflush(stdout);
		}
		else
		if (x==2)
		{
			printf("%d MENANG\n",b);
			fflush(stdout);
		}
		else
		if (x==INF)	//gak ketemu relasi
		{
			printf("PASS\n");
			fflush(stdout);
			
			scanf("%s",dummy);
			string ans=dummy;
			
			if (ans=="SERI")
			{
				adj[a].pb(mp(b,0));		adj[b].pb(mp(a,0));
			}
			else
			{
				scanf("%s",dummy);
				int tmp=stoi(ans);
				
				if (tmp==a)
				{
					adj[a].pb(mp(b,1));		adj[b].pb(mp(a,-1));
				}
				else
				{
					adj[a].pb(mp(b,-1));	adj[b].pb(mp(a,1));
				}
			}
		}
	}
return 0;
}

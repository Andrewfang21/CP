#include<bits/stdc++.h>
using namespace std;
int parent[100005],colour[100005],height[100005];
vector<int>adj[100005];

bool sameset(int a, int b)
{
	if (parent[a]==parent[b])
		return true;
return false;
}

bool findset(int num)
{
	if (parent[num]!=num)
		return findset(parent[num]);
	else
		return num;
}

void union_set(int a, int b)
{
	long long x,y;
	if (!sameset(a,b))
	{
		x=findset(a);	y=findset(b);
		if (height[x]>height[y])
			parent[y]=x;
		else
			parent[x]=y;
		
		if (height[x]==height[y])
			height[y]++;
	}
}

int main()
{
	int N,i,a,b,Q,tipe;
	scanf("%d",&N);
	memset(height,0,sizeof(height));
	
	for (i=0;i<(N-1);i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);	adj[b].push_back(a);
	}
	for (i=0;i<N;i++)
		parent[i]=i;
		
	memset(colour,-1,sizeof(colour));
	scanf("%d",&Q);
	
	while (Q--)
	{
		scanf("%d",&tipe);
		if (tipe==1)
		{
			scanf("%d %d",&a,&b);
			colour[a]=b;
			for (int temp=0;temp<adj[a].size();temp++)
			{
				int current=adj[a][temp];
				if (colour[current]==colour[a])
					union_set(a,current);
			}
		}
		else
		if (tipe==2)
		{
			scanf("%d %d",&a,&b);
			if ((sameset(a,b))&&(colour[a]!=-1)&&(colour[b]!=-1)&&(colour[a]==colour[b]))
				printf("YES\n");
			else
				printf("NO\n");
			
			//printf("PARENT  %d %d\n",parent[a],parent[b]);
		}
	}
return 0;
}

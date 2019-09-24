#include<bits/stdc++.h>
using namespace std;

int parent[100005],height[100005],N,Q,type;

int findset(int num)
{
	if (parent[num]!=num)
	{
		int search=findset(parent[num]);
		parent[num]=search;
		
		return search;
	}
	else
		return num;
}

void merge(int a, int b)
{
	int x,y;
	x=findset(a);		y=findset(b);
	
	if (x!=y)
	{
		if (height[x]>=height[y])
			parent[y]=x;
		else
			parent[x]=y;
			
		if (height[x]==height[y])
			height[x]++;
	}
}

bool sameset(int a, int b)
{
	int x,y;
	x=findset(a);		y=findset(b);
	
	if (x==y)
		return true;
		
return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>Q;
	
	int a,b;
		
	for (int i=1;i<=N;i++)
		parent[i]=i;	
	
	while (Q--)
	{
		cin>>type>>a>>b;
			
		if (type==1)
			merge(a,b);
		else
		if (type==2)
		{
			if (sameset(a,b))
				cout<<"Y\n";
			else
				cout<<"T\n";
		}
	}
return 0;
}

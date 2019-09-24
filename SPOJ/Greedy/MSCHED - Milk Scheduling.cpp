#include<bits/stdc++.h>
using namespace std;

struct lol
{
	int milk,deadline;
};

bool accompare (lol lhs, lol rhs)
{
	if (lhs.deadline==rhs.deadline)
		return lhs.milk>rhs.milk;
	else
		return lhs.deadline>rhs.deadline;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i,a,b,res=0,min;

	cin>>N;

	lol adj[N+5];
	map<int,bool>counted;
	
	for (i=0;i<N;i++)
	{
		cin>>a>>b;
		adj[i].milk=a;
		adj[i].deadline=b;
	}	
	sort(adj,adj+N,accompare);
	
	for (i=0;i<N;i++)
		cout<<adj[i].deadline<<" "<<adj[i].milk<<"\n";
		
	for (i=0;i<N;i++)
	{
		for (int j=adj[i].deadline;j>=1;j--)
		{
			if (!counted[j])
			{
				counted[j]=true;
				res+=adj[i].milk;
				break;
			}	
		}	
	}
	cout<<res<<"\n";	
return 0;
}

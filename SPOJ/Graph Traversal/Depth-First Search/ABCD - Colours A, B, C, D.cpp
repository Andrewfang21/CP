#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
pair<int, int> ii;

int main()
{
	int K,N,a,v,i,temp1,temp2;
	ii start[10], bear[1005], now,target;
	cin>>K>>N;
	for (i=1;i<=K;i++)
	{
		cin>>a>>b;
		start[i]=mp(a,b);
	}
	for (i=1;i<=N;i++)
	{
		cin>>a>>b;
		bear[i]=mp(a,b);
	}
	
	for (i=1;i<=K;i++)
	{
		now=mp(start[i].x, start[i].y);
		
		for (temp1=1;temp1<=N;temp1++)
		{
			fail=false;
			for (temp2=1;temp2<=N;temp2++)
			{
				if (temp1!=temp2)
				{
					target=bear[temp1];
					linear=check(now,line[temp2],target);
					
					if (linear==0)	// ada yang menghalang
					{
						if (now.x<=target.x && line[temp2].x<=target.x)||
		            	   (now.x>=target.x && line[temp2].x>=target.x)
								fail=true;
					}
				}
			}
			if (!fail)
				can[temp1]=true;
		}
	}
	for (i=1;i<=N;i++)
		if (can[i])
			res++;
	cout<<res<<"\n";
return 0;
}

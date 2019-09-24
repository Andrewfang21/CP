#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,j;
	scanf("%d",&N);
	int koin[N+5],uang;
	for (i=1;i<=N;i++)
		scanf("%d",&koin[i]);
	scanf("%d",&uang);
	
	int ans[uang+5];
	memset(ans,-1,sizeof(ans));
	ans[0]=0;
	
	for (i=1;i<=uang;i++)
	{
		int best=INT_MAX;
		for (j=1;j<=N;j++)
		{
			if (koin[j]<=i)
				if (ans[i-koin[j]]!=-1)
					best=min(best,ans[i-koin[j]]+1);
		}
		if (best==INT_MAX)
			ans[i]=-1;
		else
			ans[i]=best;
	}
	for (i=1;i<=uang;i++)
		if (ans[i]<=0) ans[i]=-1;
			
	if (ans[uang]<=0) cout<<-1<<"\n"; else cout<<ans[uang]<<"\n";
return 0;	
}

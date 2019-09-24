#include<bits/stdc++.h>
using namespace std;
int N,target,i,j,koin[10025],ans[10025];
int main()
{
	cin>>N>>target;
	for (i=1;i<=N;i++)
		cin>>koin[i];
	for (i=1;i<=target;i++)
		ans[i]=INT_MAX;
	ans[0]=0;
	for (i=1;i<=N;i++)
	{
		for (j=target;j>=1;j--)
		{
			if (j>=koin[i])
			{
				if (ans[j-koin[i]]!=INT_MAX)
					ans[j]=min(ans[j],ans[j-koin[i]]+1);
			}
		}
	}
	if (ans[target]!=INT_MAX) cout<<ans[target]<<"\n"; else cout<<"-1\n";
return 0;
}
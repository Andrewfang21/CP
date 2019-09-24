#include<bits/stdc++.h>
using namespace std;
long long TC,N,K,i,now,kiri,kanan;
pair<long long, long long>ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		bool fail=false;
		cin>>N>>K;
		long long arr[N+5];
		for (i=1;i<=N;i++)
			cin>>arr[i];
		
		kiri=kanan=1;
		now=arr[1];
		ans=make_pair(0,0);
				
		while (kanan!=N)
		{
			while (now<=K)
			{
				kanan++;
				if (kanan>N)
				{
					fail=true;
					break;
				}
				now+=arr[kanan];
				
				//cout<<kiri<<" "<<kanan<<" "<<now<<"\n";
				
				if (now<=K)
				{
					if ((ans.second<(kanan-kiri+1)))
					{
						ans.first=now;
						ans.second=(kanan-kiri+1);
					}
					else
					if (ans.second==(kanan-kiri+1))
						ans.first=min(now,ans.first);
				}
			}
			while (now>K)
			{
				now-=arr[kiri];
				kiri++;
				if (kiri>kanan)
				{
					kanan=kiri;
					now=arr[kiri];
				}
				if (kiri>N)
				{
					fail=true;
					break;
				}
				
				//cout<<kiri<<" "<<kanan<<" "<<now<<"\n";
				
				if (now<=K)
				{
					if ((ans.second)<(kanan-kiri+1))
					{
						ans.first=now;
						ans.second=(kanan-kiri+1);
					}
					else
					if (ans.second==(kanan-kiri+1))
						ans.first=min(now,ans.first);
				}
			}
			if (fail)
				break;
		}
		cout<<ans.first<<" "<<ans.second<<"\n";		
	}	
return 0;
}

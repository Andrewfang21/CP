#include<bits/stdc++.h>
using namespace std;
long long  now,TC,N,K,i,kanan,kiri;
pair<long long, long long> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		int arr[N+5];		
		for (i=1;i<=N;i++)
			cin>>arr[i];
		
		kiri=kanan=1;	now=arr[1];
		ans=make_pair(0,0);
		bool fail=false;
		
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
				//cout<<kiri<<" "<<kanan<<" "<<now<<" "<<ans.first<<" "<<ans.second<<"\n";
				if (now<=K)
				{
					if (ans.first==(kanan-kiri+1))
						ans.second=min(ans.second,now);
					else
					if (ans.first<(kanan-kiri+1))
					{
						ans.second=now;
						ans.first=(kanan-kiri+1);
					}
				}
			}
			while (now>K)
			{
				now-=arr[kiri];
				kiri++;
				if (kiri>kanan)
					break;
					
				//cout<<kiri<<" "<<kanan<<" "<<now<<" "<<ans.first<<" "<<ans.second<<"\n";
				if (now<=K)
				{
					if (ans.first==(kanan-kiri+1))
						ans.second=min(ans.second,now);
				}
				else
				if (ans.first<(kanan-kiri+1))
				{
					ans.first=max(ans.first,(kanan-kiri+1));
					ans.second=now;
				}
			}
			if (fail)
				break;
		}
		cout<<ans.second<<" "<<ans.first<<"\n";
	}
return 0;
}

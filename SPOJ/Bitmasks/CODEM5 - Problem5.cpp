#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int TC,N,K;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>K;
		
		int v[N+5];
		for (int i=0;i<N;i++)
			cin>>v[i];
			
		int res=INT_MAX;
		
		for (int mask=0;mask<(1<<N);mask++)
		{
			int sum,cnt;;
			sum=cnt=0;
			
//			cout<<mask<<"\n";
//			cout<<"BARANG : ";
			for (int i=0;i<N;i++)
			{
				int temp=mask&(1<<i);
				if (temp!=0)
				{
					sum+=v[i];
					cnt++;
				}
			}
//			cout<<"\nTOTAL : "<<sum<<"\n\n";
			if (sum==K)
				res=min(res,cnt);
		}
		
		if (res==INT_MAX)
			cout<<"impossible\n";
		else
			cout<<res<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long TC,N,ans,i,temp1,temp2;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		ans=0;
		for (i=2;i<=sqrt(N);i++)
		{
			if (N%i==0)
			{
				temp1=i;	temp2=N/i;
				if (temp1!=temp2)
					ans+=(temp1+temp2);
				else
					ans+=temp1;
			}
		}
		if (N!=1)
			ans+=1;
		cout<<ans<<"\n";
	}
return 0;
}

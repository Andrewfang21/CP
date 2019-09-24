#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long TC,N,i,temp1,temp2,ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		N=2*N;
		ans=-1;
			
		for (i=sqrt(N);i>=1;i--)
		{
			if (N%i==0)
			{
				temp1=i;		temp2=(N/i);
				if ((temp2-temp1)==1)
				{
					ans=temp1;
					break;
				}
			}	
		}	
		if (ans==-1)
			cout<<"NAI\n";
		else
			cout<<ans<<"\n";
	}
return 0;
}

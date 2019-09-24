#include<bits/stdc++.h>
using namespace std;

int main()
{
	long int x[100003],n,q,y,hi,lo,mid;
	bool ketemu;
	
	cin>>n>>x[1];
	for (int i=2;i<=n;i++)
	{
		cin>>x[i];
		x[i]=x[i]+x[i-1];
	}
	
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>y;
		hi=n;
		lo=1;
		ketemu=false;
		
		while(hi>=lo)
		{
			mid=(hi+lo)/2;
			if (x[mid]==y)
			{
				ketemu=true;
				break;
			} else
			if (x[mid]<y) lo=mid+1; else hi=mid-1;
		}
		
	if (ketemu) cout<<mid<<"\n"; else cout<<lo<<"\n";
	}
return 0;	
}
#include<bits/stdc++.h>
using namespace std;

int l,r;
string ans1,ans2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>l>>r;
	
	while (l<=r)
	{
		int mid=(l+r)/2;
		
//		cout<<l<<" "<<r<<"  "<<mid<<"\n";
		
		cout<<mid<<endl;
		cin>>ans1;
		
		if (ans1[0]=='t')
		{
			cin>>ans2;
			if (ans2[0]=='b')
				r=mid-1;
			else
				l=mid+1;
		}
		else
			return 0;
	}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long TC,tc,mins,N;
long long arr[100005],pref[100005];

int main()
{
	cin>>TC;
	
	for (tc=1;tc<=TC;tc++)
	{
		cin>>N;
		mins=LLONG_MAX;
		pref[0]=0;
		
		for (int i=1;i<=N;i++)
		{
			cin>>arr[i];
			pref[i]=pref[i-1]+arr[i];
			mins=min(pref[i],mins);
			//cout<<i<<" "<<pref[i]<<" "<<mins<<"\n";
		}
		if (mins<=0)
		{
			mins=abs(mins);
			cout<<mins+1<<"\n";
		}
		else
			cout<<"0\n";
	}
return 0;
}

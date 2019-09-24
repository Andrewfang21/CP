#include<bits/stdc++.h>
using namespace std;

int main()
{
	string subs;
	cin>>subs;
	long long N,i,ans=0,cnt,now;
	cin>>N;
	long long arr[N+5];
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	now=arr[0];		cnt=1;
	
	for (i=2;i<=N;i++)
	{
		if (arr[i]==arr[i-1])
			cnt++;
		else
		{
			ans+=(cnt*(cnt+1)/2);
			cnt=1;
		}
	}
	ans+=(cnt*(cnt+1)/2);
	cout<<ans<<"\n";
return 0;
}

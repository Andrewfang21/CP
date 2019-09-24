#include<bits/stdc++.h>
using namespace std;
long long pref[100005],arr[100005],N;

long long search(long long a, long long b)
{
	long long left,right,up,mid,low;
	
	left=1;		right=N;
	up=low=-1;
	
	while (left<=right)
	{
		mid=(left+right)/2;
		
		if (arr[mid]<=b)
		{
			up=mid;
			left=mid+1;
		}
		else
			right=mid-1;
	}
	
	left=1;		right=N;
	
	while (left<=right)
	{
		mid=(left+right)/2;
		
		if (arr[mid]>=a)
		{
			low=mid;
			right=mid-1;
		}
		else
			left=mid+1;
	}
	
	if ((up>0)&&(low>0)&&(up-low+1>0))
	{
		long long temp=pref[up]-pref[low-1];
		return temp;
	}
return 0;
}

int main()
{
	int i;
	cin>>N;
	
	for (i=1;i<=N;i++)
		cin>>arr[i];
	sort(arr+1,arr+N+1);
	pref[0]=0;
	
	for (i=1;i<=N;i++)
		pref[i]=pref[i-1]+arr[i];
		
	/*for (i=1;i<=N;i++)
		cout<<arr[i]<<" "<<pref[i]<<"\n";*/
	int Q,a,b;
		
	cin>>Q;
	while (Q--)
	{
		cin>>a>>b;
		long long ans=search(a,b);
		
		cout<<ans<<"\n";	
	}	
return 0;
}

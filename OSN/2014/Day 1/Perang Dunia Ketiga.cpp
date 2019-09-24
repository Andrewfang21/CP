#include<bits/stdc++.h>
using namespace std;
long long cnt[2000005],pref[2000005],pref2[2000005];

int main()
{
	ios_base::sync_with_stdio(false);
	long long N,i,j,ans,temp1,sum,temp2;
	string dummy;
	cin>>dummy;
	cin>>N;
	long long arr[N+5];
	
	memset(pref,0,sizeof(pref));	memset(pref2,0,sizeof(pref2));
	memset(cnt,0,sizeof(cnt));
	
	for (i=0;i<N;i++)
	{
		cin>>arr[i];
		cnt[arr[i]]++;
		
		if (arr[i]==0)
			pref[0]++;	
	}
	
	sort(arr,arr+N);
	for (i=1;i<=2000000;i++)
	{
		pref[i]=pref[i-1]+cnt[i];
		pref2[i]=pref2[i-1]+i*cnt[i];
	}
	
	if (arr[N-1]==0)
	{
		cout<<N<<"\n";
		return 0;
	}
	
	ans=LLONG_MAX;
	for (i=1;i<=arr[N-1];i+=2)
	{
		sum=0;			temp2=0;
		for (j=i;j<=2000000;j*=2)
		{
			if ((temp2==0)&&(pref[0]!=0))
			{
				sum=sum+j*pref[j]-pref2[j];
			}
			else
				sum=sum+j*(pref[j]-pref[temp2])-(pref2[j]-pref2[temp2]);
			//cout<<j<<" "<<sum<<"\n";
			temp2=j;
		}
		//cout<<i<<" "<<sum<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
return 0;
}

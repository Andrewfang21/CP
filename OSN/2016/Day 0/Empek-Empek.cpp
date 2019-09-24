#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy;
	int N;
	cin>>dummy;
	cin>>N;
	char arr[N+5];
	long long i,pref1[N+5],pref2[N+5],pref3[N+5],ans=0;
	memset(pref1,0,sizeof(pref1));
	memset(pref2,0,sizeof(pref2));
	memset(pref3,0,sizeof(pref3));
	
	for (i=1;i<=N;i++)
	{
		cin>>arr[i];
		if (arr[i]=='1')
		{
			pref1[i]=pref1[i-1]+1;
			pref2[i]=pref2[i-1];
			pref3[i]=pref3[i-1];
		}
		else
		if (arr[i]=='2')
		{
			pref1[i]=pref1[i-1];
			pref2[i]=pref2[i-1]+1;
			pref3[i]=pref3[i-1];
		}
		else
		{
			pref1[i]=pref1[i-1];
			pref2[i]=pref2[i-1];
			pref3[i]=pref3[i-1]+1;
		}	
	}
	for (i=1;i<=N;i++)
	{
		if (arr[i]=='2')
			ans=ans+(pref1[i-1]*(pref3[N]-pref3[i]));
	}
	cout<<ans<<"\n";
return 0;
}

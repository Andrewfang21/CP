#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long TC,limit,N,temp,cnt,tc=0;
	cin>>TC;
	
	while (TC--)
	{
		tc++;
		cin>>limit>>N;
		int i,now,arr[N+5];
		temp=cnt=0;
		
		for (i=0;i<N;i++)
		{
			cin>>arr[i];
			temp+=arr[i];
		}
		sort(arr,arr+N,greater<int>() );
		
		cout<<"Scenario #"<<tc<<":\n";
		if (temp<limit)
			cout<<"impossible\n";
		else
		{
			now=i=0;
			while (now<limit)
			{		
				now+=arr[i];
				i++;
				cnt++;
				//cout<<now<<" "<<cnt<<"\n";
			}
			cout<<cnt<<"\n";
		}
	}
return 0;
}

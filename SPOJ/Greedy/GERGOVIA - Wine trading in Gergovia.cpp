#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i;
	
	while (cin>>N)
	{
		if (N==0)	return 0;
		int arr[N+5];

		for (i=0;i<N;i++)
			cin>>arr[i];
			
		long long ans=0;
		for (i=1;i<N;i++)
		{
			arr[i]+=arr[i-1];
			ans+=abs(arr[i-1]);
		}
		cout<<ans<<"\n";
	}
return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long TC,sum,N,i;
	ios_base::sync_with_stdio(false);
	cin>>TC;
	while (TC--)
	{
		cin>>N;
		unsigned long long num[N+5],arr[N+5];
		for (i=1;i<=N;i++)
		{
			cin>>arr[i];
			num[i]=num[i-1]+arr[i];
		}
		sum=0;
		for (i=1;i<N;i++)
		{
			sum+=(num[N]-num[i])-((N-i)*arr[i]);
		}
		cout<<sum<<"\n";
	}
}


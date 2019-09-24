#include<bits/stdc++.h>
using namespace std;

long long C(long long M, long long N)
{
	long long ans=1,temp;
	if (N>(M-N))	N=M-N;
	
	for (temp=0;temp<N;temp++)
		ans=(ans*(M-temp))/(temp+1);
return ans;
}

int main()
{
	long long TC,N,K;
	cin>>TC;

	while (TC--)
	{
		cin>>N>>K;
		cout<<C(N-1,K-1)<<"\n";
	}
return 0;
}

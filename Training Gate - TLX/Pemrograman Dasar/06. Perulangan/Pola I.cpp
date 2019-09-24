#include<bits/stdc++.h>
using namespace std;
int N,K,i;

int main()
{
	cin>>N>>K;
	for (i=1;i<=N;i++)
	{
		if (i%K==0) 
		{
			if (i==N) cout<<"*\n"; else cout<<"* ";
		} else
		if (i==N) cout<<i<<"\n"; else cout<<i<<" ";
	}
return 0;	
}

#include<bits/stdc++.h>
using namespace std;
long long N,K,cnt,temp;

int main()
{
	int TC;
	cin>>TC;
	
	for (int tc=1;tc<=TC;tc++)
	{
		cin>>N>>K;
		cnt=0;	temp=K;
			
		while ((N/K)!=0)
		{
			cnt+=(N/K);
			//cout<<K<<" "<<cnt<<"\n";
			K*=temp;
		}
		cout<<"Case "<<tc<<": "<<cnt<<"\n";
	}
}

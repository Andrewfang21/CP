#include<bits/stdc++.h>
using namespace std;

int main()
{
	string dummy;
	cin>>dummy;
	int N=INT_MAX,M=INT_MAX;
	while ((N!=1)&&(M!=1))
	{
		cin>>N>>M;
		int p=min(M,N);
		int q=min(M,N);
		cout<<p<<" "<<q<<"\n";
	}
return 0;
}

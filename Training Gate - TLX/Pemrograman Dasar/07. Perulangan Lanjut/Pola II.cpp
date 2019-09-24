#include<bits/stdc++.h>
using namespace std;
int N,i,j;

int main()
{
	cin>>N;
	for(i=1;i<=N;i++)
	{
		for(j=N;j>=1;j--)
		{
			if(j<=i) cout<<"*"; else cout<<" ";
		}
		cout<<"\n";
	}
return 0;		
}

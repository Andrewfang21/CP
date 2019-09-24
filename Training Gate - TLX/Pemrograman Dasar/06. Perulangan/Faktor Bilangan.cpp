#include<bits/stdc++.h>
using namespace std;
int N,i;

int main()
{
	cin>>N; 
	for (i=N;i>=1;i--)
		if (N%i==0) cout<<i<<"\n";
return 0;	
}

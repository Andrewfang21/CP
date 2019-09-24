#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long C[60][60],ans,i,j;
	C[0][0]=1;
	for (i=1;i<=50;i++)
		for (j=0;j<=i;j++)
			if ((j==0)||(j==i)) C[i][j]=1; else
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	
	int N;
	cin>>N;
	if ((N%2)!=0)	cout<<0<<"\n"; else
	{
		long long n=N/2;
		ans=(C[2*n][n]/(n+1));
		cout<<ans<<"\n";	
	}	
return 0;	
}
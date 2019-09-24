#include<bits/stdc++.h>
using namespace std;
int M,N,P,i,j,k,A[101][101],B[101][101],C[101][101];

int main()
{
	cin>>N>>M>>P;
	for (i=1;i<=N;i++)
		for(j=1;j<=M;j++)
			cin>>A[i][j];
	
	for (i=1;i<=M;i++)
		for(j=1;j<=P;j++)
			cin>>B[i][j];
	for (i=1;i<=N;i++)
		for(j=1;j<=P;j++)
		{
			C[i][j]=0;
			for(k=1;k<=M;k++)
				C[i][j]+=A[i][k]*B[k][j];
		}
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=P;j++)
			if(j==P) cout<<C[i][j]<<"\n"; else cout<<C[i][j]<<" ";
	}					
return 0;	
}

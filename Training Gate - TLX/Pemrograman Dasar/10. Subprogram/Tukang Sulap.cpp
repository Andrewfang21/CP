#include<bits/stdc++.h>
using namespace std;
int N,i,j,A[1001],B[1001],Q,k,x,y;
char a,b;

int main()
{
	cin>>N;
	for(i=1;i<=N;i++) cin>>A[i];
	for(i=1;i<=N;i++) cin>>B[i];
	cin>>Q;
	for(k=1;k<=Q;k++)
	{
		cin>>a>>x>>b>>y;
		if((a=='A')&&(b=='A')) swap(A[x],A[y]); else 
		if((a=='A')&&(b=='B')) swap(A[x],B[y]); else 
		if((a=='B')&&(b=='A')) swap(B[x],A[y]); else
		if((a=='B')&&(b=='B')) swap(B[x],B[y]);
	}	
	for(i=1;i<=N;i++)
	{
		if(i==N) cout<<A[i]<<"\n"; else cout<<A[i]<<" ";
	}
	for(i=1;i<=N;i++)
	{
		if(i==N) cout<<B[i]<<"\n"; else cout<<B[i]<<" ";
	}
return 0;		
}

#include<bits/stdc++.h>
using namespace std;

int N,M,K,MAXX,ansy,ansx,ans[200][200],arr[200][200];

void reset()
{
	MAXX=pow(10,7);
	
	for (int i=0;i<=105;i++)
		for (int j=0;j<=105;j++)
			arr[i][j]=1;
			
	for (int i=1;i<=N;i++)	
		for (int j=1;j<=M;j++)
			cin>>arr[i][j];
}

int main()
{
	cin>>N>>M>>K;
	reset();
	
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			ans[i][j]=arr[i-1][j]*arr[i+1][j]*arr[i][j-1]*arr[i][j+1];
			
	ansx=ansy=MAXX;
	
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			if (ans[i][j]==K)
				if (j<ansy)
				{
					ansx=i;		ansy=j;
				}
				else
				if (j==ansy)
					ansx=min(ansx,i);
		}
	
	if (ansx==MAXX && ansy==MAXX)
		cout<<"0 0\n";
	else
		cout<<ansx<<" "<<ansy<<"\n";
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,j,Q,a,b,c,d;
	cin>>N;
	int arr[N+5][N+5],hitam[N+5][N+5],putih[N+5][N+5];
	memset(hitam,0,sizeof(hitam));		memset(putih,0,sizeof(putih));
	
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
		{
			cin>>arr[i][j];
			if (((i%2==1)&&(j%2==1))||((i%2==0)&&(j%2==0)))	//hitam
			{
				hitam[i][j]=hitam[i-1][j]+hitam[i][j-1]-hitam[i-1][j-1]+arr[i][j];
				putih[i][j]=putih[i][j]=putih[i-1][j]+putih[i][j-1]-putih[i-1][j-1];
			}
			else
			if (((i%2==0)&&(j%2==1))||((i%2==1)&&(j%2==0)))	//putih
			{
				putih[i][j]=putih[i-1][j]+putih[i][j-1]-putih[i-1][j-1]+arr[i][j];
				hitam[i][j]=hitam[i-1][j]+hitam[i][j-1]-hitam[i-1][j-1];
			}
		}
	/*cout<<"\n";
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
			cout<<hitam[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=N;j++)
			cout<<putih[i][j]<<" ";
		cout<<"\n";
	}*/
	
	
	cin>>Q;
	while (Q--)
	{
		cin>>a>>b>>c>>d;
		int temp1,temp2;
		temp1=hitam[c][d]+hitam[a-1][b-1]-hitam[a-1][d]-hitam[c][b-1];
		temp2=putih[c][d]+putih[a-1][b-1]-putih[a-1][d]-putih[c][b-1];

		cout<<abs(temp1-temp2)<<"\n";
	}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int N,M,i,j,k,l,maks,batuu,stone,nilai,value[55][55],batu[55][55],batas;
int main()
{
	maks=-1;
	memset(value,0,sizeof(value));
	memset(batu,0,sizeof(batu));
	cin>>N>>M>>batas;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
		{
			cin>>value[i][j];
			if (value[i][j]==9999)
			{
				value[i][j]=0;
				batu[i][j]=1;
			}
			value[i][j]=value[i][j]+value[i-1][j]+value[i][j-1]-value[i-1][j-1];
			batu[i][j]=batu[i][j]+batu[i-1][j]+batu[i][j-1]-batu[i-1][j-1];
		}
	}
		
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
		{	
			for (k=i;k<=N;k++)
			{
				for (l=j;l<=M;l++)
				{
					nilai=value[k][l];
					stone=batu[k][l];
					nilai=nilai-value[i-1][l]-value[k][j-1]+value[i-1][j-1];
					stone=stone-batu[i-1][l]-batu[k][j-1]+batu[i-1][j-1];
					
					if ((nilai>maks)&&(stone<=batas))
					{
						maks=nilai;
						batuu=stone;
					}
				}
			}
		}
	}
	cout<<maks<<" "<<batuu<<"\n";
return 0;
}
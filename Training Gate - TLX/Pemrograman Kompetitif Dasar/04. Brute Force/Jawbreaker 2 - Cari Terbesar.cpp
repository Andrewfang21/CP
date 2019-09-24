#include<bits/stdc++.h>
using namespace std;
int i,j,M,N,matriks[50][50],hitung;
bool visited[50][50];

void floodfill(int a,int b, int c)
{
	if ((a>=1)&&(a<=M)&&(b>=1)&&(b<=N)&&(!visited[a][b])&&(matriks[a][b]==c))
	{
		hitung++;
		visited[a][b]=true;
		floodfill(a,b-1,matriks[a][b]);
		floodfill(a,b+1,matriks[a][b]);
		floodfill(a+1,b,matriks[a][b]);
		floodfill(a-1,b,matriks[a][b]);
	}
}
int main()
{
	int nilai=INT_MIN;
	scanf("%d %d",&M,&N);
	
	for (i=1;i<=M;i++)
		for (j=1;j<=N;j++)
			cin>>matriks[i][j];
	
	memset(visited,false,sizeof(visited));		
	for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
		{
			if (!visited[i][j])
			{
				hitung=0;
				floodfill(i,j,matriks[i][j]);
				hitung=hitung*(hitung-1);
				nilai=max(nilai,hitung);
			}
		}	
	}		
	cout<<nilai<<"\n";
return 0;	
}

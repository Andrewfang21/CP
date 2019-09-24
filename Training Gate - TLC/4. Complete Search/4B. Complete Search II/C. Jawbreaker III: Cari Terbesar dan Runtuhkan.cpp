#include<bits/stdc++.h>
using namespace std;
int i,j,M,N,hitung,startr,startc,temp;
bool visited[50][50];
char matriks[50][50],simbol[50][50];

void floodfill(int a,int b, char c)
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

void titik(int a, int b, char c)
{
	if ((a>=1)&&(a<=M)&&(b>=1)&&(b<=N)&&(!visited[a][b])&&(matriks[a][b]==c))
	{
		visited[a][b]=true;
		simbol[a][b]='.';
		titik(a,b-1,matriks[a][b]);
		titik(a,b+1,matriks[a][b]);
		titik(a+1,b,matriks[a][b]);
		titik(a-1,b,matriks[a][b]);
	}
}
int main()
{
	int nilai=INT_MIN;
	scanf("%d %d",&M,&N);
	
	for (i=1;i<=M;i++)
		for (j=1;j<=N;j++)
		{
			cin>>matriks[i][j];
			simbol[i][j]=matriks[i][j];
		}
	
	
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
				if (nilai==hitung)
				{
					startr=i; startc=j;
				}
			}
		}	
	}
	memset(visited,false,sizeof(visited));			
	titik(startr,startc,matriks[startr][startc]);
	
	for (i=M;i>=1;i--)
	{
		for (j=1;j<=N;j++)
		{
			if (simbol[i][j]=='.')
			{
				for (temp=i;temp>=1;temp--)
				{
					if (simbol[temp][j]!='.')
					{
						while(simbol[temp+1][j]=='.') 
						{
							swap(simbol[temp+1][j],simbol[temp][j]);
							if (temp<M) temp++;
						}
					}
				}
			}
		}
	}
	for (i=1;i<=M;i++)
	{
		for (j=1;j<=N;j++)
		{
			if (j==N) cout<<simbol[i][j]<<"\n";
			else cout<<simbol[i][j]<<" ";
		}
	}
return 0;	
}
#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int x,y;
}K,B;
int M,N,i,j,count1,count2,ans;
char matriks[505][505];
bool visited[505][505];

void floodfill(int a, int b, int& hitung)
{
	if ((a>=1)&&(a<=N)&&(b>=1)&&(b<=M)&&(!visited[a][b])&&(matriks[a][b]!='#'))
	{
		visited[a][b]=true;
		hitung++;
		floodfill(a+1,b,hitung);
		floodfill(a-1,b,hitung);
		floodfill(a,b+1,hitung);
		floodfill(a,b-1,hitung);
	}
}
int main()
{
	scanf("%d %d",&M,&N);
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
		{
			cin>>matriks[i][j];
			if (matriks[i][j]=='K')
			{
				K.x=i;
				K.y=j;
			} else
			if (matriks[i][j]=='B')
			{
				B.x=i;
				B.y=j;
			}
		}
	count1=count2=0;
	memset(visited,false,sizeof(visited));
	floodfill(K.x,K.y,count1);
	memset(visited,false,sizeof(visited));
	floodfill(B.x,B.y,count2);
	
	ans=abs(count1-count2);
	if (count1>count2)
		printf("K %d\n",ans); else
	if (count1<count2)
		printf("B %d\n",ans); else
	printf("SERI\n");
return 0;	
}
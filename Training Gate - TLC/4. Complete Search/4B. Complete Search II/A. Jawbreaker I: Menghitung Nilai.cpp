#include<bits/stdc++.h>
using namespace std;
int M,N,i,j,x,y,T,matriks[30][30];
bool visited[30][30];

void floodfill(int a,int b)
{
	if ((a>=0)&&(a<M)&&(b>=0)&&(b<N)&&(!visited[a][b])&&(matriks[a][b]==matriks[x][y]))
	{
		visited[a][b]=true;
		T++;
		floodfill(a+1,b);
		floodfill(a-1,b);
		floodfill(a,b+1);
		floodfill(a,b-1);
	}
}

int main()
{
	memset(visited,false,sizeof(visited));
	cin>>M>>N;
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
			cin>>matriks[i][j];
	
	cin>>x>>y;
	floodfill(x,y);
	cout<<T*(T-1)<<"\n";
return 0;	
}
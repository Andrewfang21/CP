#include<bits/stdc++.h>
using namespace std;
int N,M,i,j;
char matriks[26][26],target[8][26][26];
bool visited[26][26];

void print(char bla[26][26])
{
	cout<<"\n";
	for (int x=1;x<=N;x++)
	{
		for (int y=1;y<=M;y++)
			cout<<bla[x][y]<<" ";
		cout<<"\n";
	}
}

void mark(int x, int y, char num)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)&&(matriks[x][y]==num)&&(!visited[x][y]))
	{
		visited[x][y]=true;
		mark(x+1,y,num);
		mark(x-1,y,num);
		mark(x,y+1,num);
		mark(x,y-1,num);
	}
}

int floodfill(int x, int y, char num)
{
	if ((x>=1)&&(x<=N)&&(y>=1)&&(y<=M)&&(!visited[x][y])&&(matriks[x][y]==num)&&(matriks[x][y]!='0'))
	{
		matriks[x][y]='0';
		visited[x][y]=true;
		return (1+floodfill(x+1,y,num)+floodfill(x-1,y,num)+floodfill(x,y+1,num)+floodfill(x,y-1,num));
	}
	else return 0;
}

void runtuh()
{
	int temp1,temp2,temp3;
	for (temp1=1;temp1<=M;temp1++)
	{
		for (temp2=1;temp2<=N;temp2++)
		{
			if (matriks[temp2][temp1]=='0')
			{
				temp3=temp2;
				while (temp3>1)
				{
					swap(matriks[temp3][temp1],matriks[temp3-1][temp1]);
					if (temp3>1)	temp3--;
				}
			}
		}
	}
}

void backup(int lol)
{
	int x,y;
	for (x=1;x<=N;x++)
		for (y=1;y<=M;y++)
			target[lol][x][y]=matriks[x][y];
}

void paste(int lol)
{
	int x,y;
	for (x=1;x<=N;x++)
		for (y=1;y<=M;y++)
		{
			matriks[x][y]=target[lol][x][y];
			visited[x][y]=false;
		}
}

int solve(int lol)
{
	int temp1,temp2;
	runtuh();
	backup(lol);	//mengcopy array matriks ke array save
	//print(matriks);
	
	memset(visited,false,sizeof(visited));
	int jwb=0;
	
	for (temp1=1;temp1<=N;temp1++)
	{
		for (temp2=1;temp2<=M;temp2++)
		{
			if ((!visited[temp1][temp2])&&(matriks[temp1][temp2]!='0'))
			{
				if ((matriks[temp1][temp2]==matriks[i+1][temp2])||(matriks[temp1][temp2]==matriks[temp1-1][temp2])||(matriks[temp1][temp2]==matriks[temp1][temp2+1])||(matriks[temp1][temp2]==matriks[temp1][temp2-1]))
				{
					int point=matriks[temp1][temp2];
					int ans=floodfill(temp1,temp2,matriks[temp1][temp2]);
					ans=ans*(ans-1);
					jwb=max(jwb,ans+solve(lol+1));
					paste(lol);	//menyalin kembali array
					
					mark(temp1,temp2,point);
					//print(matriks);	
				}
			}
		}
	}
return jwb;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
		{
			cin>>matriks[i][j];
		}
	}
	cout<<solve(1)<<"\n";
return 0;
}

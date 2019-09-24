#include<bits/stdc++.h>
using namespace std;
int row,column;
char matriks[30][30];

int main()
{
	int batas=-1,i,j,hitung;
	scanf("%d %d",&row,&column);
	
	for (i=1;i<=row;i++)
		for (j=1;j<=column;j++)
			cin>>matriks[i][j];
	bool boo;
	while (!boo)
	{
		batas=-1;
	for (i=row;i>=1;i--)
	{
		hitung=0;
		for (j=1;j<=column;j++)
		{
			if (matriks[i][j]=='1') hitung++;				
		}
		if (hitung==column)
		{
			for (j=1;j<=column;j++)
				matriks[i][j]='0';
		if (batas==-1) batas=i;		
		}		
	}
		for (j=1;j<=column;j++)
		{
			for (i=batas;i>=1;i--)
			{
				int temp=i;
				if (matriks[temp][j]=='1')
				{
					while (matriks[temp+1][j]=='0')
					{
						swap(matriks[temp+1][j],matriks[temp][j]);	
						if (temp!=row) temp++;
					}	
				}	
			}	
		}
		boo=true;
		for (i=row;i>=1;i--)
		{
		hitung=0;
		for (j=1;j<=column;j++)
		{
			if (matriks[i][j]=='1') hitung++;				
		}
			if (hitung==column)
			{
				boo=false;
			}		
		}			
	}
	for (i=1;i<=row;i++)
	{
		for (j=1;j<=column;j++)
		{
			cout<<matriks[i][j];
		}
		cout<<"\n";
	}
return 0;
}
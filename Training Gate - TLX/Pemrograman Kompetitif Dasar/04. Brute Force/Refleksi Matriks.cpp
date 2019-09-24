#include<bits/stdc++.h>
using namespace std;
int N,i,j,arr1[100][100],arr2[100][100];

bool identik()
{
	int temp1,temp2; bool boo=false;
	for (temp1=1;temp1<=N;temp1++)
	{
		for (temp2=1;temp2<=N;temp2++)
		{
			if (arr1[temp1][temp2]!=arr2[temp1][temp2])
				{
					boo=true;
					break;
				}
		}
	}
	return boo;
}

bool vertikal()
{
	int temp1,temp2; bool boo=false;
	for (temp1=1;temp1<=N;temp1++)
	{
		for (temp2=1;temp2<=N;temp2++)
		{
			if (arr1[temp1][temp2]!=arr2[temp1][N-temp2+1])
				{
					boo=true;
					break;
				}
		}
	}
	return boo;
}

bool horisontal()
{
	int temp1,temp2; bool boo=false;
	for (temp1=1;temp1<=N;temp1++)
	{
		for (temp2=1;temp2<=N;temp2++)
		{
			if (arr1[temp1][temp2]!=arr2[N-temp1+1][temp2])
				{
					boo=true;
					break;
				}	
		}
	}
	return boo;
}

bool diagonalkanan()
{
	int temp1,temp2; bool boo=false;
	for (temp1=1;temp1<=N;temp1++)
	{
		for (temp2=1;temp2<=N;temp2++)
		{
			if (arr1[temp1][temp2]!=arr2[temp2][temp1])
				{
					boo=true;
					break;
				}
		}
	}
	return boo;
}

bool diagonalkiri()
{
	int temp1,temp2; bool boo=false;
	for (temp1=1;temp1<=N;temp1++)
	{
		for (temp2=1;temp2<=N;temp2++)
		{
			if (arr1[temp1][temp2]!=arr2[N-temp2+1][N-temp1+1])
			{
				boo=true;
				break;
			}
		}
	}
	return boo;
}
int main()
{
	cin>>N>>N;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin>>arr1[i][j];
	
	cin>>N>>N;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin>>arr2[i][j];
	
	if (!identik()) cout<<"identik\n"; else
	if (!vertikal())	cout<<"vertikal\n"; else
	if (!horisontal()) cout<<"horisontal\n"; else
	if (!diagonalkanan()) cout<<"diagonal kanan bawah\n"; else
	if (!diagonalkiri()) cout<<"diagonal kiri bawah\n"; else
	cout<<"tidak identik\n";
return 0;				
}

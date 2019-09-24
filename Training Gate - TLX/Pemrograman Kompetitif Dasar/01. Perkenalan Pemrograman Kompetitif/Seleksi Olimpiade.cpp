#include<bits/stdc++.h>
using namespace std;
int N,M,TC,i,j,nilai1[81],nilai2[81],nilai3[81];
string name,nama[81];
bool boo;

void sort()
{
	int temp1,temp2;
	for (temp1=1;temp1<=N-1;temp1++)
		for (temp2=temp1;temp2<=N;temp2++)
			if (nilai3[temp1]<nilai3[temp2])
			{
				swap(nilai3[temp1],nilai3[temp2]);
				swap(nilai2[temp1],nilai2[temp2]);
				swap(nilai1[temp1],nilai1[temp2]);
				swap(nama[temp1],nama[temp2]);
			} else
			if (nilai3[i]==nilai3[j])
			{
				if (nilai2[i]==nilai2[j])
				{
					if (nilai1[i]<=nilai1[j])
					{
						swap(nilai3[temp1],nilai3[temp2]);
						swap(nilai2[temp1],nilai2[temp2]);
						swap(nilai1[temp1],nilai1[temp2]);
						swap(nama[temp1],nama[temp2]);
					}
				else if(nilai2[temp1]<nilai2[temp2])
					{	
						swap(nilai3[temp1],nilai3[temp2]);
						swap(nilai2[temp1],nilai2[temp2]);
						swap(nilai1[temp1],nilai1[temp2]);
						swap(nama[temp1],nama[temp2]);
					}	
				}
			}
}
int main()
{
	cin>>TC;
	for (i=1;i<=TC;i++)
	{
		boo=false;
		cin>>N>>M;
		cin>>name;
		for (j=1;j<=N;j++)
			cin>>nama[j]>>nilai1[j]>>nilai2[j]>>nilai3[j];
		sort();
		for (j=1;j<=M;j++)
			if (name==nama[j])
			{
				if(nilai3[j]>nilai3[M]) boo=true; else
				if (nilai3[j]==nilai3[M])
				{
					if (nilai2[j]>nilai2[M]) boo=true; else
					if (nilai2[j]==nilai2[M])
					{
						if (nilai1[j]>=nilai1[M]) boo=true;
					}
				}
			}
		if (boo) cout<<"YA\n"; else cout<<"TIDAK\n";	
	}
return 0;	
}

#include<bits/stdc++.h>
#define mod 26101991
using namespace std;
long long N,row[105],column[105],MCM[105][105],i,j,k,temp,best,hitung[105][105],mins,ans;

long long first()
{
	mins=0;
	for (i=1;i<=N;i++)
		MCM[i][i]=0;

	for (int L=2;L<=N;L++)
	{
		for (i=1;i<=N-L+1;i++)
		{
			j=i+L-1;
			MCM[i][j]=LLONG_MAX;
			for (k=i;k<=j-1;k++)
			{
				mins=MCM[i][k]+MCM[k+1][j]+row[i]*column[k]*column[j];
				if (mins<MCM[i][j])	MCM[i][j]=mins;
			}
		}
	}
	return MCM[1][N];
}

long long second()
{
	mins=0;
	memset(hitung,0,sizeof(hitung));
	for (i=1;i<=N;i++)
	{
		MCM[i][i]=0;
		hitung[i][i]=1;
	}

	for (long long L=2;L<=N;L++)
	{
		for (i=1;i<=N-L+1;i++)
		{
			j=i+L-1;
			MCM[i][j]=LLONG_MAX;
			for (k=i;k<=j-1;k++)
			{
				mins=MCM[i][k]+MCM[k+1][j]+row[i]*column[k]*column[j];
				
				if ((mins<MCM[i][j]))
				{
					hitung[i][j]=((hitung[i][k]%mod)*(hitung[k+1][j]%mod)%mod);
					MCM[i][j]=mins;	
				}
				else
				if (mins==MCM[i][j])	hitung[i][j]+=((hitung[i][k]%mod)*(hitung[k+1][j]%mod)%mod);
			}
		}
	}
return hitung[1][N]%mod;
}

long long third()
{
	mins=0;
	memset(hitung,0,sizeof(hitung));
	for (i=1;i<=N;i++)
	{
		MCM[i][i]=0;
		hitung[i][i]=1;
	}

	for (long long L=2;L<=N;L++)
	{
		for (i=1;i<=N-L+1;i++)
		{
			j=i+L-1;
			MCM[i][j]=LLONG_MAX;
			for (k=i;k<=j-1;k++)
			{
				mins=MCM[i][k]+MCM[k+1][j]+row[i]*column[k]*column[j];
				hitung[i][j]+=((hitung[i][k]%mod)*(hitung[k+1][j]%mod)%mod);
				if (mins<MCM[i][j])	MCM[i][j]=mins;
			}
		}
	}
return hitung[1][N]%mod;
}

int main()
{
	scanf("%lld",&N);
	for (i=1;i<=N+1;i++)
	{
		if (i==1)	scanf("%lld",&row[1]); else
		if (i==N+1)	scanf("%lld",&column[N]); else
		{
			scanf("%lld",&temp);
			column[i-1]=temp;
			row[i]=temp;
		}
	}
	long long tipe;
	scanf("%lld",&tipe);
	if (tipe==1)
		ans=first();
	else
	if (tipe==2)
		ans=second();
	else
		ans=third();
	
	printf("%lld\n",ans);
return 0;			
}

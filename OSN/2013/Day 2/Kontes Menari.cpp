#include<bits/stdc++.h>
using namespace std;
 
int N,R,juri,bonus,i,j,save[15],hitung[70000],mini,maks,nilai1[25],nilai2[25];
char gerak1[25],gerak2[25];
bool used[25];
 
void proses(int a)
{
	int temp1,sum=0,temp2[a+5];
	bool performed;
	performed=false;
	for (temp1=1;temp1<a;temp1++)
		temp2[temp1]=nilai2[temp1];
 
	for (temp1=1;temp1<a;temp1++)
	{
		if (temp1>1)
		{
			if (gerak2[temp1-1]=='L') temp2[temp1]/=2;
			if (gerak2[temp1-1]=='P') temp2[temp1]*=2;
			if (gerak2[temp1-1]=='Y') performed=true;
			if (performed) temp2[temp1]+=bonus;
		}
		sum+=temp2[temp1];
	}
	hitung[sum]++;
}
 
void Permutasi(int awal, int banyak, int batas)
{
	int temp2;
	if (awal>batas) proses(awal); else
	for (temp2=1;temp2<=banyak;temp2++)
	{
		if (!used[temp2])
		{
			used[temp2]=true;
			gerak2[awal]=gerak1[temp2];
			nilai2[awal]=nilai1[temp2];
 
			Permutasi(awal+1,banyak,batas);
 
			used[temp2]=false;
		}
	}
}
 
int main()
{
	string dummy;
	getline(cin,dummy);
	cin>>N>>R>>bonus>>juri;
 
	j=0;	maks=0;
 
	for (i=1;i<=N;i++)
		cin>>nilai1[i]>>gerak1[i];
 
	for (i=1;i<=25;i++)
		used[i]=false;
 
	Permutasi(1,N,R);
 
	for (j=1;j<=juri;j++)
	{
		cin>>mini;
		if (mini>21000) cout<<0<<"\n";
		else
		{
			maks=0;
			for (int k=mini+1;k<=21000;k++)
				maks+=hitung[k];
			cout<<maks<<"\n";	
		}	
	}	
return 0;			
}

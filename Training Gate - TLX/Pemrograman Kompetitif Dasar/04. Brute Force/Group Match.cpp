#include<bits/stdc++.h>
using namespace std;
int poin[10],tim[10],TC,i,j,N;
bool bisa;

void cek()
{
	int temp;
	bool boo=true;
	for (temp=1;temp<=N;temp++)
		if (tim[temp]!=poin[temp])
			boo=false;
	if (boo) bisa=true;	
}

void tanding(int a,int b,string hasil)
{
		int temp1,temp2;
		if (hasil=="menang") poin[a]+=3;
		if (hasil=="seri")
		{
			poin[a]+=1;	poin[b]+=1;
		}
		if (hasil=="kalah") poin[b]+=3;
		
		if ((a==N-1)&&(b==N))
			cek();
		else
		if (b==N)
			tanding(a+1,a+1,"mulai");
		else
		{
			tanding(a,b+1,"menang");
			poin[a]-=3;
			tanding(a,b+1,"seri");
			poin[a]-=1;	poin[b+1]-=1;
			tanding(a,b+1,"kalah");
			poin[b+1]-=3;
		}	
}

int main()
{
	cin>>TC;
	for (i=1;i<=TC;i++)
	{
		cin>>N;
		for (j=1;j<=N;j++)
			cin>>tim[j];
		
		bisa=false;
		memset(poin,0,sizeof(poin));
		tanding(1,1,"mulai");
		
		if 	(bisa) cout<<"YES\n"; else cout<<"NO\n";
	}
return 0;	
}

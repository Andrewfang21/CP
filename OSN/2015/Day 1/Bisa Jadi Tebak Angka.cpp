#include<bits/stdc++.h>
using namespace std;
char c[20];
string ans;
int N,K;

void ternary2(int start, int finish)
{
	int panjang,mid1,mid2,last,choose=-1,choose2=-1,sum=0;
	if (start==finish)
	{
		printf("0 %d\n",start);
		fflush(stdout);
	}
	else
	{
		panjang=(finish-start)/3;
		mid1=start+panjang;		mid2=start+2*panjang;
		//printf("%d %d\n",start,finish);
		for (int i=start;i<=mid2;i+=2)
			sum++;
		printf("%d",sum);
		
		for (int i=start;i<=mid2;i+=2)
		{
			last=i;
			if (i<=mid1)
			{
				choose=i;
				printf(" %d",i-1);
			}
			else
			{
				if (choose2==-1)
					choose2=i;
				printf(" %d",i);
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%s",c);
		ans=c;
		
		if (ans=="YA")
			ternary2(choose2,last);
		else
		if (ans=="TIDAK")
			ternary2(last+2,finish);
		else
			ternary2(start,choose);
	}
}

void ternary1(int start, int finish)
{
	int panjang,mid1,mid2,i,sum=0,last;
	if (start==finish)
	{
		printf("0 %d\n",start);
		fflush(stdout);
	}
	else
	{
		panjang=finish-start+1;
		mid1=start+(panjang/3);		mid2=finish-(panjang/3);
		
		for (i=start;i<=mid2;i+=2)
			sum++;
		
		printf("%d",sum);
		for (i=start;i<=mid2;i+=2)
		{
			last=i;
			printf(" %d",i);
		}
		printf("\n");
		fflush(stdout);
		
		scanf("%s",c);
		ans=c;
		
		if (ans=="YA")
			ternary2(start,last);
		else
		if (ans=="TIDAK")
			ternary1(mid2+1,finish);
		else
			ternary2(start+1,last+1);
	}
}

int main()
{
	scanf("%s",c);
	scanf("%d %d",&N,&K);
	
	ternary1(1,N);
return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int jumlah,tinggi,i;
	scanf("%d %d",&jumlah,&tinggi);
	int bebek[jumlah+5];
	
	for (i=0;i<jumlah;i++)
		scanf("%d",&bebek[i]);
	sort(bebek,bebek+jumlah,greater<int>());
	
	int sum=0,temp;
	while (sum<tinggi)
	{
		sum+=bebek[temp];
		temp++;
	}
	printf("%d\n",temp);
return 0;	
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,posisi,first;
	scanf("%d",&N);
	long long harga[N+5],minimum,uang,akhir[55],panjang,diff,num[N+5],temp[N+5];
	for (i=0;i<=N;i++)
		scanf("%lld",&harga[i]);
	scanf("%lld",&uang);
	memset(num,0,sizeof(num));
	minimum=harga[1];	posisi=1;
	for (i=2;i<=N;i++)
	{
		if (harga[i]<=minimum)
		{
			minimum=harga[i];
			posisi=i;	
		}	
	}	
	if ((uang<minimum)&&(uang<harga[0]))
	{
		printf("0\n");
		return 0;
	}
	else
	if ((uang<minimum)&&(uang>=harga[0]))
	{
		printf("1\n0\n0\n");
		return 0;
	}
	{
		panjang=0;
		first=posisi;  //angka terdepan adalah angka yang termurah//
		num[posisi]++;
		uang-=harga[posisi];
		if (harga[0]<harga[posisi])
		{
			minimum=0;
			posisi=0;
		}
		panjang++;	
	}
	panjang+=(uang/harga[posisi]);

	uang-=((panjang-1)*harga[posisi]);
	num[posisi]+=(panjang-1);
	
	for (i=N;i>first;i--)
	{
		if ((uang+harga[first])>=harga[i])
		{
			uang=uang+harga[first]-harga[i];
			num[first]--;
			first=i;
			num[i]++;
			break;
		}
	}
	
	for (i=N;i>posisi;i--)
	{
		if ((uang+harga[posisi])>=harga[i])
		{
			diff=uang/(harga[i]-harga[posisi]);
			if (diff>=num[posisi]) //sanggup ganti semua ngga?//
			{
				num[i]+=num[posisi];
				num[posisi]=0;
			}
			else
			{
				num[posisi]-=diff;
				uang+=(diff*harga[posisi]);
				
				num[i]+=diff;
				uang-=(diff*harga[i]);
			}
		}
	}
	
	int batas=N;
	for (i=0;i<=N;i++)
		temp[i]=num[i];	//simpan dulu//

	cout<<panjang<<"\n";
	if (panjang<=50)
	{
		while(batas>=0)
		{
			for (i=0;i<num[batas];i++)
				cout<<batas;
			batas--;
		}	
		printf("\n");
		batas=N;
		
		while(batas>=0)
		{
			for (i=0;i<num[batas];i++)
				cout<<batas;
			batas--;
		}
		printf("\n");
	}
	else
	{
		batas=N;
	
		for (i=0;i<50;i++)	//print 50 digit pertama//
		{
			while (temp[batas]==0)	batas--;
			cout<<batas;
			temp[batas]--;
		}
		printf("\n");
		batas=0;
		
		for (i=0;i<50;i++)
		{
			while(num[batas]==0) batas++;
			akhir[i]=batas;
			num[batas]--;
		}
		
		for(i=49;i>=0;i--)
			printf("%d",akhir[i]);
		printf("\n"); 
	}
return 0;
}
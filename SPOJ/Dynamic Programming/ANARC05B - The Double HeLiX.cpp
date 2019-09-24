#include<bits/stdc++.h>
using namespace std;
map<int,bool>found;
int N,M,A[10005],B[10005];
long long sumA[10005],sumB[10005],ans;

int search(string arr, int num)
{
	int kiri,kanan,tengah;
		
	if (arr=="A")
	{
		kiri=1;	kanan=N;
		while (kiri<=kanan)
		{
			tengah=(kiri+kanan)/2;
			if (A[tengah]<num)
				kiri=tengah+1;
			else
			if (A[tengah]>num)
				kanan=tengah-1;
			else
				return tengah;
		}
	}
	else
	if (arr=="B")
	{
		kiri=1;	kanan=M;
		while (kiri<=kanan)
		{
			tengah=(kiri+kanan)/2;
			if (B[tengah]<num)
				kiri=tengah+1;
			else
			if (B[tengah]>num)
				kanan=tengah-1;
			else
				return tengah;
		}
	}
}

int main()
{
	while (cin>>N)
	{
		int i,now,u,nowA,nowB,ans=0;
		if (N==0)	return 0;
		memset(sumA,0,sizeof(sumA));	memset(sumB,0,sizeof(sumB));
		memset(A,0,sizeof(A));		memset(B,0,sizeof(B));
		deque<int>vec;
		
		for (i=1;i<=N;i++)
		{
			cin>>A[i];
			found[A[i]]=true;
			sumA[i]=sumA[i-1]+A[i];
		}
		cin>>M;
		for (i=1;i<=M;i++)
		{
			cin>>B[i];
			if (found[B[i]])	vec.push_back(B[i]);
			sumB[i]=sumB[i-1]+B[i];
		}
		
		now=0;		nowA=nowB=0;
		
		while (!vec.empty())
		{
			int u,x,y;
			u=vec.front();	vec.pop_front();
			x=search("A",u);	y=search("B",u);
			
			if ((sumA[x]-sumA[nowA])>=(sumB[y]-sumB[nowB]))
			{
				ans+=(sumA[x]-sumA[nowA]);
				nowA=x;		nowB=y;
				cout<<nowA<<" "<<nowB<<" "<<ans<<"\n";
			}
			else
			{
				ans+=(sumB[y]-sumB[nowB]);
				nowA=x;		nowB=y;
				cout<<nowA<<" "<<nowB<<" "<<ans<<"\n";
			}
		}
		if ((nowA!=N)||(nowB!=M))
		{
			int temp1=sumA[N]-sumA[nowA-1],temp2=sumB[N]-sumB[nowB-1];
			ans+=max(temp1,temp2);
		}
		cout<<ans<<"\n";
	}
return 0;
}

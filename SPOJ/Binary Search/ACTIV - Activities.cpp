#include<bits/stdc++.h>
#define finish first
#define start second
using namespace std;
vector<pair<int,int> >vec;
int N;

long long pangkat(int a, int b)
{
	if (b==0)	return 1;
	if (b==1)	return a;
	if (b%2==0)
	{
		int temp=pangkat(a,b/2);
		return (temp*temp);
	}
	if (b%2==1)
	{
		int temp=pangkat(a,b/2);
		return (a*temp*temp);
	}
}

int search(int index, int num)
{
	int kiri,kanan,up,tengah;
	kiri=index+1;	kanan=N-1;
	up=-1;
	while(kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		
		if (vec[tengah].start>=num)
		{
			up=tengah;
			kanan=tengah-1;
		}
		else
			kiri=tengah+1;
	}
	if (up>0)
		return up;
	else return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	while (cin>>N)
	{
		int i,x,j,a,b;
		long long res=0,lis[N+5];
		bool yes=false;
		
		if (N==-1)
			return 0;
		
		for (i=0;i<N;i++)
		{
			cin>>a>>b;
			vec.push_back(make_pair(b,a));
			lis[i]=1;
		}
		sort(vec.begin(),vec.end());
		
		for (i=0;i<N;i++)
		{
			x=search(i,vec[i].finish);
			
			//	printf("i= %d  lis[%d]=%d\n",i,i,lis[i]);
			if (x!=-1)
			{
				for (j=x;j<N;j++)
				{
					lis[j]+=lis[i];
				}
			}	
			res+=lis[i];
			res%=pangkat(10,8);
		}
		
	if (res<10)
		cout<<"0000000"<<res<<"\n";
	else
	if (res<100)
		cout<<"000000"<<res<<"\n";
	else
	if (res<1000)
		cout<<"00000"<<res<<"\n";
	else
	if (res<10000)
		cout<<"0000"<<res<<"\n";
	else
	if (res<100000)
		cout<<"000"<<res<<"\n";
	else
	if (res<1000000)
		cout<<"00"<<res<<"\n";
	else
	if (res<10000000)
		cout<<"0"<<res<<"\n";
	else
		cout<<res<<"\n";
	
	vec.clear();
	}
return 0;
}

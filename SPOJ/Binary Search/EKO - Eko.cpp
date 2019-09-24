#include<bits/stdc++.h>
using namespace std;
vector<long long>vec;
long long N,K;

bool check(long long num)
{
	long long i,cnt=0;
	for (i=0;i<vec.size();i++)
	{
		if (num<=vec[i])
		{
			cnt+=(vec[i]-num);
			if (cnt>=K)
				return true;
		}
	}
return false;
}

long long search(long long num)
{
	long long kiri,kanan,tengah,up;
	kiri=0;		kanan=num;
	
	while (kiri<=kanan)
	{
		tengah=(kiri+kanan)/2;
		
		if (check(tengah))
		{
			up=tengah;
			kiri=tengah+1;
		}
		else
			kanan=tengah-1;
	}
return up;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>K;
	long long i,a,maks=-1,res=0;
	
	for (i=0;i<N;i++)
	{
		cin>>a;
		vec.push_back(a);
		if (maks<a)
			maks=a;
	}
	
	res=search(maks);
	cout<<res<<"\n";
return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long MINN=LLONG_MIN,segtree[1000005],arr[100005];

void build_segtree(int kiri, int kanan, int pos)
{
	if (kiri==kanan)
	{
		segtree[pos]=arr[kiri];
		return;
	}
		
	int mid=(kiri+kanan)/2;
	
	build_segtree(kiri,mid,2*pos);
	build_segtree(mid+1,kanan,2*pos+1);
	
segtree[pos]=max(segtree[2*pos], segtree[2*pos+1]);
}

int RMQ(int qleft, int qright, int kiri, int kanan, int pos)
{
	if (qleft>kanan || qright<kiri)
		return MINN;
		
	if (qleft<=kiri && qright>=kanan)
		return segtree[pos];
		
	int mid=(kiri+kanan)/2;
	
return max(RMQ(qleft,qright,kiri,mid,2*pos),
		   RMQ(qleft,qright,mid+1,kanan,2*pos+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int N,i,K,res;
	cin>>N;
	
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	build_segtree(1,N,1);
	cin>>K;
	
	for (i=1;i+K-1<=N;i++)
	{
		res=RMQ(i,i+K-1,1,N,1);
		
		if (i+K-1==N)
			cout<<res<<"\n";
		else
			cout<<res<<" ";
	}
return 0;
}

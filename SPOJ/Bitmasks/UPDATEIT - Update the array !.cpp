#include<bits/stdc++.h>
using namespace std;
int segtree[40005],lazy[40005],INF=10000000;

void update(int left, int right, int qleft, int qright, int pos, int val)
{
	cout<<left<<"  "<<right<<"\n";
	if (lazy[pos]!=0)
	{
		segtree[pos]+=lazy[pos];
		
		if (left!=right)
		{
			lazy[2*pos]+=lazy[pos];
			lazy[2*pos+1]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	
	if (qleft>right || qright<left)
		return;
	
	if (qleft<=left && qright>=right)
	{
		segtree[pos]+=val;
		
		if (left!=right)
		{
			lazy[2*pos]+=val;
			lazy[2*pos+1]+=val;
		}
	}
	int mid=(left+right)/2;

	update(left,mid,qleft,qright,2*pos,val);
	update(mid+1,right,qleft,qright,2*pos+1,val);
}

int RMQ(int left, int right, int qleft, int qright, int pos)
{
	if (qright<left || qleft>right)
		return INF;
	
	if (qleft<=left && qright>=right)
		return segtree[pos];
		
	int mid=(left+right)/2;

return min(RMQ(left,mid,qleft,qright,2*pos),
		   RMQ(mid+1,right,qleft,qright,2*pos+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,N,Q,i,value,left,right,num;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>Q;
		memset(segtree,0,sizeof(segtree));
		memset(lazy,0,sizeof(lazy));
		N++;
		
		for (i=1;i<=N;i++)
		{
			cin>>left>>right>>value;
			update(1,N,left+1,right+1,1,value);
		}
		
		while (Q--)
		{
			cin>>num;
			cout<<RMQ(1,N,num+1,num+1,1)<<"\n";
		}
	}
return 0;
}

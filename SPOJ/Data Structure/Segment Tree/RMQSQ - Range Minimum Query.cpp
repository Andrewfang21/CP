#include<bits/stdc++.h>
using namespace std;
int segtree[400005], arr[100005],INF=2*pow(10,8);

int RMQ(int qleft, int qright, int left, int right, int pos)
{
	if (qleft<=left && qright>=right)
		return segtree[pos];
		
	if (qleft>right || qright<left)
		return INF;
		
	int mid=(left+right)/2;
	
return min(RMQ(qleft,qright,left,mid,2*pos),
		   RMQ(qleft,qright,mid+1,right,2*pos+1));
}

void build_segtree(int left, int right, int pos)
{
	if (left==right)
	{
		segtree[pos]=arr[left];
		return;
	}
	
	int mid=(left+right)/2;
	build_segtree(left,mid,2*pos);
	build_segtree(mid+1,right,2*pos+1);
	
	segtree[pos]=min(segtree[2*pos], segtree[2*pos+1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i,Q,left,right;
	cin>>N;
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	build_segtree(1,N,1);
	
	cin>>Q;
	while (Q--)
	{
		cin>>left>>right;
		left++;		right++;
		
		cout<<RMQ(left,right,1,N,1)<<"\n";
	} 
return 0;
}

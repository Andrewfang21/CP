#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N,Q,arr[100005],update[100005],kiri,kanan,value;

void compute()
{
	ll res=0;
	for (int i=0;i<N;i++)
	{
		res+=update[i];
		arr[i]+=res;
	}
}

void reset()
{
	memset(arr,0,sizeof(arr));
	memset(update,0,sizeof(update));
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	
	while(TC--)
	{
		cin>>N>>Q;
		reset();
		
		while (Q--)
		{
			cin>>kiri>>kanan>>value;
			update[kiri]+=value;		update[kanan+1]-=value;
		}
		compute();
		cin>>Q;
		
		while (Q--)
		{
			int i;
			cin>>i;
			cout<<arr[i]<<"\n";
		}
	}
return 0;
}

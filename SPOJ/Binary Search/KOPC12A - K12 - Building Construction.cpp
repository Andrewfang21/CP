#include<bits/stdc++.h>
using namespace std;
long long ans;
int height[10005],cost[10005],N;
double kiri,kanan;

long long check(int num)
{
	long long res=0;
	for (int i=1;i<=N;i++)
		res+=((abs(num-height[i]))*cost[i]);
return res;

}

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,INF=2*pow(10,8),i,t1,t2,x,y;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		int kanan=-INF;
		for (i=1;i<=N;i++)
		{
			cin>>height[i];
			kanan=max(kanan,height[i]);
		}
		for (i=1;i<=N;i++)
			cin>>cost[i];
		
		kiri=1;
		for (int temp=1;temp<=20;temp++)
		{
			t1=kiri+ceil((kanan-kiri)/3);		t2=kiri+2*ceil((kanan-kiri)/3);
			
			x=check(t1);		y=check(t2);
			
			cout<<kiri<<" "<<kanan<<"\n";
			cout<<t1<<" "<<t2<<"\n\n";
			
			if (x>=y)
				kiri=t1;
			else
				kanan=t2;
		}
		ans=check(kiri);
		cout<<ans<<"\n";
	}
return 0;
}

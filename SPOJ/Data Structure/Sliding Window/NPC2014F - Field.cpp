#include<bits/stdc++.h>
using namespace std;
int Q,num[30],cnt[30];
char q[30];

bool lebih()
{
	int temp;
	for (temp=1;temp<=Q;temp++)
		if (cnt[q[temp]-96]<num[temp])
			return false;
return true;
}

bool kurang()
{
	int temp;
	for (temp=1;temp<=Q;temp++)
		if (cnt[q[temp]-96]<num[temp])
			return true;
return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i,kiri,kanan,INF=2*pow(10,8);
	cin>>N;
	char arr[N+5];
	
	for (i=1;i<=N;i++)
		cin>>arr[i];
	cin>>Q;
	for (i=1;i<=Q;i++)
		cin>>num[i]>>q[i];
	int ans=INF;
	kiri=kanan=1;	cnt[arr[kanan]-96]++;
	bool fail=false;
	
	while (kanan!=N)
	{
		while (kurang())
		{
			kanan++;
			if (kanan>N)
			{
				fail=true;
				break;
			}
			cnt[arr[kanan]-96]++;
			
			if (lebih())
				ans=min(ans,(kanan-kiri+1));
		
			//cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<kiri<<" "<<kanan<<" "<<ans<<"\n";
					
		}
		while (lebih())
		{
			cnt[arr[kiri]-96]--;
			kiri++;
			
			if (kiri>kanan)
			{
				kanan=kiri;
				cnt[arr[kanan]-96]++;
			}
			if (kiri>N)
			{
				fail=true;
				break;
			}
			if (lebih())
				ans=min(ans,(kanan-kiri+1));
		
			//cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<kiri<<" "<<kanan<<" "<<ans<<"\n";
				
		}
		if (fail)
			break;
	}	
	if (ans==INF)
		cout<<"Andy rapopo\n";
	else
		cout<<ans<<"\n";
return 0;
}

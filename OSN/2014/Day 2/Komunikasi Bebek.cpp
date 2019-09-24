#include<bits/stdc++.h>
using namespace std;
int arr[2005],N,i,j,step,temp;
bool filled[5500];
 
int main()
{
	ios_base::sync_with_stdio(false);
	string subs;
	cin>>subs;
	cin>>N;
	if ((N==1)||(N==2))
	{
		cout<<"0\n";
		return 0;
	}
	memset(filled,false,sizeof(filled));
	for (i=1;i<=N;i++)
	{
		cin>>arr[i];
		arr[i]+=2500;
		filled[arr[i]]=true;	//ada bebek
	}
	 
	int ans=N-2;
	for (i=1;i<=N;i++)
	{
		for (step=1;step<5000;step++)
		{
			int remaining=N,cnt=0;
			for (j=arr[i];j<=5000;j+=step)
			{
				if (filled[j])
					remaining--;
				else
					cnt++;
				temp=remaining+cnt;
				ans=min(ans,temp);
			}
		}
		//cout<<arr[i]<<" "<<step<<" "<<temp<<"\n";
	}
	cout<<ans<<"\n";
return 0;
}

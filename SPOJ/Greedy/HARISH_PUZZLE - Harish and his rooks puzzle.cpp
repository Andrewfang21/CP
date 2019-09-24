#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int i,j,k,TC,cnt;
	cin>>TC;
	string chess[10];
	
	while (TC--)
	{
		for (i=0;i<8;i++)
			cin>>chess[i];
		bool found=false;
		cnt=0;
			
		for (i=0;i<8;i++)
		{
			for (j=0;j<8;j++)
				if (chess[i][j]=='R')
				{
					cnt++;
					for	(k=j+1;k<=8;k++)	//cek kanan
						if (chess[i][k]=='R')
						{
							//cout<<i<<" "<<j<<" "<<k<<"\n";
							found=true;
							break;	
						} 
					for (k=i+1;k<8;k++)
						if (chess[k][j]=='R')
						{
							//cout<<k<<" "<<j<<"\n";
							found=true;
							break;
						}
				}
			if (found)
				break;
		}
		if (found)
			cout<<"NO\n";
		else
		if (cnt!=8)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
return 0;
}

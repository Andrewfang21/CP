#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	
	while (cin>>str)
	{
		if (str=="0")
			return 0;
			
		long long dp[str.length()+5],i,before,now;	
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		
		for (i=0;i<str.length();i++)
		{
			if ((str[i]>='1')&&(str[i]<='9'))
				dp[i+1]+=dp[i];
			
			if (i>0)
			{
				before=10*(str[i-1]-'0');
				now=str[i]-'0';
				
				//cout<<i<<" "<<before<<" "<<now<<"\n";
				
				if (((before+now)>=10)&&((before+now)<=26))
					dp[i+1]+=dp[i-1];
			}
			//cout<<i<<" "<<dp[i+1]<<"\n";
		}
		cout<<dp[str.length()]<<"\n";
	}
return 0;
}

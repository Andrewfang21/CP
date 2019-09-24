#include<bits/stdc++.h>
using namespace std;
vector<int>a,b;
int LCS[2002][2002];

int lcs()
{
	int temp1,temp2;
	
	for (temp1=0;temp1<=a.size();temp1++)
		for (temp2=0;temp2<=b.size();temp2++)
		{
			if ((temp1==0)||(temp2==0))
				LCS[temp1][temp2]=0;
			else
			if (a[temp1-1]==b[temp2-1])
				LCS[temp1][temp2]=1+LCS[temp1-1][temp2-1];
			else
				LCS[temp1][temp2]=max(LCS[temp1-1][temp2],LCS[temp1][temp2-1]);
		}
	/*for (temp1=1;temp1<=a.size();temp1++)
	{
		for (temp2=1;temp2<=b.size();temp2++)
			cout<<LCS[temp1][temp2]<<" ";
		cout<<"\n";
	}*/
return LCS[a.size()][b.size()];
}

int main()
{
	int TC,num,temp,ans=0;
	cin>>TC;
	
	while (TC)
	{
		ans=0;
		a.clear();		b.clear();
		while (cin>>num)
		{
			if (num==0)	//agnes
				break;
			else
				a.push_back(num);
		}
		while (true)
		{
			cin>>temp;
			if (temp==0)
			{
				TC--;
				cout<<ans<<"\n";
				break;
			}
			else
			{
				b.push_back(temp);
				while (cin>>num)
				{
					if (num==0)
					{
						ans=max(ans,lcs());
						b.clear();
						//cout<<ans<<"\n";
						break;
					}
					else
						b.push_back(num);
				}
			}
		}
	}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
int BIT[40005],MAXX=35000;
map<string, int>a;

void reset()
{
	memset(BIT,0,sizeof(BIT));
	a.clear();
}

void update(int bound)
{
	int i=bound;
	
	while (i>0)
	{
		BIT[i]++;
		i-=(i & -i);
	}
}

int query(int i)
{
	int res=0;
	while (i<MAXX)
	{
		res+=BIT[i];
		i+=(i & -i);
	}
return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int TC,N,i,temp;
	string s,connect[30005],b[30005];
		
	cin>>TC;
	
	while (TC--)
	{
		reset();
		cin>>N;
		for (int i=1;i<=N;i++)
		{
			cin>>s;
			a[s]=i;			connect[i]=s;
		}
		for (int i=1;i<=N;i++)
		{
			cin>>s;
			b[i]=s;
		}
		
		int res=0;
		for (int i=1;i<=N;i++)
		{
			string now;
			now=b[i];
			
			int pos=a[now];

			temp=query(pos);

		//	cout<<i<<" "<<pos<<"  "<<temp<<"\n";
			
			res+=(abs(pos+temp-i));
			update(pos);
		}
		cout<<res<<"\n";
	}
return 0;
}

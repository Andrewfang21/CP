#include<bits/stdc++.h>
using namespace std;
int N,lis1[205],lis2[205],lds1[205],lds2[205],arr[205];
bool mark[205];

void backtrack(int maks, int N)
{
	int temp;
		
	for (temp=N;temp>=1;temp--)
	{
		if (lis1[temp]==maks)
		{
			//cout<<temp<<" "<<lis1[temp]<<" "<<arr[temp]<<"\n";
			maks=lis1[temp]-1;
			mark[temp]=true;
		}
	}
}

int main()
{
	int N;
	while (cin>>N)
	{
		int i,j,maks1,maks2;
		if (N==-1)
			return 0;
			
		memset(mark,false,sizeof(mark));					
		for (i=1;i<=N;i++)
		{
			cin>>arr[i];
			lis1[i]=lis2[i]=1;
			lds1[i]=lds2[i]=0;
		}
	
		maks1=-1;
		for (i=2;i<=N;i++)
			for (j=1;j<i;j++)
				if ((arr[i]>arr[j])&&(lis1[i]<lis1[j]+1))
				{
					lis1[i]=lis1[j]+1;
					
					if (lis1[i]>maks1)
						maks1=lis1[i];
				}
		cout<<maks1<<"\n";
		
		backtrack(maks1,N);
		
		/*for (i=1;i<=N;i++)
			if (mark[i])
				cout<<i<<" "<<arr[i]<<"\n";*/
		
		maks2=-1;
		for (i=N;i>=1;i--)
			if (!mark[i])
			{
				lds1[i]=1;
				break;
			}
			
		for (i=N;i>=1;i--)
		{
			if (!mark[i])
			{
				for (j=i-1;j>=1;j--)
				{
					if ((arr[i]<arr[j])&&(lds1[j]<lds1[i]+1)&&(!mark[j]))
					{
						lds1[j]=lds1[i]+1;
						
						if (lds1[j]>maks2)
							maks2=lds1[j];
					}
				}
			}
		}
		for (i=1;i<=N;i++)
			if (!mark[i])
				cout<<i<<" "<<arr[i]<<" "<<lds1[i]<<"\n";
		cout<<maks2<<"\n";
	}
}

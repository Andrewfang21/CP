#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i,temp,X,Y,size=0;
	string command;
	stack<int>num,frek;
	scanf("%d",&N);
	for (i=1;i<=N;i++)
	{
		cin>>command;
		if (command=="add")
		{
			scanf("%d %d",&X,&Y);
			num.push(X-temp);
			frek.push(Y);
			size+=Y;
			printf("%d\n",size);
		} else
		if (command=="del")
		{
			scanf("%d",&X);
			cout<<num.top()+temp<<"\n";
			size-=X;
			
			while(X>=frek.top())
			{
				X-=frek.top();
				frek.pop();		num.pop();
				
				if ((frek.size()==0)||(num.size()==0)) break;
				if (frek.top()==0)
				{
					temp=0;
					break;
				}
			}
			if ((frek.size()>0)&&(num.size()>0))
				frek.top()-=X;	
		} else
		if (command=="adx")
		{
			scanf("%d",&X);
			temp+=X;
		} else
		if (command=="dex")
		{
			scanf("%d",&X);
			temp-=X;
		}
	}
}

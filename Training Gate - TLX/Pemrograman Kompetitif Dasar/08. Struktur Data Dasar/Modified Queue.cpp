#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int val,frek;
};

int main()
{
	deque<lol>temp;
	int N,i,X,Y,ukuran=0;
	scanf("%d",&N);
	string command;
	for (i=1;i<=N;i++)
	{
		cin>>command;
		if (command=="add")
		{
			lol u;
			scanf("%d %d",&X,&Y);
			temp.push_back({X,Y});
			ukuran+=Y;
			printf("%d\n",ukuran);	
		}
		else
		if (command=="del")
		{
			scanf("%d",&X);
			printf("%d\n",temp.front().val);
			while(temp.front().frek<X)
			{
				ukuran-=temp.front().frek;
				X-=temp.front().frek;
				temp.pop_front();
			}
			if ((X<temp.front().frek)&&(X!=0))
			{
				ukuran-=X;
				temp.front().frek-=X;
			}
		}
		else
		reverse(temp.begin(),temp.end());
	}
return 0;	
	
}

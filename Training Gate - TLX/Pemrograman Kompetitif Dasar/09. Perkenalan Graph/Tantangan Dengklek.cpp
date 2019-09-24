#include<bits/stdc++.h>
using namespace std;
bool visited[90000000];
int N,i,K,arr[10];
struct lol
{
	int value,dist;
};
int convert()
{
	int hasil=0,temp1;
	for (temp1=1;temp1<=N;temp1++)
	{
		hasil*=10;
		hasil+=arr[temp1];
	}
return hasil;
}

bool sorted()
{
	int temp;
	for (temp=1;temp<=N;temp++)
		if (arr[temp]!=temp)
			return false;
return true;			
}

void change(int head)
{
	int front,back,temp=0;
	front=head;	back=head+K-1;
	while(front<=back)
	{
		swap(arr[front],arr[back]);
		front++;	back--;
	}
}

int main()
{
	scanf("%d",&N);
	for (i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&K);
	queue<lol>q;
	lol now,u;
	
	now.value=convert();
	now.dist=0;
	q.push(now);
	memset(visited,false,sizeof(visited));
	
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if (!visited[u.value])
		{
			visited[u.value]=true;
			for (i=1;i<=N;i++)	//untuk memindahkan nilai u.value ke array temp//
			{
				arr[N-i+1]=u.value%10;
				u.value/=10;
			}
			
			if (!sorted())
			{
				u.dist++;
				for (i=1;i<=N-K+1;i++)
				{
					change(i);
					u.value=convert();
					q.push(u);
					change(i);
				}
			}
			else
			{
				printf("%d\n",u.dist);
				return 0;
			}
		}
	}
	printf("-1\n");
return 0;
}

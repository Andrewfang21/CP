#include<bits/stdc++.h>
using namespace std;
struct lol
{
	int value,index;
};

int main()
{
	ios_base::sync_with_stdio(false);
	int N,i,j;		long long sum=0;
	scanf("%d",&N);
	int A[N+5];		lol H[N+5],temp;
	memset(A,0,sizeof(A));
	for (i=1;i<=N;i++)
		scanf("%d",&H[i]);
	stack<lol>st;
	
	if (N==1) printf("1\n"); else
	{
	st.push({H[N].value,N});
	i=N-1;
	while(i!=0)
	{
		if (H[i].value>st.top().value)
		{
			while(H[i].value>st.top().value)
			{
				A[st.top().index]=abs(i-st.top().index);
				sum+=A[st.top().index];
				st.pop();	
				if (st.empty()) break;
			}
			st.push({H[i].value,i});
		} else
		if (H[i].value<=st.top().value)
			st.push({H[i].value,i});
		i--;	
	}

	if (st.size()>0)
	{
		temp.value=st.top().value;	temp.index=st.top().index;
		A[st.top().index]=1;
		sum+=A[st.top().index];
		st.pop();
		while (!st.empty())
		{
			A[st.top().index]=abs(temp.index-st.top().index)+1;
			sum+=A[st.top().index];
			st.pop();
		}
	}	
	printf("%lld\n",sum);
	}
return 0;		
}

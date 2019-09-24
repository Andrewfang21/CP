#include<bits/stdc++.h>
using namespace std;

int main()
{
	int M,N,i,hitung,limit,temp,j;
	cin>>N>>M;
	vector<int>B,S;
	
	for (i=0;i<N;i++)
	{
		int a;
		cin>>a;
		B.push_back(a);
	}
	for (i=1;i<=M;i++)
	{
		int a;
		cin>>a;
		S.push_back(a);	
	}	
	
	sort(B.begin(),B.end());	sort(S.begin(),S.end());
	
	limit=min(N,M);
	temp=N-1;	i=M-1; hitung=0;
		
	for (int j=1;j<=1015;j++)
	{
		if ((i>=0)&&(temp>=0))
		{
			if ((B[temp]==S[i])||(B[temp]+1==S[i]))
			{
				hitung++;	i--;	temp--;
			} 
			else
			if (B[temp]>S[i])
				temp--; 
			else
			if (B[temp]+1<S[i])
				i--;	
		}
	}
	cout<<hitung<<"\n";
return 0;	
}

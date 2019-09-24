#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,N,M,i;
	cin>>TC;
	
	while (TC--)
	{
		cin>>N>>M;
		int godzilla[N+5],mecha[M+5];
		for (i=0;i<N;i++)
			cin>>godzilla[i];
		for (i=0;i<M;i++)
			cin>>mecha[i];
		sort(godzilla,godzilla+N);	sort(mecha,mecha+M);
		
		if (godzilla[N-1]>=mecha[M-1])
			cout<<"Godzilla\n";
		else
			cout<<"MechaGodzilla\n";
	}
return 0;
}

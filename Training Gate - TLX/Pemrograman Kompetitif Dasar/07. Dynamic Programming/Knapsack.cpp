#include<bits/stdc++.h>
using namespace std;
int knapsack[2500][2500],berat[2500],value[2500],i,j,N,G,temp,maks;
struct lol
{
	vector<int>isi;
	int weight;
};
bool accompare(lol lhs, lol rhs)
{
	if (lhs.weight==rhs.weight)	return lhs.isi<rhs.isi; else return lhs.weight<rhs.weight;
}

int main()
{
	cin>>G>>N;
	for (i=1;i<=N;i++)
		cin>>berat[i]>>value[i];
	
	for (i=0;i<=G;i++)
		knapsack[0][i]=0;
	maks=INT_MIN;
	
	for (i=1;i<=N;i++)
		for (j=0;j<=G;j++)
		{
			if (berat[i]<=j)
				knapsack[i][j]=max(knapsack[i-1][j],knapsack[i-1][j-berat[i]]+value[i]);
			else
				knapsack[i][j]=knapsack[i-1][j];
			
			if (maks<knapsack[i][j]) maks=knapsack[i][j];
		}
	int temp=0;
	lol backtrack[5000];
	for (i=N;i>=1;i--)
	{
		if (knapsack[i][G]==maks)
		{
			int batas=i,bla=G;	
			while(batas!=0)
			{
				if (knapsack[batas][bla]==knapsack[batas-1][bla-berat[batas]]+value[batas])
				{
					backtrack[temp].weight+=berat[batas];
					backtrack[temp].isi.push_back(batas);
					bla-=berat[batas];
				}
				batas--;
			}
			sort(backtrack[temp].isi.begin(),backtrack[temp].isi.end());
			temp++;	
		}	
	}
	
	sort(backtrack,backtrack+temp,accompare);
	cout<<maks<<"\n";
	for (i=0;i<backtrack[0].isi.size();i++)
	{
		printf("%d\n",backtrack[0].isi[i]);
	}
return 0;			
}

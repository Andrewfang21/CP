#include<bits/stdc++.h>
using namespace std;
int N,D,i,j,kecil,besar;
struct num
{
	int x,y;
};
num angka[1001];

int max (int a, int b) 
{
	if (a>=b) return a; else return b;
}
int min(int a, int b) 
{
	if (a>=b) return b; else return a;
}
int main()
{
	cin>>N>>D;
	for (i=1;i<=N;i++)
		cin>>angka[i].x>>angka[i].y;
		besar=-1;
		kecil=300000;
	for (i=1;i<=N-1;i++)
		for (j=i+1;j<=N;j++)
		{
			besar=max(besar,pow((abs(angka[i].x-angka[j].x)),D)+pow((abs(angka[i].y-angka[j].y)),D));
			kecil=min(kecil,pow((abs(angka[i].x-angka[j].x)),D)+pow((abs(angka[i].y-angka[j].y)),D));
		}
	cout<<kecil<<" "<<besar<<"\n";
return 0;			
}

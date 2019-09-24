#include<iostream>
using namespace std;
int sisa,permen,orang;
float bagi;
int main()
{
	cin>>permen>>orang;
	bagi=permen/orang;
	sisa=permen%orang;
	cout<<"masing-masing "<<bagi<<"\n";
	cout<<"bersisa "<<sisa<<"\n";
}

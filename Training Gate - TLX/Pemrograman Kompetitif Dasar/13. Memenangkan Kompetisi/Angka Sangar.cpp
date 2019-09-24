#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	long long N,A,B,C,data[16]={1,5,6,25,76,376,625,9376,109376,7109376,90625,890625,2890625,12890625,87109376},i,j,ans,save1,save2,k;
	int simpan1[100],simpan2[100];
	string temp1,temp2,temp3,ans1,ans2;
	cin>>N;
	for (i=0;i<11;i++)
	{
		C=data[i];
		temp3=to_string(C);
		ans=stoll(to_string(N)+to_string(C));
		
		for (j=2;j<=sqrt(ans);j++)
		{
			if (ans%j==0)
			{
				A=j;	B=ans/j;
				
				temp1=to_string(A);
				temp2=to_string(B);
				if ((temp1.length()>temp3.length())&&(temp2.length()>temp3.length()))
				{
					save1=save2=0;	
					for (k=1;k<=temp3.length();k++)
					{
						simpan1[k]=A%10;
						A/=10;
					}
					for (k=temp3.length();k>=1;k--)
					{
						save1=(save1*10)+simpan1[k];
					}
					
					for (k=1;k<=temp3.length();k++)
					{
						simpan2[k]=B%10;
						B/=10;
					}
					for (k=temp3.length();k>=1;k--)
					{
						save2=(save2*10)+simpan2[k];
					}
					
					if ((save1==C)&&(save2==C))
					{
						cout<<"YA\n";
						cout<<A<<" "<<B<<" "<<C<<"\n";
						return 0;
					}
				}	
			}
		}
	}
	cout<<"TIDAK\n";
return 0;
}

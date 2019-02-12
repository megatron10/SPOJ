#include <iostream>
using namespace std;
int main() 
{
  int i,t,n,inp,j;
	cin>>t;
	while(t--)
	{
		bool values[100001]={};values[0]=1;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>inp;
			for(j=1000*i;j>=0;j--){ if(values[j]) values[j+inp]=1; }
		}
		j=0;
		for(i=0;i<100001;i++)j+=values[i]?i:0;
		cout<<j<<"\n"; 
	}
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  long int a,b,n,l,i,loop_limit,j;
	cin>>a>>b>>n;
  l=ceil(sqrt(b));
  bool sieve[(int)ceil(sqrt(pow(10,9)))]={};
  long int actual_no[b-a+1]={};
	long int actual[b-a+1]={};
	for(i=0;i<b-a+1;i++){actual[i]=1;actual_no[i]=a+i;}
  loop_limit=sqrt(sqrt(pow(10,9)));
  for(i=2;i<=loop_limit;i++)
  { if(!sieve[i]){for(j=i*i;j<=sqrt(pow(10,9));j+=i) {sieve[j]=true;} } }
		
	for(int k=2;k<=l;k++)
	{
		if(sieve[k])continue; 
		for(i=(k-a%k)%k;i<b-a+1;i+=k)
		{
			int count=1;
			while((actual_no[i]%k)==0)
			{
				count++;
				actual_no[i]/=k;
			}
			actual[i]*=count;
		}
	}
	int ans=0;
	for(i=0;i<b-a+1;i++)
	{
		if(actual_no[i]!=1)actual[i]*=2;
		if(actual[i]==n)ans++;
	}
	cout<<ans<<"\n";
}
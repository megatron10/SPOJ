#include <iostream>
#define l 1000001
using namespace std;
int main()
{
  int t=1,n,ans[l]={},j,k,primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	for(int i:primes)
	{
		k=i*i*i;
		for(j=k;j<l;j+=k)ans[j]=-1;
	}
	for(int i=1;i<l;i++)if(ans[i]!=-1)ans[i]=t++;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Case "<<i<<": ";
		if(ans[n]==-1)cout<<"Not Cube Free\n";
		else cout<<ans[n]<<"\n";
	}
}
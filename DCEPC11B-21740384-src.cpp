#include <iostream>
using namespace std;
long int bin_expo(long int b, long int e, long int p)
{
	long int out=1,tmp=b;
	while(e)
	{
		if(e&1)out=(out*tmp)%p;
		tmp=(tmp*tmp)%p;
		e>>=1;	
	}
	return out;	
}
int main()
{
  long int i,t,n,p,inv=1;
	cin>>t;
	while(t--)
	{
		inv=1;
		cin>>n>>p;
		if(n<p)
		{
			for(i=n+1;i<p;i++)inv=(inv*i)%p;
			cout<<bin_expo(p-inv,p-2,p)<<"\n";
		}
		else cout<<"0\n";
	}
}
#include <iostream>
#include <algorithm>
#define p 		500000003
#define hadhai 1000000007
#define lli long long int
#define limit 100001
using namespace std;
lli fact[2*limit]={},ifact[2*limit]={},inv[2*limit]={};
lli bin_expo(lli b,lli e,lli bass)
{
	lli ans=1,tmp=b%bass;
	while(e)
	{
		if(e&1)ans=(ans*tmp)%bass;
		e>>=1;
		tmp=(tmp*tmp)%bass;
	}
	return ans;
}
void build()
{
	fact[0]=ifact[0]=inv[1]=fact[1]=ifact[1]=1;
	for(int i=2;i<2*limit;i++)
	{
		fact[i]=(fact[i-1]*i)%p;
		inv[i]=(p-((p/i)*inv[p%i])%p)%p;
		ifact[i]=(ifact[i-1]*inv[i])%p;
	}
}
int main() 
{
	build();
  int t,a,b,n,i;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n;
		cout<<bin_expo(a,bin_expo(2*((fact[(2*n)-1]*((ifact[n]*ifact[n-1])%p))%p),b,hadhai-1),hadhai)<<"\n";		
	}
}
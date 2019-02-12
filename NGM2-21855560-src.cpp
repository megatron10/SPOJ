#include <iostream>
#include <algorithm>
#define lli long long int
using namespace std;
lli gcd(lli a,lli b) {return (b?gcd(b,a%b):a);}
lli lcm(lli a,lli b) {return (-a*b)/gcd(max((lli)abs(a),b),min((lli)abs(a),b));}
int main() 
{
  lli put,loop,i,j=1,tmp,n,k,ie[32769],ans;ie[1]=1;
	cin>>n>>k;ans=n;
	for(i=0;i<k;i++)
	{
		cin>>tmp;
		for(loop=1;loop<=j;loop++)ans+=n/(ie[j+loop]=lcm(ie[loop],tmp));
		j<<=1;
	}
	cout<<ans;
}
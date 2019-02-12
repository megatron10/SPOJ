#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	bool np[50000]={};int r,t,i,j,p,l;
	int prime[9592]={}; long long int m,n;
	for(i=2;i<224;i++)	if(!np[i])	for(j=i*i;j<50000;j+=i)np[j]=1; 
	j=0;
	for(i=2;i<50000;i++) if(!np[i]) prime[j++]=i;
	
	cin>>t;
	while(t--)
	{
		i=0;
		bool q[1000001]={};
		cin>>m>>n;
		l=(int)floor(sqrt(n));
		while(prime[i]<=l)
		{
			r=m%(prime[i]);
			j=(prime[i]-r)%(prime[i]);
			if(m+j==prime[i])j+=prime[i];
			for(;j<=(n-m);j+=prime[i]) q[j]=1;
			i++;
		}
		i=(m==1)?1:0;
		for(;i<=n-m;i++){ if(!q[i]) {cout<<(m+i)<<"\n";} }
	}
	return 0;
}
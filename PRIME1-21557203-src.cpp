#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	bool np[31623]={};int r,t,i,j,p,l;
	int prime[3402]={}; long long int m,n;
	for(i=2;i<200;i++)	if(!np[i])	for(j=i*i;j<31623;j+=i)np[j]=1; 
	j=0;
	for(i=2;i<31623;i++) if(!np[i]) prime[j++]=i;
	prime[3401]=31627;
	cin>>t;
	while(t--)
	{
		i=0;
		bool q[100001]={};
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
		for(;i<=n-m;i++){if(!q[i]) {cout<<(m+i)<<"\n";}}
		cout<<"\n";
	}
	return 0;
}
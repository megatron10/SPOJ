#include <iostream>
#include<algorithm>
using namespace std;
int *s,n;

//int give()

bool okay(int o,int c)
{
	int i=-o,l=0,u=n-1;
	while(c--)
	{
	//cout<<c<<":\n";	
	u=n-1;
	while(l<=u)
		{
			int m=(l+u)/2;
			if(s[m]-i==o) {l=m;break;}
			else if(s[m]-i>o) u=m-1;
			else l=m+1;
		}
	i=s[l];
	//cout<<s[l]<<"\n";
	if(l>=n)break;	
	}
	//cout<<"\n";
	if(c>=0)return false;
	return true;
}

int main()
{
	int t,l,u,c; cin>>t;
	while(t--)
	{
		cin>>n>>c;		s = new int[n];
		for(int i=0;i<n;i++) scanf("%d",&s[i]);
		sort(s,s+n);
		l=0; u=s[n-1]-s[0];
		while(l<=u)
		{
			int m=(l+u)/2;
			if(okay(m,c)) l=m+1;
			else u=m-1;
			
		}
		cout<<u<<"\n";
		
	}
	//okay()
}
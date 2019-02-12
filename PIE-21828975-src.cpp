#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() 
{
	double PI=acos(-1);
  int tmp,i,t,n,f,pies[10001];
	cin>>t;
	while(t--)
	{
		cin>>n>>f;
		f++;
		double radius=0,r=0,l=0;
		for(i=0;i<n;i++)
		{
			cin>>pies[i];
			r=max(r,(double)pies[i]);
		}
		r*=2;
		while(PI*(r*r-l*l)>0.0001)
		{
			radius=(l+r)/2;
			tmp=0;
			for(i=0;i<n;i++)tmp+=floor((pies[i]*pies[i])/(radius*radius));
			if(tmp>=f)l=radius;
			else r=radius;
		}
		printf("%.4f\n",PI*l*l);
	}
}
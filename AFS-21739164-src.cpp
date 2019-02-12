#include <iostream>
#include <cstring>
#include <cmath>
#define l 1000001
using namespace std;
long int bin_expo(int b, int e)
{
	long int out=1,tmp=b;
	while(e)
	{
		if(e&1)	out*=tmp;
		tmp*=tmp;
		e>>=1;
	}
	return out;
}
int main()
{
	long int tmp,i,j,t,n,t2,cter=0;
	long int *answer=new long int[l];
	long int *div=new long int[l];
	memset(answer, 0, l*sizeof(int));
	memset(div,0,l*sizeof(int));
	div[1]=1;
	for(i=2;i<=1000;i++)
	{
		if(!div[i])
		{
			div[i]=i;
			for(j=i*i;j<l;j+=i)div[j]=i;
		}	
	}
	for(;i<l;i++)if(!div[i])div[i]=i;
	
	
	for(i=2;i<l;i++)
	{
		j=i;
		tmp=1;
		while(j>1)
		{
			t2=div[j];
			cter=0;
			while(!(j%t2))
			{
				cter++;
				j/=t2;
			}
			tmp=tmp*((bin_expo(t2,cter+1)-1)/(t2-1));	
		}
		answer[i]=answer[i-1]-i+tmp;
	}
		
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<answer[n]<<"\n";
	}
	return 0;	
}
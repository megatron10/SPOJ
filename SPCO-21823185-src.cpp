#include <iostream>
#include <algorithm>
#define ulli unsigned long long int
using namespace std;
ulli nCr[65][66];
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,67};
void build()
{
	int i,j;
	nCr[0][0]=1;
	for(i=1;i<65;i++)
	{
		nCr[i][0]=nCr[i][i]=1;
		for(j=1;j<i;j++)nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
	}
}
int kitni_bits(ulli no)
{
	int ret=0;
	while(no)
	{
		if(no&1)ret++;
		no>>=1;
	}
	return ret;
}
ulli solve(ulli no)
{
	int pos=0;
	int shift=kitni_bits(no)-1;
	//cout<<shift;
	ulli answer=0;
	while(no)
	{
		if(no&1)
		{
			int r=2-shift;
			for(int i=0;i<19 && pos>=r;i++)
			{
				if(r>=0)answer+=nCr[pos][r];
				r=primes[i+1]-shift;
			}
			shift--;
		}
		no>>=1;
		pos++;
	}
	return answer;
}
int main() 
{
	build();
  int t;
	ulli a,b,ans;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		ans=solve(b+1)-solve(a);
		cout<<ans<<"\n";
	}	
}
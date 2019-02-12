#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() 
{
	int n,i,j;
	vector <int> primes;
	vector <int> :: iterator it;
	int div[10001]={},count[10001]={}; div[1]=1;
	for(i=2;i<=100;i++)
	{
		if(!div[i])
		{
			div[i]=i;
			for(j=i*i;j<=10000;j+=i)if(!div[j])div[j]=i;
			primes.push_back(i);
		}	
	}
	for(i=101;i<=10000;i++)if(!div[i]){ primes.push_back(i); div[i]=i; }
	cin>>n;
	for(i=2;i<=n;i++)
	{
		j=i;
		while(j>1)
		{
			count[div[j]]++;
			j/=div[j];
		}
	}
	for(it=primes.begin();it!=primes.end();it++)
	{if(count[*it]){cout<<*it<<"^"<<count[*it];break;}}
	it++;
	for(;it!=primes.end();it++)if(count[*it]){cout<<" * "<<*it<<"^"<<count[*it];}
}
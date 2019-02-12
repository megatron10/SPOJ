#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define p 1000000007
using namespace std;
void multiply(vector<long int>* a,vector<long int>* b,int n)
{
	vector <long int> output[n],b_[n];int i,j,k;
	for(i=0;i<n;i++)for(j=0;j<n;j++){output[i].push_back(a[i][j]);b_[i].push_back(b[i][j]);a[i][j]=0;}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)a[i][k]=(a[i][k]+(output[i][j]*b_[j][k])%p)%p;
		}
	}
}
void mat_expo(int n,long int e,vector<long int> *a)
{
	int i=0,j=0;
	vector <long int> out[n];
	vector <long int> tmp[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){out[i].push_back(0); tmp[i].push_back(a[i][j]);}
		out[i][i]=1;
	}
	while(e)
	{
		if(e&1)multiply(out,tmp,n);
		multiply(tmp,tmp,n);
		e>>=1;
	}
	for(i=0;i<n;i++)for(j=0;j<n;j++)a[i][j]=out[i][j];
}
void display(int n,int m,vector<long int> *a)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)cout<<a[i][j]<<"	";
		cout<<"\n";
	}
}
int main() 
{
	int t,l,r;long int ans=0;
	cin>>t;
	while(t--)
	{
		vector<long int> a[2]={{0,1},{1,1}},b[2]={{0,1},{1,1}};
		cin>>l>>r;
		mat_expo(2,r+1,a);
		mat_expo(2,l,b);
		ans=(a[1][1]-b[1][1]+p)%p;
		cout<<ans<<"\n";
	}
	return 0;
}
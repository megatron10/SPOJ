#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main() 
{
  int i,j,n,m,f[101]={},tmp;
	unordered_set <int> all;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>f[i];
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>tmp;
			all.insert(tmp);
		}
	}tmp=0;
	for(i=0;i<n;i++){if(all.find(f[i])!=all.end())tmp++;}
	cout<<all.size()-tmp;
}
#include <iostream>
#include <algorithm>
using namespace std;
int walk_no;
int data[1000001];
bool dfs(int i,int* walk)
{
	int tmp=data[i];//destination
	walk[i]=walk_no;
	if(!walk[tmp])	return dfs(tmp,walk);
	if(walk[tmp]!=walk_no)return false;
	return true;
}
int main() 
{
  int tmp,i,j,n,m;
	walk_no=0;
	char c;
	int ans=0;cin>>n>>m;
	int walk[n*m+1]={};
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>c;
			tmp=m*i+j;
			if(c=='E')tmp+=1;
			else if(c=='W')tmp-=1;
			else if(c=='N')tmp-=m;
			else tmp+=m;
			data[m*i+j]=tmp;
		}
	}
	for(i=1;i<=n*m;i++){if(!walk[i]) { walk_no++;  if(dfs(i,walk)) ans++; } }
	cout<<ans;	
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> tree[10001];
bool visited[10001];
int node=1,dist=0;
void dfs(int i,int d=0)
{
	visited[i]=1;
	for(int k:tree[i]) if(!visited[k]) dfs(k,d+1);
	if(d>dist){ node=i; dist=d; }
}
int main() 
{
  int n,i,v1,v2; cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>v1>>v2;
		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}
	dfs(1);
	int tmp=node;
	for(i=1;i<=n;i++)visited[i]=0;
	node=1; dist=0;
	dfs(tmp);
	cout<<dist;
}
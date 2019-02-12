#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> graph;
vector<vector<int>> rgraph;
int back[100011]={},id[100011]={},imp,timer=1,counter=0;
void dfs(int i,vector<vector<int>> &graph)
{
	id[i]=back[i]=timer++; counter++;
	for(int v:graph[i])	if(!id[v]) dfs(v,graph);
	imp=i;
}
void reboot() {counter=0;	memset(id,0,sizeof(id));	memset(back,0,sizeof(back));   timer=1; }
int main()
{
	int t,i,u,v,n,m;
	cin>>n>>m;
	graph.resize(n+1); rgraph.resize(n+1);
	while(m--){ cin>>u>>v; graph[u].push_back(v); rgraph[v].push_back(u); }
	for(i=1;i<=n;i++) if(!id[i])dfs(i,rgraph);
	reboot();
	dfs(imp,rgraph);	
	for(i=1;i<=n;i++) if(!id[i]) break; 
	if(counter==n)
	{
		reboot();
		dfs(imp,graph);
		cout<<counter<<"\n";
		for(i=1;i<=n;i++) if(id[i]) cout<<i<<" ";
	}
	else cout<<"0\n";
}
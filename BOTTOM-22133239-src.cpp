#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include<stack>
using namespace std;
vector<vector<int>> graph;
vector<int> scc;
stack<int> s;
bool isp[10000]={};
int back[10000]={},id[10000]={},timer=1;
bool dfs(int i,vector<vector<int>> &graph)
{
	bool faltu=0;
	id[i]=back[i]=timer++;
	s.push(i);   isp[i]=1;
	for(int v:graph[i])
	{
		if(!id[v]) faltu|=dfs(v,graph);
		if(isp[v]) back[i]=min(back[i],back[v]);
		else faltu=1;
	}
	if(back[i]==id[i])
	{
		vector<int> temp;
		while(s.top()!=i){ temp.push_back(s.top()); isp[s.top()]=0; s.pop(); }//scc gound here
		isp[i]=0; s.pop(); temp.push_back(i);
		if(!faltu)scc.insert(scc.end(),temp.begin(),temp.end());
	}
	return faltu;
}
void reboot(int n) 
{	
	memset(id,0,sizeof(id));	memset(back,0,sizeof(back));  memset(isp,0,sizeof(isp));  timer=1; 
	graph.clear(); scc.clear();
	graph.resize(n+1);
}
int main()
{
	int t,i,u,v,n,m;
	while(cin>>n && n)
	{
		reboot(n);
		cin>>m;	
		while(m--){ cin>>u>>v; graph[u].push_back(v); }
		for(i=1;i<=n;i++)if(!id[i])dfs(i,graph);
		sort(scc.begin(),scc.end());
		for(int ans:scc)cout<<ans<<" ";
		cout<<"\n";
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define lli long long int
using namespace std;
struct edge{int s,e;};
bool operator<(edge a,edge b){return a.s<b.s || (a.s==b.s && a.e<b.e);}
vector<vector<int>> graph;
vector <edge> out;
int back[710],id[710],timer=1;
void reboot(int n=709)
{
	graph.clear();			out.clear();
	memset(back,0,sizeof(back));		memset(id,0,sizeof(id));
	timer=1;
	while(n--)graph.push_back({});
}
void dfs(int i,int papa)
{
	id[i]=back[i]=timer++;

	for(int v:graph[i])
	{
		if(v==papa)continue;
		if(!id[v])
		{
			dfs(v,i);
			if(back[v]>id[i])
				out.push_back({min(i,v),max(i,v)});
		}
		back[i]=min(back[i],back[v]);
	}
}
int main()
{
	int t,i,u,v,n,m;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		reboot();
		cin>>n>>m;
		while(m--){ cin>>u>>v; graph[u].push_back(v); graph[v].push_back(u); }
		dfs(1,0);
		sort(out.begin(),out.end());
		cout<<"Caso #"<<i<<"\n";
		if(out.size()!=0)
		{
			cout<<out.size()<<"\n";
			for(edge p:out)cout<<p.s<<" "<<p.e<<"\n";
		}
		else cout<<"Sin bloqueos\n";
	}
}
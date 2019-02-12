#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int>> graph;
vector<pair<int,int> > edges;
int id=1;
void AP(int papa,int i,bool *visited,int *value,int *back)
{
	back[i]=value[i]=id++; 
	visited[i]=1;
	for(int v:graph[i])
	{	
		if(v==papa)continue;
		if(!visited[v])
		{
			AP(i,v,visited,value,back);
			if(back[v]>value[i])
				edges.push_back({min(i,v),max(i,v)});
			back[i]=min(back[i],back[v]);
		}
		else back[i]=min(back[i],value[v]);
	}
}
int main()
{
	int n,m,u,v,i,j,tc;
	cin>>tc;
	for(j=1; j<=tc ;j++)
	{
		cin>>n>>m;
		id=1;
		graph.clear();
		edges.clear();
		graph.resize(n+1);
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		bool visited[n+1]={}; int value[n+1]={},back[n+1]={};
		AP(0,1,visited,value,back);
		cout<<"Caso #"<<j<<"\n";
		if(edges.size()==0){cout<<"Sin bloqueos\n";continue;}
		cout<<edges.size()<<"\n";
		sort(edges.begin(),edges.end());
		for(auto k:edges)cout<<k.first<<" "<<k.second<<"\n";
	}
}
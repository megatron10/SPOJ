#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> graph;
int id=1,nap=0;
void AP(int papa,int i,bool *visited,int *value,int *back)
{
	bool sp=false; int ic=0;
	back[i]=value[i]=id++; visited[i]=1;
	for(int v:graph[i])
	{
		if(!visited[v])
		{
			AP(i,v,visited,value,back); ic++;
			if(back[v]>=value[i])sp=true;
			back[i]=min(back[i],back[v]);
		}
		else back[i]=min(back[i],value[v]);
	}
	if(papa==0)sp=(ic>1);
	if(sp)nap++;
}
int main()
{
	int n,m,u,v,i;
	while(cin>>n>>m && (n||m))
	{
		id=1;nap=0;graph.clear();
		for(i=0;i<=n;i++)graph.push_back({});
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		bool visited[n+1]={}; int value[n+1]={},back[n+1]={};
		for(i=1;i<=n;i++)if(!visited[i])AP(0,i,visited,value,back);
		cout<<nap<<"\n";
	}
}
/*
 8 8
  1 2
  2 3
  3 4
  4 1
  4 5
  5 6
  6 7
  7 3
*/
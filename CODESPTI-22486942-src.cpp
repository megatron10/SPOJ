#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define lli long long int
using namespace std;
vector<vector<int>> graph;
vector <int> ans;
bool visited[10001]={};
int dfs(int u)
{
	visited[u]=1;
	int i,temp=0,bad=0,good=0;
	for(int v:graph[u])
	{
		if(!visited[v])
		{
			i=dfs(v);
			if(i!=1)i?good++:bad++;
			temp+=ans[v];
		}
	}
	ans[u]=temp-((good)/2)+(bad && (!(good)));
	if( (bad && !good) || (good&1) )return 2; 
	return (good)?1:0;
}
int main()
{
	lli t,n;
	int i,u,v;
	cin>>t;
	while(t--)
	{
		memset(visited,0,sizeof(visited));
		cin>>n;
		graph.resize(n+1); ans.resize(n+1);
		for(i=1;i<n;i++)
		{
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		dfs(0);
		cout<<ans[0]<<endl;
		graph.clear();    ans.clear();
	}
} 
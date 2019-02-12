#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int id=1,counter=0;
vector<vector<int>> graph;
void AP(int papa,int i, bool *visited,int *back,int value[])
{
  bool sp=false;
  int ic=0; value[i]=back[i]=id++; visited[i]=true;
  for(int v:graph[i])
  {
  	if(!visited[v])
  	{
  		AP(i,v,visited,back,value); ic++;
  		back[i]=min(back[i],back[v]);
  		if(back[v]>=value[i])sp=true;
  	}
  	else back[i]=min(back[i],value[v]);
  }
  if(papa==0)sp=(ic>1)?true:false;
  if(sp)counter++;
}
 
int main() 
{
  int v,e,f,t,i;
  while(cin>>v>>e&&(v||e))
  {
    graph.clear();
    id=1; counter=0;
    bool visited[v+1]={};
    int back[v+1],value[v+1]; value[0]=1;
    for(i=0;i<=v;i++){ graph.push_back({}); visited[i]=back[i]=0; }
    for(i=0;i<e;i++)
    {
      cin>>f>>t;
      graph[f].push_back(t);
      graph[t].push_back(f);
    }
    for(i=1;i<=v;i++)if(!visited[i])AP(0,i,visited,back,value);
    cout<<counter<<endl;
  }
} 
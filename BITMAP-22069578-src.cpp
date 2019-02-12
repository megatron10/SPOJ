#include <iostream>
#include <algorithm>
#include <queue>
#define lli long long int
struct point { int x , y ; } ;
using namespace std;
bool valid(int i,int j, int n,int m)
{	return (i>=0 && i<n && j>=0 && j<m); }
int main() 
{
  int i,j,t,n,m;
	bool matrix[200][200];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		char c;
		queue<point> bfs;
		point tmp;
		int answer[n][m];
		for(i=0;i<n;i++) for(j=0;j<m;j++)
		{
			cin>>c;
			matrix[i][j]=(c=='0')?false:true;
			answer[i][j]=400;
			if(matrix[i][j]){ bfs.push({i,j}); answer[i][j]=0; }
		}
		int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		while(!bfs.empty())
		{
			tmp=bfs.front();
			for(i=0;i<4;i++)
			{
				point tmp2={tmp.x+d[i][0],tmp.y+d[i][1]};
				if( valid(tmp2.x,tmp2.y,n,m) && answer[tmp2.x][tmp2.y]==400 )
				{	answer[tmp2.x][tmp2.y] = answer[tmp.x][tmp.y]+1; bfs.push(tmp2); }
			}
			bfs.pop();
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)cout<<answer[i][j]<<" ";
			cout<<"\n";
		}
	}
}
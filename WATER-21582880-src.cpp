#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node{  int h,x,y;  };
bool operator < (const node &a,const node &b) {return a.h>b.h;}
bool comp(const node&a,const node &b){return b<a;}
int main() 
{
	int t,n,i,j,m,a[107][107]={}; 
	node city[10007] ; 
	cin>>t; 
	int total=0,a1=0,shift[2][4]={{-1,1,0,0},{0,0,1,-1}};
	while(t--)
	{
		cin>>n>>m;
		int answer[100][100]={};
		total=a1=0;
		for(i=0;i<n;i++) for(j=0;j<m;j++) { cin>>a[i][j]; city[(i*m)+j] = { a[i][j] , i , j } ; }//input
		sort(city,city+(n*m),comp);
		for(i=0;i<n*m;i++)
		{
		  node k=city[i];
		  //cout<<k.x<<" "<<k.y<<" "<<k.h<<"\n";
			if(answer[k.x][k.y])continue;
			//cout<<k.x<<" "<<k.y<<" "<<k.h<<endl;
			priority_queue <node> dijkstra; dijkstra.push(k);
			bool visited[100][100]={};
			while(1)
			{
				node tmp=dijkstra.top();
			// cout<<tmp.h<<" "<<tmp.x<<" "<<tmp.y<<"\n";
				if(tmp.x==0 || tmp.x==n-1||tmp.y==0||tmp.y==m-1){a1=tmp.h; break;}
				dijkstra.pop();
				if(!visited[tmp.x][tmp.y])
				{
					visited[tmp.x][tmp.y]=1;
					for(j=0;j<4;j++) 
					{
					 // cout<<tmp.x+shift[0][j]<<" "<<tmp.y+shift[1][j]<<" "<<answer[tmp.x+shift[0][j]][tmp.y+shift[1][j]]<<"\n";
						if(!answer[tmp.x+shift[0][j]][tmp.y+shift[1][j]]) dijkstra.push({max(tmp.h,a[tmp.x+shift[0][j]][tmp.y+shift[1][j]]),tmp.x+shift[0][j],tmp.y+shift[1][j]});
						else dijkstra.push({max(tmp.h,answer[tmp.x+shift[0][j]][tmp.y+shift[1][j]]),0,0});
					}
				}
				
			//	cout<<"\n"<<(dijkstra.top()).h<<"\n";
			}
			//cout<<"Idhar dekhle bhosdike  "<<a1<<endl;
			queue <node> bfs;
			bfs.push(k);
			while(!bfs.empty())
			{
				node k=bfs.front();
				answer[k.x][k.y]=a1;
				for(j=0;j<4;j++)
				{
				  if(k.x+shift[0][j]>=0 && k.x+shift[0][j]<=n-1 && k.y+shift[1][j]>=0 && k.y+shift[1][j]<=m-1)
				  {
  				  int height=a[k.x+shift[0][j]][k.y+shift[1][j]];
  					int &ans=answer[k.x+shift[0][j]][k.y+shift[1][j]];
  					if(!ans)
  					{
  						if(height<a1)bfs.push({height,k.x+shift[0][j],k.y+shift[1][j]});
  						else if(height==a1)ans=a1;
  					}
				  }
				}
				bfs.pop();
			}
		
		//cout<<"\n";
		//for(int namuna=0;namuna<n;namuna++){ for(j=0;j<m;j++)cout<<answer[namuna][j];	cout<<"\n";	}	
		//cout<<"\n";
		}
		for(i=0;i<n;i++){ for(j=0;j<m;j++) total+=answer[i][j]-a[i][j]; }
		cout<<total<<"\n";
	}
	
	return 0;
}

/*

1
5 5
2	4	5	4	7
8	5	4	3	6
2	1	3	8	3
2	9	7	4	7
3	8	3	5	2

24547
85446
22383
29757
38352

24547
85446
22383
29757
38352
 */
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{ int d; int s;};
int walk_no;
int nod[101]={};
edge data[101];
bool dfs(int i,int* walk,int def=0)
{
	int tmp=data[i].d;
	nod[i]=def;
	walk[i]=walk_no;
	def^=data[i].s;
	if(!walk[tmp])	return dfs(tmp,walk,def);
	if(walk[tmp]!=walk_no)return true;
	if((def^nod[tmp]))return false;
	return true;
}
int main() 
{
  int i,n;
	char inp[10];
	while(cin>>n,n)
	{
		walk_no=0;
		int walk[n+1]={};
		for(i=1;i<=n;i++)
		{
			cin>>data[i].d;
			cin>>inp;
			data[i].s=(inp[0]=='f')?1:0;
		}
		for(i=1;i<=n;i++){if(!walk[i]) { walk_no++;  if(!dfs(i,walk)) break; } }
		if(i==n+1)cout<<"NOT ";
		cout<<"PARADOX\n";
		for(i=1;i<101;i++)nod[i]=0;
	}
}
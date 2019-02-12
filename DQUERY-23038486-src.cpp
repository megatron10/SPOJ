#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>
#define pb push_back
#define sz size
#define mp make_pair
#define ff first
#define ss second
// #define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int BIT[300005] = {},n;
 
void update(int p,int v)
{
	for( int i = p; i && i <= n; i += (i&-i) )
		BIT[i] += v;
}
 
int query(int p)
{
	int ret = 0;
	for( int i = p; i ; i -= (i&-i) )
		ret += BIT[i];
	return ret;
}
 
vector < pair<int,int> > qr[300005];
int pre[1000005];
int main()
{
	// nfs	
	int m,i,j,l,r;
	scanf("%d",&n);
	int a[n+1];
 
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	
	scanf("%d",&m);
	int ans[m];
 
	for(j=0;j<m;j++)
	{
		scanf("%d %d",&l,&r);
		qr[r].pb(mp(l,j));
	}
 
	for(i=1;i<=n;i++)
	{
		update(pre[a[i]],-1);	
		update(i,1);
		pre[a[i]] = i;
		int rt = query(i);
		for(auto j : qr[i])
			ans[j.ss] = rt - query(j.ff-1);
	}
 
	for(i=0;i<m;i++)
		printf("%d\n",ans[i]);
}
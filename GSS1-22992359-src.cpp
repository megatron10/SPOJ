#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<climits>
// #include<unordered_map>
 
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
// #define p 1000000007
using namespace std;
struct node{
	int lsum,rsum,bsum,sum;
	int l,r;
	void reset(int l=0,int r=0,int v=0LL)	{	this->lsum=this->rsum=this->bsum=sum=v; this->l=l; this->r=r;}
};
vector<int> val(50005);
vector<node> segTree(200011);
 
void merge(node& f,node& j,node& k)
{
	f.l=j.l; f.r=k.r;
	f.bsum=max({j.bsum,k.bsum,j.rsum+k.lsum});
	f.lsum=max(j.sum+k.lsum,j.lsum);
	f.rsum=max(k.rsum,k.sum+j.rsum);
	f.sum=j.sum+k.sum;
}
 
void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}
 
void init(node& i,int ind)
{
	i.reset(ind,ind,val[ind]);
}
 
void build(int l,int r,int i=1)
{
	if(l==r) {init(segTree[i],l); return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(i);
}
 
void take(int i)
{
	merge(segTree[0],segTree[0],segTree[i]);
}
/*
void push(int i)
{
	segTree[2*i].lazy+=segTree[i].lazy;
	segTree[2*i+1].lazy+=segTree[i].lazy;
	merge(i);
}
 
void range_update(int l,int r,int val,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ a.lazy+=val; return; }
	if(a.lazy) push(i);
	int mt=(a.l+a.r)/2;
	range_update(l,r,val,2*i); range_update(l,r,val,2*i+1);
	merge(i);
}*/
 
void query(int l,int r,int i)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i); return; }
	//if(a.lazy) push(i);
	query(l,r,2*i); query(l,r,2*i+1);
}
 
lli act_query(int l,int r)
{
	segTree[0].reset(0,0,-750350010);
	query(l,r,1);
	return segTree[0].bsum;
}
 
int main()
{
	IOS
	int i,n,x,y,m;
	cin>>n;
	for(i=1;i<=n;i++)cin>>val[i];
	build(1,n,1);
	cin>>m;
	while(m--)
	{
		cin>>x>>y;
		cout<<(act_query(x,y))<<endl;
	}
} 

#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
// #include<unordered_map>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
// #define p 1000000007
using namespace std;
struct node{
	lli lazy,sum;
	int l,r;
	void reset(int l=0,int r=0)	{	this->lazy=this->sum=0; this->l=l; this->r=r;}
};

vector<node> segTree(4000001);

void merge(node& f,node j,node k)
{
	f.reset(j.l,k.r);
	f.sum=j.sum+k.sum+((j.r-j.l+1)*(j.lazy))+((k.r-k.l+1)*k.lazy);
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

void init(node& i,int index)
{
	i.reset(index,index);
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
}

void query(int l,int r,int i)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i); return; }
	if(a.lazy) push(i);
	int mt=(a.l+a.r)/2;
	query(l,r,2*i); query(l,r,2*i+1);
}

lli act_query(int l,int r)
{
	segTree[0].reset(0,0);
	query(l,r,1);
	return segTree[0].sum;
}

int main()
{
	IOS
	int v,j,k,f,t,n,c,p,q;
	cin>>t;
	while(t--)
	{
		segTree.clear();
		segTree.resize(4000001);
		cin>>n>>c;
		build(1,n);
		while(c--)
		{
			cin>>j>>p>>q;
			if(j) cout<<act_query(p,q)<<endl;
			else { cin>>v; range_update(p,q,v); }
		}
	}
}
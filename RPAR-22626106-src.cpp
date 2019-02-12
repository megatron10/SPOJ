#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
// #include<unordered_map>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define p 10007
using namespace std;
struct node{
	int l,r,a,b,c,sum;
	void reset(int n=0,int l=0,int r=0)	{ this->sum=n;	this->a=this->b=this->c=0; this->l=l; this->r=r;}
};

vector<node> segTree(4000001);

int f1(lli r,node &d)
{
	lli a=d.a,b=d.b,c=d.c;
	return ((a*((r*((r+1)*(2*r+1)))/6)%p)%p + (b*((r*(r+1))/2)%p)%p +(c*r)%p)%p;
}

int calc(node &a)
{
	return (a.sum+(f1(a.r,a)+(p-f1(a.l-1,a))%p)%p)%p; 
}


void merge(node& f,node& j,node& k)
{
	f.reset((calc(j)+calc(k))%p,j.l,k.r);
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

void init(node& i,int index)
{
	i.reset(0,index,index);
}

void build(int l,int r,int i=1)
{
	if(l==r) {init(segTree[i],l); return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(i);
}

inline void take(int i){	merge(segTree[0],segTree[0],segTree[i]); }

inline void update_lazy(int a,int b,int c,node &d) {	d.a=(d.a+a)%p;	d.b=(d.b+b)%p;	d.c=(d.c+c)%p; }

inline void update_lazy(node &a,node &b) { 	update_lazy(a.a,a.b,a.c,b); }

inline bool check_lazy(node &a){ return a.a||a.b||a.c; }

void push(int i)
{
	update_lazy(segTree[i],segTree[2*i]);
	update_lazy(segTree[i],segTree[2*i+1]);
	merge(i);
}

void range_update(int aa,int b,int c,int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ update_lazy(aa,b,c,a); return; }
	if(check_lazy(a)) push(i);
	range_update(aa,b,c,l,r,2*i); range_update(aa,b,c,l,r,2*i+1);
	merge(i);
}

void query(int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i); return; }
	if(check_lazy(a)) push(i);
	query(l,r,2*i); query(l,r,2*i+1);
}

int act_query(int l,int r)
{
	segTree[0].reset(0,0,0);
	query(l,r,1);
	return segTree[0].sum;
}

int main()
{
	IOS
	int n,m,f,x0,x1,a,b,c;
	cin>>n>>m;
	build(0,n-1);
	while(m--)
	{
		cin>>f>>x0>>x1;
		if(f) cout<<act_query(x0,x1)<<endl; 	 
		else  { cin>>a>>b>>c; range_update(a,b,c,x0,x1); } 
	}

}
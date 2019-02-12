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
struct node{//problem based
	int l,r,n1,n2;
	void reset(int a1=0,int a2=0,int l=0,int r=0)	{ this->n1=a1;	this->n2=a2; this->l=l; this->r=r;}
};
vector<int> arr;
vector<node> segTree(4000001);

void merge(node& f,node& j,node& k)//problem based
{
	int a1=j.n1,a2=j.n2,b1=k.n1,b2=k.n2;
	if(a1<b1) { swap(a1,b1); swap(a2,b2); }
	if(a2<b1) swap(a2,b1);
	f.reset(a1,a2,j.l,k.r);
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

//problem based
void init(node& i,int index)
{
	i.reset(arr[index],-1001,index,index);
}

void build(int l,int r,int i=1)
{
	if(l==r) {init(segTree[i],l); return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(i);
}

inline void take(int i){	merge(segTree[0],segTree[0],segTree[i]); }

/*
//problem based
inline void update_lazy(int a,int b,int c,node &d) {	d.a=(d.a+a)%p;	d.b=(d.b+b)%p;	d.c=(d.c+c)%p; }

inline void update_lazy(node &a,node &b) { 	update_lazy(a.a,a.b,a.c,b); }

//problem based
inline bool check_lazy(node &a){ return a.a||a.b||a.c; }

void push(int i)
{
	update_lazy(segTree[i],segTree[2*i]);
	update_lazy(segTree[i],segTree[2*i+1]);
	merge(i);
}

//minorly problem based
void range_update(int aa,int b,int c,int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ update_lazy(aa,b,c,a); return; }
	if(check_lazy(a)) push(i);
	range_update(aa,b,c,l,r,2*i); range_update(aa,b,c,l,r,2*i+1);
	merge(i);
}
*/

void update_no(int l,int i=1)
{
	node &a=segTree[i];
	if(a.l==a.r){ init(a,l); return; }
	update_no(l,2*i+(l>(a.l+a.r)/2));
	merge(i);
}

void query(int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i); return; }
	// if(check_lazy(a)) push(i);
	query(l,r,2*i); query(l,r,2*i+1);
}

int act_query(int l,int r)
{
	segTree[0].reset(-1001,-1001,0,0);
	query(l,r,1);
	return segTree[0].n1+segTree[0].n2;
}

int main()
{
	IOS
	int i,n,m,x0,x1,a,b,c; char f;
	arr.push_back(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		arr.push_back(m);
	}
	build(1,n);
	cin>>m;
	while(m--)
	{
		cin>>f>>x0>>x1;
		if(f=='Q') cout<<act_query(x0,x1)<<endl; 
		else  { arr[x0]=x1; update_no(x0); }
	}

}
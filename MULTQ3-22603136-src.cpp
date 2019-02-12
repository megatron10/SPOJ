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
	int lazy=0;
	int l,r,s[3];
	void reset(int l=0,int r=0)	{	this->lazy=0; this->s[0]=this->s[1]=this->s[2]=0; this->l=l; this->r=r;}
};

vector<node> segTree(4000001);
inline int m3(int i){
	return (i>=3)?i-3:i;
}
void merge(node& f,node j,node k)
{
	f.reset(j.l,k.r);
	f.s[j.lazy]+=j.s[0]; f.s[m3(j.lazy+1)]+=j.s[1]; f.s[m3(j.lazy+2)]+=j.s[2];
	f.s[k.lazy]+=k.s[0]; f.s[m3(k.lazy+1)]+=k.s[1]; f.s[m3(k.lazy+2)]+=k.s[2];
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

void init(node& i,int index)
{
	i.reset(index,index);
	i.s[0]=1;
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
	segTree[2*i].lazy=m3(segTree[2*i].lazy+segTree[i].lazy);
	segTree[2*i+1].lazy=m3(segTree[2*i+1].lazy+segTree[i].lazy);
	merge(i);
}

void range_update(int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ a.lazy=m3(a.lazy+1); return; }
	if(a.lazy) push(i);
	int mt=(a.l+a.r)/2;
	range_update(l,r,2*i); range_update(l,r,2*i+1);
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

int act_query(int l,int r)
{
	segTree[0].reset(0,0);
	query(l,r,1);
	return segTree[0].s[0];
}

int main()
{
	//IOS
	int v,j,k,f,t,n,c,p,q;
	scanf("%d %d",&n,&c);
	build(1,n);
	while(c--)
	{
		scanf("%d %d %d",&j,&p,&q);
		if(j) printf("%d\n",act_query(p+1,q+1));
		else  range_update(p+1,q+1); 
	}
}
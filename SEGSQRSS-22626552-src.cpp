#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define p 10007
using namespace std;
struct node{//problem based
	lli l,r,sqs,s,n,add,val;
	void reset(lli a1=0,lli a2=0,lli l=0,lli r=0)	{this->add=0; this->val=10000; this->sqs=a1;	this->s=a2; this->l=l; this->r=r; this->n=r-l+1; }
};

vector<lli> arr;
vector<node> segTree(4000001);

bool valid(lli val){ return val<=1000; }

lli calc_sqs(node &a)
{
	if(valid(a.val)) return a.n*(a.val+a.add)*(a.val+a.add);
	else     		 return a.sqs+(a.s*2*a.add)+(a.n*a.add*a.add);
}

lli calc_s(node &a)
{
	if(valid(a.val)) return a.n*(a.val+a.add);
	else             return a.s+a.add*a.n; 
}

void merge(node& f,node& j,node& k)//problem based
{
	f.reset(calc_sqs(j)+calc_sqs(k),calc_s(j)+calc_s(k),j.l,k.r);
}

void merge(int i)
{
	merge(segTree[i],segTree[2*i],segTree[2*i+1]);
}

//problem based
void init(node& i,int index)
{
	i.reset(arr[index]*arr[index],arr[index],index,index);
}

void build(int l,int r,int i=1)
{
	if(l==r) {init(segTree[i],l); return;}
	int m=(l+r)/2;
	build(l,m,2*i); build(m+1,r,2*i+1);
	merge(i);
}

inline void take(int i){	merge(segTree[0],segTree[0],segTree[i]); }

//problem based
inline void update_lazy(lli val,lli add,node &d)
{
	if(valid(val)){ d.val=val; d.add=add; }
	else	d.add+=add;
}

inline void update_lazy(node &a,node &b) { 	update_lazy(a.val,a.add,b); }

//problem based
inline bool check_lazy(node &a){ return valid(a.val)||a.add; }

void push(int i)
{
	update_lazy(segTree[i],segTree[2*i]);
	update_lazy(segTree[i],segTree[2*i+1]);
	merge(i);
}

//minorly problem based
void range_update(lli val,lli add,int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ update_lazy(val,add,a); return; }
	if(check_lazy(a)) push(i);
	range_update(val,add,l,r,2*i); range_update(val,add,l,r,2*i+1);
	merge(i);
}

/*
void update_no(int l,int i=1)
{
	node &a=segTree[i];
	if(a.l==a.r){ init(a,l); return; }
	update_no(l,2*i+(l>(a.l+a.r)/2));
	merge(i);
}*/

void query(int l,int r,int i=1)
{
	node &a=segTree[i];
	if(r<a.l || l>a.r)return;
	if(a.l>=l && a.r<=r){ take(i); return; }
	if(check_lazy(a)) push(i);
	query(l,r,2*i); query(l,r,2*i+1);
}

//problem based
lli act_query(int l,int r)
{
	segTree[0].reset(0,0,0,0);
	query(l,r,1);
	return segTree[0].sqs;
}

int main()
{
	IOS
	int j,i,t,n,q,st,nd,x,f;
	cin>>t;
	for(j=1;j<=t;j++)
	{
		cout<<"Case "<<j<<":"<<endl;
		segTree.clear();
		arr.clear(); arr.push_back(0);
		cin>>n>>q;
		segTree.reserve(4*n+1);
		for(i=1;i<=n;i++)
		{
			cin>>f;
			arr.push_back(f);
		}
		build(1,n);
		while(q--)
		{
			cin>>f>>st>>nd;
			switch(f)
			{
				case 0:
					cin>>x;
					range_update(x,0,st,nd);
					break;
				case 1:
					cin>>x;
					range_update(10000,x,st,nd);
					break;
				case 2:
					cout<<act_query(st,nd)<<endl;
			}
		}
	}
}
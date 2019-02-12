#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>
#define pb push_back
#define sz size
#define mp make_pair
using namespace std;
using ll=int;
ll ptr = 0;
struct node{
	ll c[2],l,r,cnt;
	void reset(ll c0,ll c1,ll l,ll r,ll cnt){ this->c[0]=c0; this->c[1]=c1; this->l=l; this->r=r; this->cnt=cnt; }
};
node nd[2168965]; 
void build(ll l,ll r,ll i=1){
	if( l == r ) { nd[i].reset(0, 0, l, r, 0); return; }
	ll mid = (l + r) / 2;
	nd[i].reset(2*i, 2*i+1, l, r, 0);
	build( l, mid, 2*i ); build( mid + 1, r, 2*i + 1 );
}

ll inc_no(ll l, ll i=1){
	node &a = nd[i];
	if(a.l==a.r)  { nd[++ptr].reset(0, 0, l, l, a.cnt + 1); return ptr; }
	bool dir; ll tmp = inc_no( l , a.c[ dir = (l > (a.l + a.r)/2) ] );
	if( dir ) nd[++ptr].reset( a.c[0], tmp, a.l, a.r, a.cnt + 1 );
	else 	  nd[++ptr].reset( tmp, a.c[1], a.l, a.r, a.cnt + 1 );
	return ptr;
}

ll query(ll i,ll j,ll k){
	node &l = nd[i]; node &r= nd[j]; ll tmp;
	if(l.l==l.r) { k = 0; return l.l; }
	if( (tmp = nd[r.c[0]].cnt - nd[l.c[0]].cnt) >= k ) return query(l.c[0], r.c[0] ,k);
	return query(l.c[1], r.c[1], k-tmp);
}

ll root[100009]={1};
int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll i,n,m,j,k,dis=0; scanf("%d %d",&n,&m);
	pair<ll,ll> inp[n];
	ll values[n+1];
	for(i=0;i<n;i++){ inp[i].second = i+1; scanf("%d",&inp[i].first); } 

	sort(inp, inp+n);
	for(auto j:inp) values[j.second] = ++dis;
	build(1,n); ptr = 4*n;
	for(i=1; i<=n; i++) root[i] = inc_no(values[i], root[i-1]);
	while(m--){
		scanf("%d %d %d",&i,&j,&k);
		printf("%d\n",(inp[ query( root[i-1], root[j], k ) - 1].first));
	}
}
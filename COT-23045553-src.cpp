#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>
#define pb push_back
#define sz size
#define mp make_pair
#define ll long long int
using namespace std;

ll ptr = 0;
struct node{
	ll c[2],l,r,cnt;
	void reset(ll c0,ll c1,ll l,ll r,ll cnt){ this->c[0]=c0; this->c[1]=c1; this->l=l; this->r=r; this->cnt=cnt; }
};
node nd[2417959];
void build(ll l,ll r,ll i = 1){
	if( l == r ) { nd[i].reset(0,0,l,r,0); return; }
	ll mid = (l + r)/2;
	nd[i].reset(2*i, 2*i+1, l, r, 0);
	build( l, mid, 2*i ); build( mid + 1, r, 2*i + 1 );
}
 
ll inc_no(ll l, ll i=1){
	node &a = nd[i];
	if(a.l==a.r)  { nd[++ptr].reset(0, 0, l, l, a.cnt + 1); return ptr; }
	bool dir; ll tmp = inc_no(l , a.c[ dir = (l>(a.l + a.r)/2) ]);
	if( dir ) nd[++ptr].reset(a.c[0], tmp, a.l, a.r, a.cnt + 1);
	else 	  nd[++ptr].reset(tmp, a.c[1], a.l, a.r, a.cnt + 1);
	return ptr;
}
 
ll query(ll a,ll b,ll c,ll d,ll k)
{
	node &r1 = nd[a],&r2 = nd[b],&r3 = nd[c],&r4 = nd[d]; ll tmp;
	if(r1.l == r1.r) { k = 0; return r1.l; }
	if( ( tmp = nd[r1.c[0]].cnt + nd[r2.c[0]].cnt - nd[r3.c[0]].cnt - nd[r4.c[0]].cnt ) >= k )
		return query(r1.c[0], r2.c[0] , r3.c[0], r4.c[0], k);
	return query(r1.c[1], r2.c[1], r3.c[1], r4.c[1], k - tmp);
}
 
ll root[111112] = {1};

vector<int> graph[111112];

int up[111112][17],tm[111112][2],timer = 0,n;
ll values[111112];

void dfs(int u = 1, int par = 0)
{
	root[u] = inc_no( values[u], root[par] );
	up[u][0] = par;
	tm[u][0] = timer++;
	for(int v : graph[u]) if(v!=par) dfs(v,u);
	tm[u][1] = timer++;
}

void build_lca()
{
	for(int i = 1; i<17; i++) for(int u = 1; u<=n; u++)	up[u][i] = up[up[u][i-1]][i-1];
}

bool is_anc(int u,int v)
{
	return (tm[u][0] <= tm[v][0] && tm[u][1] >= tm[v][1]);
}

int lca(int u,int v)
{
	if( u == v ) return u;
	if( tm[u][0] <= tm[v][0] ) swap(u,v);
	for(int i = 16; i>=0; i--)	if(!is_anc(up[u][i],v))	u = up[u][i];
	return up[u][0];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i,m,j,k,u,v,dis = 0;
	cin>>n>>m;
	pair<ll,int> inp[n];
	for(i=0;i<n;i++){ inp[i].second = i+1; cin>>inp[i].first; } 
 
	sort(inp, inp+n);

	for(auto j:inp)
		values[j.second] = ++dis;

	build(1,n);
	ptr = 4*n;
	
	for(i=1; i<n; i++)
	{
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	tm[0][0] = timer++; dfs(1); tm[0][1] = timer++;
	build_lca();

	while(m--)
	{
		cin>>i>>j>>k; int anc = lca(i,j);
		// cout<<i<<" "<<j<<" "<<anc<<" "<<up[anc][0]<<"\n"; 
		cout<<inp[ query( root[i], root[j], root[anc], root[up[anc][0]], k ) - 1 ].first<<"\n";
	}
} 
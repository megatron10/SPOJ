#include <iostream>
#include <unordered_map>
#include <algorithm>
#define lli long long int
using namespace std;
unordered_map <int,int> umap[2];
int main()
{
	int n;
	cin>>n; int num[n]; lli ans=0;
	for(int i=0;i<n;i++) cin>>num[i];
	for(auto i:num) for(auto j:num) for(auto k:num) { if(umap[0].count(i*j+k))umap[0][i*j+k] += 1; else umap[0][i*j+k]=1; }
	for(auto i:num) for(auto j:num) for(auto k:num) if(i) { if(umap[1].count(i*(j+k))) umap[1][i*(j+k)] += 1; else umap[1][i*(j+k)]=1; }
	for(auto v:umap[0]) ans += (umap[1].count(v.first))?(1LL*umap[1][v.first])*v.second:0;
	cout<<ans<<endl;	 
	return 0;
} 
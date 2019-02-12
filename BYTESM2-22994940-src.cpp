#include<iostream>
#include<algorithm>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
int h,w,inp[101][101];
int ref(int r,int c){
	return (r>=0 && r<h && c>=0 && c<w)?inp[r][c]:0;
}
using namespace std;
int main()
{
	IOS
	int i,j,t,ans;
	cin>>t;
	while(t--){
		ans=0;
		cin>>h>>w;
		for(i=0;i<h;i++) for(j=0;j<w;j++) cin>>inp[i][j];
		for(i=h-1;i>=0;i--) for(j=w-1;j>=0;j--) inp[i][j] += max({ref(i+1,j-1),ref(i+1,j),ref(i+1,j+1)});
		for(j=0;j<w;j++) ans = max(ans,inp[0][j]);
		cout<<ans<<endl;
	}
}
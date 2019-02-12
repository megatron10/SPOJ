#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main() 
{
  int ans,t,i,j,n,h,m,s,lim,times[20001];char c;
	cin>>t;
	for(j=1;j<=t;j++)
	{
		cin>>n;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>h>>c>>m>>c>>s;
			times[i]=3600*h+60*m+s;
		}
		cin>>lim;
		sort(times,times+n);
		//cout<<n<<"\n";
		queue <int> gf;
		for(i=0;i<n;i++)
		{
			gf.push(times[i]);
			if(gf.size()!=1 && times[i]-gf.front()>=lim) gf.pop();
			//cout<<i<<"	"<<ans<<"\n";
		}
		cout<<"Case "<<j<<": "<<gf.size()<<"\n";
	}
}
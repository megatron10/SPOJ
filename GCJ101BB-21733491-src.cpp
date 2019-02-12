#include <iostream>
using namespace std;
int main() 
{
  long int done,j,i,c,n,k,b,t,ans=0,x[50]={},v[50]={};
	cin>>c;
	for(j=1;j<=c;j++)
	{
		cin>>n>>k>>b>>t;
		for(i=0;i<n;i++)cin>>x[i];
		for(i=0;i<n;i++)cin>>v[i];
		done=ans=0; i--;
		for(;i>=0 && done<=k;i--)
		{
			if((b-x[i])<=v[i]*t)done++;
			else ans+=k-done;
		}
		cout<<"Case #"<<j<<": ";
		if(done<k)cout<<"IMPOSSIBLE\n";
		else cout<<ans<<"\n";
	}
}
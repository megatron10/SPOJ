#include <iostream>
#include <algorithm>
using namespace std;
struct data { int h,c ; };
bool operator < (data a,data b){ return a.h<b.h; }
int main() 
{
  int i,t,n,tmp[10001]={};
	long int answer=0;
	data bldg[10001];
	bldg[10000].h=1000000;
	cin>>t;
	while(t--)
	{
		cin>>n;
		answer=0;
		for(i=0;i<n;i++)cin>>bldg[i].h;
		for(i=0;i<n;i++)cin>>bldg[i].c;
		sort(bldg,bldg+n);
		for(i=0;i<n;i++)tmp[i+1]=tmp[i]+bldg[i].c;
		for(i=0;i<n;i++)answer+=(bldg[i].h-bldg[0].h)*bldg[i].c;
		i=0;
		for(int j=bldg[0].h;j<bldg[n-1].h;j++)
		{
			while(bldg[i].h==j) i++;
			if(2*tmp[i]-tmp[n]<0)answer+=2*tmp[i]-tmp[n];
			else break;
		}
		cout<<answer<<"\n";
	}
}
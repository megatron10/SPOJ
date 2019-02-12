#include <iostream>
using namespace std;
int main() 
{
  long int c,i,j,tmp,ans=0,count=0,w[64];
	string str;
	cin>>c;
	for(j=1;j<=c;j++)
	{
		cin>>str;
		count=1;ans=0;
		int val[256]={};
		for(i=0;i<256;i++)val[i]=-1;
		w[0]=1; val[str[0]]=1; i=1;
		while(i<str.size() && str[i]==str[0])w[i++]=1;
		if(i<str.size()){w[i]=0; val[str[i++]]=0; count++;}
		while(i<str.size())
		{
			if(val[str[i]]==-1)	val[str[i]]=count++;
			w[i]=val[str[i]];	
			i++;
		}
		if(count==1)count++;
		long int tmp=1;
		for(i=str.size()-1;i>=0;i--){ans+=w[i]*tmp; tmp*=count;}
		cout<<"Case #"<<j<<": "<<ans<<"\n";
	}
}
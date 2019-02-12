#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() 
{
	int i,j,t,tmp; string S,S2;
	cin>>t;
	while(t--)
	{
		cin>>S;
		tmp=S.length();
			
		for(i=0;i<tmp;i++)if(S[i]!='9')break;
		if(i!=tmp)
		{	
			i=2;
			for(j=(tmp-1)/2;j>=0;j--){if(S[j]>S[tmp-1-j]){i=1;break;}else if(S[j]<S[tmp-1-j]){i=0;break;}}
			if(j!=-1 && i==1)goto end;	
			i=(tmp+1)/2;
			while(S[--i]=='9')S[i]='0';
			S[i]+=1;
			end : for(i=tmp/2;i<tmp;i++)S[i]=S[tmp-1-i];
			cout<<S<<"\n";	
		}
		else
		{
			cout<<'1';
			for(i=1;i<tmp;i++)cout<<'0';
			cout<<'1'<<"\n";
		}
	}
	return 0;
}
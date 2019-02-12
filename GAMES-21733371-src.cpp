#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() 
{
  int t; double n; cin>>t;
	while(t--)
	{
		int count=1,p=0;
		cin>>n;
		n=n-(int)n;
		while(n!=(int)n)
		{
			string tmp=(to_string(n));
			string::reverse_iterator it1;
			it1=tmp.rbegin();
			while((*(it1))=='0')it1++;
			if(*it1=='.')break;
			if(*it1-'0'==5){n*=2; count*=2;}
			else{n*=5; count*=5;}
		}
		cout<<count<<"\n";
	}
}
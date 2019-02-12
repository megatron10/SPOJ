#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;
int main()
{
	int cs = 1,i,j,k,n,m; string s,s1,s2; double exc;
	while(cin>>n, n){
		bool arbit=0;
		double dp[n][n] = {};
		unordered_map <string,int> curr;
		for(i=0;i<n;i++){
			cin>>s;
			curr.insert(make_pair(s,i));
			dp[i][i] = 1.0;
		}

		cin>>m;
		for(i=0;i<m;i++){
			cin>>s1>>exc>>s2;
			dp[curr[s1]][curr[s2]] = exc;
		}

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					dp[j][k] = max(dp[j][k],dp[j][i]*dp[i][k]);

		for(i=0;i<n;i++)if(dp[i][i]>1){arbit = 1; break;}
		cout<<"Case "<<cs<<": "<<((arbit)?"Yes":"No")<<"\n";
		cs++;
	}
}
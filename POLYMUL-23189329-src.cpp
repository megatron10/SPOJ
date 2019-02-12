#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
#define vcd vector<cd>
#define PI acos(-1)
#define pb push_back

int next_pow2(int no) { for(int i=0;i<6;i++) no |= no>>(1<<i);   return (no+1); }

void fft(vector<cd>& pol, int inv = 1)
{
	int n = pol.size(),i;
	if(n==1) return;
	
	vector<cd> e,o;
	
	for(i=0; i<n; i += 2) {	 e.pb(pol[i]);  o.pb(pol[i+1]); }
	
	fft(e,inv);
	fft(o,inv);

	cd w[n];

	for(i=0; i<n/2; i++) w[i] = cd(cos((2*PI*i*inv)/n),sin((2*PI*i*inv)/n));
	for(i=0; i<n/2; i++) pol[i] = e[i] + w[i]*o[i];
	for(i=0; i<n/2; i++) pol[i+(n/2)] = e[i] - w[i]*o[i];
	return;

}

void print(vector<cd> poly,int n)
{
	for(int i=n-1; i>=0; i--) cout<<((long long)round(poly[i].real()))<<" "; cout<<"\n";
}

vector<cd> polymul(vector<cd> a, vector<cd> b)
{
	int n = next_pow2( a.size() + b.size() - 1 ),i;
	a.resize(n,cd(0.0, 0.0));	b.resize(n,cd(0.0, 0.0));
	fft(a);
	fft(b);
	
	vector <cd> fab;
	transform(a.begin(), a.end(), b.begin(), back_inserter(fab), multiplies<cd>());
	
	fft(fab,-1);
	for(i=0;i<n;i++)fab[i] /= n;
	return fab;
}

int main()
{
	int i,n,t,c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<cd> a,b;
		for(i=0;i<=n;i++){
			cin>>c;
			a.pb(cd(c,0));
		}
		for(i=0;i<=n;i++){
			cin>>c;
			b.pb(cd(c,0));
		}
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		print(polymul(a,b),2*n+1);
	}
}
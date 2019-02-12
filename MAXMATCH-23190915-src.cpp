#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
#define pb push_back
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
double PI = acos(-1);
int next_pow2(int no) { for(int i=0;i<6;i++) no |= no>>(1<<i);   return (no+1); }

void fft(vector<cd>& pol, int inv = 1)
{
	int n = pol.size(),i,j,l;
	if(n==1) return;

	cd w[n]={cd(1.0,0.0)}, w1 = cd(cos((2*PI*inv)/n),sin((2*PI*inv)/n));
	for(i=1; i<n; i++) w[i] = w[i-1]*w1;
	for (i=1, j=0; i<n; i++) {
        int bit = n >> 1;
        for (; j&bit; bit>>=1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(pol[i], pol[j]);
    }

	for(l=2; l<=n; l = l<<1){
		int jump = n/l;
		for(i=0; i<n; i += l){
			for(j=0; j<l/2; j++){
				cd& u = pol[i+j]; cd& v = pol[i+j+l/2]; cd mul = w[j*(n/l)];
				tie(u,v) = make_tuple(u + mul*v, u - mul*v);
			}
		}
	}

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
	for(i=0; i<n; i++) fab[i] /= n;
	return fab;
}

int main()
{
	nfs_mw
	int i,j,maxm = 0,l,c;
	string s;
	cin>>s; l=s.length();
	vector<int> out;
	vector <cd> pol[3][3];
	for(i=0; i<3; i++) for(j=0;j<2;j++) pol[i][j].resize(l,cd(0.0,0.0));
	for(i=0 ;i<l; i++){
		c = s[i]-'a';
		pol[c][0][i] = cd(1.0,0.0);
		pol[c][1][l-1-i] = cd(1.0,0.0);
	}
	for(i=0;i<3;i++)
		pol[i][2] = polymul(pol[i][0],pol[i][1]);
	for(i=l; i<2*l; i++){
		int tmp=0;
		for(j=0;j<3;j++) tmp += round(pol[j][2][i].real());
		if(tmp>maxm){
			maxm = tmp;
			out.clear();
		}
		if(tmp==maxm) out.pb(i-l+1);
	}
	cout<<maxm<<"\n";
	for(auto v:out) cout<<v<<" ";
	cout<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
using cd = complex<double>;
#define pb push_back
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
double PI = acos(-1);
int next_pow2(int no) { for(int i=0;i<6;i++) no |= no>>(1<<i);   return (no+1); }

void fft(vector<cd>& pol, int inv = 1)
{
	int n = pol.size(),i,j,l,jump,ang;
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

	for(l=2; l<=n; l = l<<1)//length of merged block
		for(i=0; i<n; i += l)//iterate over the blocks
			for(j=0,ang=0,jump=n/l; j<l/2; j++,ang += jump)//form each block
			{
				cd& u = pol[i+j]; cd& v = pol[i+j+l/2]; cd mul = w[ang];
				tie(u,v) = make_tuple(u + mul*v, u - mul*v);
			}
	
	return;
}

void print(vector<cd> poly)
{
	for(int i=0; i<poly.size(); i++) cout<<((int)round(poly[i].real()))<<" "; cout<<"\n";
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
	// nfs_mw
	int i,j,maxm = 0,l,c,lr;
	string s,r;
	cin>>s>>r; l=s.length(); lr=r.length();
	int ref[100]={}; ref['A'] = 0; ref['G'] = 1; ref['C'] = 2; ref['T'] = 3;
	vector <cd> pol[4][3];
	for(i=0; i<4; i++) { pol[i][0].resize(l,cd(0.0,0.0)); pol[i][1].resize(lr,cd(0.0,0.0)); }
	for(i=0; i<l; i++) {
		c = ref[(int)s[i]];
		pol[c][0][i] = cd(1.0,0.0);
	}
	for(i=0;i<lr;i++){
		c = ref[r[i]];
		pol[c][1][lr-1-i] = cd(1.0,0.0);
	}

	for(i=0;i<4;i++){
		pol[i][2] = polymul(pol[i][0],pol[i][1]);
	}

	for(i=0; i<=l-lr; i++){
		int tmp=0;
		for(j=0;j<4;j++) tmp += (pol[j][2].size()>(i+lr-1))?(round(pol[j][2][i+lr-1].real())):0;
		maxm = max(tmp,maxm);
	}
	cout<<(lr-maxm)<<"\n";
}

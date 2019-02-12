#include <iostream>
using namespace std;
char a[3][4];
int i,j,count;
bool eq(char a, char b, char c, char d) {return (a==b && b==c && c==d);}

int wins(char c) {
	count=0;
	for(i=0;i<3;i++)
		count+=eq(a[i][0],a[i][1],a[i][2],c)+eq(a[0][i],a[1][i],a[2][i],c);
	count+=eq(a[0][0],a[1][1],a[2][2],c);
	count+=eq(a[2][0],a[1][1],a[0][2],c);
	return count;
}

int main() {
	int t,x,o,wx,wo; cin>>t;
	bool b;
	while(t--) {
//		scanf("%s %s %s",a[0],a[1],a[2]);
		o=x=0;
		cin>>a[0]>>a[1]>>a[2];
//		for(i=0;i<3;i++) {for(j=0;j<3;j++) cout<<a[i][j];cout<<"\n";}
		for(i=0;i<3;i++) for(j=0;j<3;j++) {
			if(a[i][j]=='O') o++;
			if(a[i][j]=='X') x++;
		}
		wx=wins('X'); wo=wins('O');
		
		if(((!wo)&& (x-o)==1)||((!wx)&&(x==o))) printf("yes\n");
		else printf("no\n");
	}
}
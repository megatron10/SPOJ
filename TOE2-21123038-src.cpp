#include <iostream>
using namespace std;
char a[9];
int i,j,count;
bool eq(char a, char b, char c, char d) {return (a==b && b==c && c==d);}

int wins(char c) {
	for(i=0;i<3;i++)
		if(eq(a[3*i],a[3*i+1],a[3*i+2],c)||eq(a[i],a[3+i],a[6+i],c)) return 1;
	if(eq(a[0],a[4],a[8],c)||eq(a[2],a[4],a[6],c)) return 1;
	return 0;
}

int main() {
	int x,o,wx,wo;
	bool b;
		while(cin>>a && a[0]!='e')
		{
			o=x=0;
			for(i=0;i<9;i++) {
				if(a[i]=='O') o++;
				if(a[i]=='X') x++;
			}
			wx=wins('X'); wo=wins('O');
			if(((!wo)&&wx&& (x-o)==1)||((!wx)&&wo&&(x==o))||(!wx&&!wo&&x==5&&o==4)) printf("valid\n");
			else printf("invalid\n");
		}	
	
}
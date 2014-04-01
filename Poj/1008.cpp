#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char haab[30][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char tzol[30][10]={ "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main(){
	int t;
	for(scanf("%d",&t),printf("%d\n",t);t;t--){
		char s[30];
		int d,y;
		scanf("%d. %s %d",&d,s,&y);getchar();
		int mm=0;
		while(strcmp(haab[mm],s)!=0)mm++;
		int DD=365*y+mm*20+d;
		int Y=DD/260;
		int X=DD%260;
		printf("%d %s %d\n",X%13+1,tzol[X%20],Y);
	}
	return 0;
}

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
bool cmp(const char x,const char y){
	if(x-y=='A'-'a')return 1;
	if(y-x=='A'-'a')return 0;
	char xx=x,yy=y;
	if(xx>='a')xx-='a';
	if(xx>='A')xx-='A';
	if(yy>='a')yy-='a';
	if(yy>='A')yy-='A';
	return xx<yy;
}
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int T;
	char s[20];
	for(scanf("%d",&T);T;T--){
		scanf("%s",s);
		int len=strlen(s);
//		printf("%s-->",s);
		sort(s,s+len,cmp);
//		printf("%s\n",s);
		do{
			puts(s);
		}while(next_permutation(s,s+len,cmp));
	}
return 0;}

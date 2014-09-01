#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define LL long long
int main(){
//	freopen("headshot.in","r",stdin);
//	freopen("headshot.out","w",stdout);
	char s[111];
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		int i;
		int tot0=0;
		int tot00=0;
		for(i=0;i<len;i++)if(s[i]=='0')tot0++;
		for(i=0;i<len-1;i++)if(s[i]=='0'&&s[i+1]=='0')tot00++;
		if(s[0]=='0'&&s[len-1]=='0')tot00++;
		int rota=tot0,rotb=len;
		int shoa=tot00,shob=tot0;
		if(rota*shob==rotb*shoa){printf("EQUAL\n");}
		else if(rota*shob>rotb*shoa){printf("ROTATE\n");}
		else if(rota*shob<rotb*shoa){printf("SHOOT\n");}
	}
	return 0;
}
/*
0
0011
0111
000111
*/

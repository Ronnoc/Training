/*
ID: kybconn1
PROG: namenum
LANG: C++
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namesapce std;
struct stg{
	char s[15];
	
	}tp;
vector<stg>dic;
vector<stg>::iterator iter;
int main(){
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",a+b);
	return 0;
	}

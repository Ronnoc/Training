#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
char f[11][5][5]={
	{
		"329",
		"418",
		"567"
	},
	{
		"923",
		"814",
		"765"
	},
	{
		"345",
		"216",
		"987"
	},
	{
		"987",
		"216",
		"345"
	},
	{
		"567",
		"418",
		"329"
	},
	{
		"765",
		"814",
		"923"
	},
	{
		"789",
		"612",
		"543"
	},
	{
		"543",
		"612",
		"789"
	},
};
int main(){
	int i,j,k,_T;
	char s[5][5];
	for(i=0;i<3;i++)
		scanf("%s",s[i]);
	for(i=0;i<8;i++){
		int fail=0;
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				if(s[j][k]!='?'&&s[j][k]!=f[i][j][k])
					fail=1;
		if(!fail){
			for(j=0;j<3;j++)
				printf("%s\n",f[i][j]);
			break;
		}
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char l[5010],r[5010];
unsigned short dp[2][5010];
int main(){
	int len;
	while(scanf("%d",&len)!=EOF){
		int i,j;
		scanf("%s",l);
		for(i=0;i<len;i++)r[i]=l[len-1-i];
		for(i=0;i<2;i++)for(j=0;j<len;j++)dp[i][j]=0;
		for(i=0;i<len;i++){
			dp[i%2][0]=l[i]==r[0]?1:0;
			for(j=1;j<len;j++)
				dp[i%2][j]=(l[i]==r[j])?dp[(i+1)%2][j-1]+1:max(dp[i%2][j-1],dp[(i+1)%2][j]);
		}
		printf("%d\n",len-(int)dp[(len+1)%2][len-1]);
	}
	return 0;
}

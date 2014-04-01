#include<stdio.h>
#define inf (int)1e9
#include<algorithm>
int g[110][110];
int n;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,j,k;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i>j){
			char s[100];
			scanf("%s",s);
			if(s[0]=='x')g[i][j]=g[j][i]=inf;
			else {
				int r;sscanf(s,"%d",&r);
				g[i][j]=g[j][i]=r;
				}
			}else if(i==j)g[i][i]=0;
		for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++){
			g[i][j]=std::min(g[i][j],g[i][k]+g[k][j]);
			}
		int res=0;
		for(i=2;i<=n;i++)res=std::max(res,g[1][i]);
		printf("%d\n",res);
		}	
	return 0;
	}

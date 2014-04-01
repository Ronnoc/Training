#include<stdio.h>
int f[30],d[30],g[30];
int n,t,k[30];
int map[30][30];
int main(){
	int z=1;
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&t);
		t*=60;
		int i,j;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)map[i][j]=0;
		for(i=1;i<=n;i++)scanf("%d",&f[i]);
		for(i=1;i<=n;i++)scanf("%d",&d[i]);
		g[1]=0;
		for(i=2;i<=n;i++){
			int x;
			scanf("%d",&x);
			g[i]=g[i-1]+x*5;
			}
		for(i=1;i<=n;i++)k[i]=(t-g[i])/5;	
		int res[30];
		for(i=1;i<=n;i++){
			int tf[30];
			res[i]=0;
			for(j=1;j<=i;j++)tf[j]=f[j];
			int u;
			for(u=1;u<=k[i];u++){
				int max=tf[1],pax=1;
				for(j=2;j<=i;j++)if(tf[j]>max){
					max=tf[j];
					pax=j;
					}
				if(max>0){
					map[i][pax]++;
					res[i]+=tf[pax];
					tf[pax]-=d[pax];
					}
				else {
					map[i][1]++;
					}
				}
			}	
		int ans=res[1],pns=1;
		for(i=2;i<=n;i++)if(res[i]>ans){ans=res[i];pns=i;}
		int fi=1;
		if(z)z=0;
		else printf("\n");
		for(i=1;i<=n;i++){
			if(fi)fi=0;
			else printf(", ");
			printf("%d",map[pns][i]*5);
			}printf("\n");
		printf("Number of fish expected: %d\n",ans);
		}
	return 0;
	}

#include<stdio.h>
#include<vector>
std::vector<int>p[1000010];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i;
		for(i=1;i<=1000000;i++)p[i].clear();
		for(i=1;i<=n;i++){
			int z;
			scanf("%d",&z);
			p[z].push_back(i);
			}
		int k,v;
		for(i=1;i<=m;i++){
			scanf("%d%d",&k,&v);
			if(p[v].size()>=k)printf("%d\n",p[v][k-1]);
			else printf("0\n");
			}
		}
	return 0;
	} 

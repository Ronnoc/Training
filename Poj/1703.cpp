#include<stdio.h>
#define N 100010
int ft[N],enmy[N];
int _ini(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i;
	for(i=1;i<=n;i++)enmy[i]=-1;
	}
int find(int x){
	return x==ft[x]?x:ft[x]=find(ft[x]);
	}
void merge(int x,int y){
	int u=find(x),v=find(y);
	ft[u]=v;
	}
void add(int a,int b){
	int ea=enmy[a];
	int eb=enmy[b];
	if(eb!=-1)merge(eb,a);
	if(ea!=-1)merge(ea,b);
	int ra=find(a);
	int rb=find(b);
	enmy[ra]=rb;
	enmy[rb]=ra;
	}
int main(){
	int T=20;
	scanf("%d",&T);
	while(T--){
		int n,m,i,p,q;
		scanf("%d%d%*c",&n,&m);
		_ini(n);
		for(i=1;i<=m;++i){
			char x;
			scanf("%c %d %d%*c",&x,&p,&q);
			if(x=='D')add(p,q);
			else {
				int rx=find(p);
				int ry=find(q);
				if(enmy[rx]==ry)printf("In different gangs.\n");
				else if(rx==ry)printf("In the same gang.\n");
				else printf("Not sure yet.\n");
				}
			}
		
		}
	return 0;
	}

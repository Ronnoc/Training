#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 200010
struct edge{
	int p,q,w;
	bool operator < (const edge& b)const {
		return w<b.w;
		}
	};
std::vector<edge>L;
int ft[MAX];
void in_ft(int n){
	int i;
	for(i=0;i<n;i++)ft[i]=i;
	}
int find(int x){
	int t=x,temp;
	while(ft[x]!=x)x=ft[x];
	while(t!=x){
		temp=ft[t];
		ft[t]=x;
		t=temp;
		}
	return x;
	}
void merge(int root1,int root2){
	int fr1=find(root1);
	int fr2=find(root2);
	ft[fr1]=fr2;
	}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(!m&&!n)break;
		L.clear();
		in_ft(n);
		int i;
		int sum=0;
		for(i=1;i<=m;i++){
			int p,q,w;
			scanf("%d%d%d",&p,&q,&w);
			L.push_back( (edge){p,q,w} );
			sum+=w;
			}
		std::sort(L.begin(),L.end());
		int res=0;
		for(i=0;i<L.size();i++){
			if( find(L[i].p) != find(L[i].q) ){
				merge(L[i].p,L[i].q);
				res+=L[i].w;
				}
			}
		printf("%d\n",sum-res);
		}
	return 0;
	}

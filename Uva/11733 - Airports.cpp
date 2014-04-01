#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 10010
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
	for(i=1;i<=n;i++)ft[i]=i;
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
	find(root1);
	find(root2);
	}
int is_root(int x){
	if(ft[x]==x)return 1;
	return 0;
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		L.clear();
		int n,m,A;
		scanf("%d%d%d",&n,&m,&A);
		in_ft(n);
		int i;
		for(i=1;i<=m;i++){
			int p,q,w;
			scanf("%d%d%d",&p,&q,&w);
			if(w<A)L.push_back( (edge){p,q,w} );
			}
		std::sort(L.begin(),L.end());
		long long res=0;
		for(i=0;i<L.size();i++){
			if( find(L[i].p) != find(L[i].q) ){
				merge(L[i].p,L[i].q);
				res+=L[i].w;
				}
			}
		int sum=0;
		for(i=1;i<=n;i++)sum+=is_root(i);
		res+=sum*A;
		printf("Case #%d: %lld %d\n",k,res,sum);
		}
	return 0;
	}

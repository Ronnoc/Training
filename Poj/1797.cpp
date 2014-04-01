#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1010
#define INF (int)1e9
struct line{
	int l,r,w;
	bool operator <(const line &tp)const{return w>tp.w;}
	}tp;
int ft[N];
int find(int x){return (x==ft[x])? x:ft[x]=find(ft[x]); }
void ini(int n){while(n){ft[n]=n;n--;}}
void merge(int a,int b){
	int ra=find(a),rb=find(b);
	ft[ra]=rb;
	}
vector<line>L;
int main(){
	int t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		int n,m,i;
		scanf("%d%d",&n,&m);
		L.clear();ini(n);
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&tp.l,&tp.r,&tp.w);
			L.push_back(tp);
			}
		sort(L.begin(),L.end());
		int res=INF;
		for(i=0;i<L.size();i++){
			int l=L[i].l,r=L[i].r;
			if(find(l)!=find(r))res=min(res,L[i].w),merge(l,r);
			if(find(1)==find(n))break; 
			}
		printf("Scenario #%d:\n",t);
		printf("%d\n\n",res);
		} 
	return 0;
	}

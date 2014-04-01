#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#define MAX 1010
struct edge{
	int p,q;
	double w;
	bool operator < (const edge& b)const {
		return w<b.w;
		}
	};
std::vector<edge>L;
int ft[MAX],rank[MAX],d[MAX];
void in_ft(int n){
	int i;
	for(i=1;i<=n;i++)ft[i]=i,rank[i]=1,d[i]=0;
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
	rank[fr2]+=rank[fr1];
	rank[fr1]=0;
	find(root1);
	find(root2);
	}
double x[MAX],y[MAX];
double dis(int p,int q){
	double xx=x[p]-x[q];
	double yy=y[p]-y[q];
	return sqrt(xx*xx+yy*yy);
	}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		L.clear();
		in_ft(m);
		int i,j;
		for(i=1;i<=m;i++){
			scanf("%lf%lf",&x[i],&y[i]);
			for(j=1;j<i;j++){
				L.push_back( (edge){i,j,dis(i,j)} );
				}
			}
		std::sort(L.begin(),L.end());
		double res;
		int tmd=m;
		for(i=0;i<L.size();i++){
			if( find(L[i].p) != find(L[i].q) ){
				merge(L[i].p,L[i].q);
				d[ find(L[i].p) ]+=L[i].w;
				tmd--;				
				if(tmd==n){
					res=L[i].w;
					break;
					}
				}
			}
		printf("%.2lf\n",res);
	//	if(t)printf("\n");
		}
	return 0;
	}

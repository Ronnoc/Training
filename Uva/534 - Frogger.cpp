#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#define MAX 310
struct edge{
	int p,q;
	double w;
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
	}
double x[MAX],y[MAX];
double dis(int p,int q){
	double xx=x[p]-x[q];
	double yy=y[p]-y[q];
	return sqrt(xx*xx+yy*yy);
	}
int main(){
	int z=0,n;
	while(scanf("%d",&n)!=EOF&&n){
		L.clear();
		in_ft(n);
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%lf%lf",&x[i],&y[i]);
			for(j=1;j<i;j++){
				L.push_back( (edge){j,i,dis(i,j)} );
				}
			}
		std::sort(L.begin(),L.end());
		printf("Scenario #%d\n",++z);
		for(i=0;i<L.size();i++){
			if( find(L[i].p) != find(L[i].q) ){
				merge(L[i].p,L[i].q);
				if(find(1)==find(2)){
					printf("Frog Distance = %.3lf\n",L[i].w);
					break;
					}
				}
			}
		printf("\n");
		}
	return 0;
	}

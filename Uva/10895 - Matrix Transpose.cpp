#include<stdio.h>
#include<vector>
#include<algorithm>
struct point{
	int val,i,j;
	bool operator < (const point &a) const {
        if(j!=a.j)return a.j>j;
        return a.i>i;
		}
	};
std::vector<point>L;
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int i,j;
		L.clear();
		for(i=1;i<=n;i++){
			int a[1010];
			scanf("%d",&a[0]);
			for(j=1;j<=a[0];j++)scanf("%d",&a[j]);
			for(j=1;j<=a[0];j++){
				int temp;
				scanf("%d",&temp);
				L.push_back( (point){temp,i,a[j]} );
				}
			}
		std::sort(L.begin(),L.end());
		L.push_back( (point){-1,-1,-1} );		//из╠Ь 
	//	for(i=0;i<L.size();i++)printf("L(%d,%d)=%d\n",L[i].i,L[i].j,L[i].val); 
		int start=0,end;
		printf("%d %d\n",m,n);
		for(i=1;i<=m;i++){
			for(j=start;j<L.size();j++)if(L[j].j!=i)break;
			printf("%d",j-start);
			end=j;
			for(j=start;j<end;j++)printf(" %d",L[j].i);printf("\n");
			int fi=1;
			for(j=start;j<end;j++){
				if(fi)fi=0;else printf(" ");
				printf("%d",L[j].val);
				}printf("\n");
			start=j;
			}
		}
	return 0;
	}

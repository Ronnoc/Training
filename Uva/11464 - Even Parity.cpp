#include<stdio.h>
#include<algorithm>
#define MOD 1000000007
#define FOR(i,a,b) for(i=(a);i<=(b);++i)
const int N=20;
int map[N][N],now[N][N];
int cho[N];
int n;
int res;
int count(int i,int j){
	int sum=0;
	if(i>=2)sum+=now[i-1][j];
	if(j>=2)sum+=now[i][j-1];
	if(j<n)sum+=now[i][j+1];
	return sum;
}
void output(){
	int i,j;
	FOR(i,1,n){
		FOR(j,1,n)printf("%d",now[i][j]);
		printf("\n");
		}printf("\n");
	}
void DFS(int x){
	int i,j;
	if(x<=n){
		if(map[1][x]){cho[x]=0;DFS(x+1);}
		else {
			FOR(i,0,1){cho[x]=i;DFS(x+1);}
		}
	}
	else {
		int sum=0;
		FOR(i,1,n)sum+=cho[i];
		FOR(i,1,n)FOR(j,1,n)now[i][j]=map[i][j];
		FOR(i,1,n)if(cho[i])now[1][i]=1;
	//	printf("begin\n");output();
		FOR(i,2,n)FOR(j,1,n){
		//	printf("count(%d,%d)=%d\n",i,j,count(i-1,j));
		//	output();
			if(count(i-1,j)%2==0){
				if(now[i][j]){/*printf("(%d,%d)break\n",i,j);output();*/return;}
			}
			else {
				if(!now[i][j]){
				//	printf("(%d,%d)change\n",i,j);output();
					now[i][j]=1;
					sum++;
				}
			//	else printf("(%d,%d)not change\n",i,j);
			}
		}
		FOR(i,1,n)if(count(n,i)%2==1)return;
	//	printf("%d\n",sum);
		res=std::min(sum,res);
	}
}
int main(){
	int k,z;
	scanf("%d",&z);
	FOR(k,1,z){
		scanf("%d",&n);
		int i,j;
		FOR(i,1,n)FOR(j,1,n)scanf("%d",&map[i][j]);
		res=MOD;
		DFS(1);
		printf("Case %d: ",k);
		if(res==MOD)printf("-1\n");
		else printf("%d\n",res);
	}
	return 0;
}

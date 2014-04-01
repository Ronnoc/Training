#include<stdio.h>
int map[10][10];
int t[10][10];
int cho[10];
int flag;
int res;
int m,n;
int ff(char s){
	if(s=='b')return 1;
	return 0;
	}
int min(int a,int b){
	if(a>b)return b;return a;
	}
void f(int x,int y){
	t[x][y]  =1-t[x][y];
	t[x+1][y]=1-t[x+1][y];
	t[x-1][y]=1-t[x-1][y];
	t[x][y+1]=1-t[x][y+1];
	t[x][y-1]=1-t[x][y-1];
	}
void dfs(int x){
	if(x>n){
		int i,j;
//		for(i=1;i<=n;i++)printf("%d ",cho[i]);printf("---cho\n");
		int ans=0;
		int ths=0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)t[i][j]=map[i][j];
		for(i=1;i<=n;i++)if(cho[i])f(i,1),ans++;
		for(j=2;j<m;j++)for(i=1;i<=n;i++)if(t[i][j-1])f(i,j),ans++;
		for(i=1;m>1&&i<=n;i++){
			if(i==1){
				if(t[1][m-1])f(1,m),ans++; 
				}
			else {
				if(t[i][m-1]!=t[i-1][m]){ths=1;break;}
				else {
					if(t[i-1][m])f(i,m),ans++;
					}
				}
			}
		if(!ths&&!t[n][m]){flag=1;res=min(ans,res);}
		ths=0;ans=0;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)t[i][j]=1-map[i][j];
		for(i=1;i<=n;i++)if(cho[i])f(i,1),ans++;
		for(j=2;j<m;j++)for(i=1;i<=n;i++)if(t[i][j-1])f(i,j),ans++;
		for(i=1;m>1&&i<=n;i++){
			if(i==1){
				if(t[1][m-1])f(1,m),ans++; 
				}
			else {
				if(t[i][m-1]!=t[i-1][m]){ths=1;break;}
				else {
					if(t[i-1][m])f(i,m),ans++;
					}
				}
			}
		if(!ths&&!t[n][m]){flag=1;res=min(ans,res);}
		}
	else {
		int i;
		for(i=0;i<=1;i++){
			cho[x]=i;
			dfs(x+1);
			}
		}
	}
int main(){
	m=4;n=4;
	char in_map[10][10];
	int i,j;
	while(scanf("%s",in_map[0])!=EOF){
		for(i=1;i<4;i++)scanf("%s",in_map[i]);
		for(i=0;i<4;i++)for(j=0;j<4;j++)map[i+1][j+1]=ff(in_map[i][j]);
		flag=0;
		res=m*n+1;
		dfs(1);
		if(flag)printf("%d\n",res);
		else printf("Impossible\n");
		}
//	return main();
	return 0;
	}

#include<stdio.h>
const int search_size=1<<12;
int Cg(char x){
	if(x=='+')return 1;
	return 0;
	} 
void next(int &x,int &y){
	if(y<4){y++;return;}
	else {x++;y=1;return;}
	}
int map[6][6],t[6][6];
void change(int x,int y){
	int i;
	for(i=1;i<=4;i++)t[i][y]=1-t[i][y];
	for(i=1;i<=4;i++)t[x][i]=1-t[x][i];
	t[x][y]=1-t[x][y];
	}
int main(){
	char in_map[6][6];
	int i,j,k;
	for(i=0;i<4;i++)scanf("%s",in_map[i]);
	for(i=0;i<4;i++)for(j=0;j<4;j++)map[i+1][j+1]=Cg(in_map[i][j]);
	int res=17,mem=-1;
	for(k=0;k<search_size;k++){
		for(i=1;i<=4;i++)for(j=1;j<=4;j++)t[i][j]=map[i][j];
		int sum=0,tp=k;
		int x=1,y=1;
		for(i=1;i<=12;i++){
		//	if(!tp)break;
			int temp=tp%2;tp/=2;
			if(temp)change(x,y),sum++;
			next(x,y);
			}
		for(i=1;i<=4;i++)if(t[3][i])change(4,i),sum++;
		int flag=1;
		for(i=1;flag&&i<=4;i++)for(j=1;flag&&j<=4;j++)if(t[i][j]){flag=0;break;}
		if(flag){if(sum<res){res=sum;mem=k;}}
		}
	printf("%d\n",res);
	for(i=1;i<=4;i++)for(j=1;j<=4;j++)t[i][j]=map[i][j];
	int x=1,y=1;
	for(i=1;i<=12;i++){
		int temp=mem%2;mem/=2;
		if(temp)change(x,y),printf("%d %d\n",x,y);
		next(x,y);
		}
	for(i=1;i<=4;i++)if(t[3][i])change(4,i),printf("%d %d\n",4,i);
//	return main();
	return 0;
	}

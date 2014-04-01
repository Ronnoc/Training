#include<stdio.h>
#include<stdlib.h>
int dist[90][90];
int f(int x1,int x2){
	if(x1<0)return 0;
	if(x1>7)return 0;
	if(x2<0)return 0;
	if(x2>7)return 0;
	return x1*8+x2+1;
	}
int main(){
	int i,j,k;
	for(i=1;i<=64;i++)for(j=1;j<=64;j++){
		dist[i][j]=999;
		}
	for(i=1;i<=64;i++)dist[i][i]=0;
	for(i=0;i<64;i++){
		int x,y;
		x=i/8,y=i%8;
//		printf("(%d %d)=%d?%d",x,y,f(x,y),i+1);
	//	if(y==7)printf("\n");
		if(f(x-1,y-2)){dist[f(x-1,y-2)][i+1] = 1;dist[i+1][f(x-1,y-2)] = 1;}
		if(f(x-1,y+2)){dist[f(x-1,y+2)][i+1] = 1;dist[i+1][f(x-1,y+2)] = 1;}
		if(f(x+1,y-2)){dist[f(x+1,y-2)][i+1] = 1;dist[i+1][f(x+1,y-2)] = 1;}
		if(f(x+1,y+2)){dist[f(x+1,y+2)][i+1] = 1;dist[i+1][f(x+1,y+2)] = 1;}
		if(f(x-2,y-1)){dist[f(x-2,y-1)][i+1] = 1;dist[i+1][f(x-2,y-1)] = 1;}
		if(f(x-2,y+1)){dist[f(x-2,y+1)][i+1] = 1;dist[i+1][f(x-2,y+1)] = 1;}
		if(f(x+2,y-1)){dist[f(x+2,y-1)][i+1] = 1;dist[i+1][f(x+2,y-1)] = 1;}
		if(f(x+2,y+1)){dist[f(x+2,y+1)][i+1] = 1;dist[i+1][f(x+2,y+1)] = 1;}
		}
	for(k=1;k<=64;k++)for(i=1;i<=64;i++)for(j=1;j<=64;j++){
		if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];
		}
/*	for(i='a';i<='h';i++){
		for(j=1;j<=8;j++)printf("%c%d ",i,j);
		printf("\n"); 
		}
	k=0;
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++)printf("%2d ",++k);
		printf("\n");
		}*/
	char a,b;int x,y;
	while(scanf("%c%d %c%d",&a,&x,&b,&y)!=EOF){
		getchar();
		int p,q;
		p=(a-'a')*8+x;
		q=(b-'a')*8+y;
		printf("To get from %c%d to %c%d takes %d knight moves.\n",a,x,b,y,dist[p][q]);
		}
	return 0;
	}

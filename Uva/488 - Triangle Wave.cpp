#include<stdio.h>
#include<stdlib.h>
void pri(int h){
	int i,j;
	for(i=1;i<h;i++){
		for(j=1;j<=i;j++)printf("%d",i);
		printf("\n");
		}
	for(i=h;i>=1;i--){
		for(j=1;j<=i;j++)printf("%d",i);
		printf("\n");
		}
	}
int main(){
	int n;
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		int h,n,i;
		scanf("%d%d",&h,&n);
		for(i=1;i<=n;i++){
			pri(h);
			if(!(k==z&&n==i))printf("\n");
			}
		}
//	system("pause");
	return 0;
	}

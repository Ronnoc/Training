#include<stdio.h>
#include<stdlib.h>
int dna[20];
int map[50],last[50];
void setfree(){
	int i;
	for(i=0;i<=41;i++)map[i]=0;
	map[20]=1;
	}
char f(int x){
	if(x==0)return ' ';
	if(x==1)return '.';
	if(x==2)return 'x';
	if(x==3)return 'W';
	}
void put(){
	int i;
	for(i=1;i<=40;i++)printf("%c",f(map[i]));
	printf("\n");
	}
int main(){
	int z;
	scanf("%d",&z);
	while(z--){
		int i;
		for(i=0;i<10;i++)scanf("%d",&dna[i]);
		setfree();
		int j;
		for(i=1;i<=50;i++){
			put();
			for(j=0;j<=41;j++)last[j]=map[j];
			for(j=1;j<=40;j++)map[j]=dna[ last[j-1]+last[j]+last[j+1] ];
			}
		if(z!=0)printf("\n");
		}
//	system("pause");
	return 0;
	} 

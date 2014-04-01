#include<stdio.h>
int abs(int x){if(x>0)return x;return -x;}
int choi[10];
int map[10][10];
int res=0;
bool place(int k){
	int i;
	for(i=1;i<k;i++){
		if(choi[i]==choi[k])return 0;
		if(abs(choi[i]-choi[k])==abs(i-k))return 0;
		}
	return 1;
	}
void queen(int t){
	int i;
	if(t>8){
		int sum=0;
		for(i=1;i<=8;i++)sum+=map[choi[i]][i];
		if(sum>res)res=sum;
		}
	else {
		for(i=1;i<=8;i++){
			choi[t]=i;
			if(place(t))queen(t+1);
			}
		}
	}
int main(){
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		res=0;
		int i,j;
		for(i=1;i<=8;i++)for(j=1;j<=8;j++)scanf("%d",&map[i][j]);
		queen(1);
		printf("%5d\n",res);
		}
	return 0;
	}

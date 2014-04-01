#include<stdio.h>
int abs(int x){if(x>0)return x;return -x;}
int choi[10];
int x,y;
int sum=1;
bool place(int k){
	int i;
	for(i=1;i<k;i++){
		if(i==y&&choi[y]!=x)return 0;
		if(choi[i]==choi[k])return 0;
		if(abs(choi[i]-choi[k])==abs(i-k))return 0;
		}
	if(k==y&&choi[y]!=x)return 0;
	return 1;
	}
void queen(int t){
	int i;
	if(t>8){
		printf("%2d     ",sum);
		sum++;
		for(i=1;i<=8;i++)printf(" %d",choi[i]);
		printf("\n");
		}
	else {
		for(i=1;i<=8;i++){
			choi[t]=i;
			if(place(t))queen(t+1);
			}
		}
	}
int main(){
//	freopen("out.txt","w",stdout);
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		sum=1;
		scanf("%d%d",&x,&y);
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		queen(1);
		if(k!=z)printf("\n");
		}
	return 0;
	}

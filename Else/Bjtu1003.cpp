#include<stdio.h>
#include<string.h>
#define MID 10000
void print(int *o){
	int fuhao=1;
	int l=2*MID+1,r=0,i;
	for(i=l;i>=r;i--)if(o[i]!=0){
		if(o[i]<0)fuhao=-1;
		break;
		}
	if(fuhao==-1){
		printf("-");
		for(i=l;i>=r;i--)o[i]=-o[i];
		}
	for(i=0;i<2*MID;i++){
		if(o[i]<0){
			o[i]+=10;
			o[i+1]-=1;
			}
		if(o[i]>9){
			o[i]-=10;
			o[i+1]++;
			}
		}
	for(;l>=MID;l--)if(o[l]!=0)break;
	for(;r<MID;r++)if(o[r]!=0)break;
	for(i=l;i>=MID;i--)printf("%d",o[i]);
	if(l==MID-1&&r==MID)printf("0");
	if(r!=MID)printf(".");
	for(i=MID-1;i>=r;i--)printf("%d",o[i]);
	printf("\n");
	}
int tsf(char x,int k){
	if(x=='-')return 0;
	int res=x-'0';
	return res*k;
	}
void f(char *a,int *x){
	int len=strlen(a);
	int i,j;
	for(i=0;i<=2*MID+1;i++)x[i]=0;
	int p=len;
	int k=1;
	if(a[0]=='-')k=-1;
	for(i=0;i<len;i++){
		if(a[i]=='.')p=i;
		}
	int px=MID;
	for(i=p-1;i>=0;i--)x[px++]=tsf(a[i],k);
	px=MID-1;
	for(i=p+1;i<len;i++)x[px--]=tsf(a[i],k);
//	print(x);
	}
void plus(int *x,int *y,int *o){
	int i;
	for(i=0;i<=2*MID;i++){
		o[i]=x[i]+y[i];
		}
	print(o);
	}
int main(){
	char a[20020];
	int x[20020];
	char b[20020];
	int y[20020];
	int o[20020];
	while(scanf("%s%s",a,b)!=EOF){
		int i;
		f(a,x);
		f(b,y);
		plus(x,y,o);
		}
	return 0;
	}

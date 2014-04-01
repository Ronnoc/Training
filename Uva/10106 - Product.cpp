#include<stdio.h>
#include<string.h>
#define ENTER printf("\n")
char a[1010],b[1010];
int x[1010],o[1010],y[1010];
int lena,lenb;
int main(){
	while(scanf("%s%s",a,b)!=EOF){
		lena=strlen(a);
		lenb=strlen(b);
		int i,j;
		for(i=0;i<lena;i++)x[lena-i]=a[i]-'0';
		for(i=0;i<lenb;i++)y[lenb-i]=b[i]-'0';
	//	for(i=1;i<=lena;i++)printf("%d",x[i]);ENTER;
	//	for(i=1;i<=lenb;i++)printf("%d",y[i]);ENTER;
		for(i=1;i<=1000;i++)o[i]=0;
		for(i=1;i<=lena;i++){
			for(j=1;j<=lenb;j++)o[i+j-1]+=x[i]*y[j];
			}
		int max=1;
		for(i=1;i<1000;i++){
			o[i+1]+=o[i]/10;
			o[i]%=10;
			if(o[i]!=0)max=i;
			}
		for(i=max;i>=1;i--)printf("%d",o[i]);ENTER;
		}
	return 0;
	}

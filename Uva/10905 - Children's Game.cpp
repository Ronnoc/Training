#include<stdio.h>
#include<string.h>
char a[60][5010];
char x[10020],y[10020];
char t[5010];
int cmp(char *a,char *b){
	int len=strlen(a),i;
	for(i=0;i<len;i++){
	//	printf("%d:a[]=%c,b[]=%c,a[]-b[]=%c\n",i,a[i],b[i],a[i]-b[i]);
		if(a[i]!=b[i])return (int)a[i]-(int)b[i];
	//	printf("%d ",i);
		}
	return 0;
	}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int i;
		for(i=1;i<=n;i++)scanf("%s",a[i]);
		int j;
		for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
			sprintf(x,"%s%s",a[i],a[j]);
			sprintf(y,"%s%s",a[j],a[i]);
		//	puts(x);puts(y);
		//	printf("cmp(%d,%d)=%d\n",i,j,cmp(x,y));
			if(cmp(x,y)<0){
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
				}
			}
		for(i=1;i<=n;i++)printf("%s",a[i]);
		printf("\n");
		}
	return 0;
	}

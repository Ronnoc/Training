#include<stdio.h>
#include<string.h>
#define ENTER printf("\n")
#define SMAX 5010
char Fib[5010][5010];
int x[SMAX],y[SMAX],s[SMAX];
void plus(char *a,char *b,char *o)                                                      
{
 	int lena,lenb;
	lena=strlen(a);
	lenb=strlen(b);
	int i,j;
	memset(s,0,sizeof(s));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(i=0;i<lena;i++)x[lena-i]=a[i]-'0';
	for(i=0;i<lenb;i++)y[lenb-i]=b[i]-'0';
//	for(i=1;i<=lena;i++)printf("%d",x[i]);ENTER;
//	for(i=1;i<=lenb;i++)printf("%d",y[i]);ENTER;
	for(i=1;i<SMAX;i++){
		s[i]=x[i]+y[i];
		}
	int max=1;
	for(i=1;i<SMAX;i++){
		s[i+1]+=s[i]/10;
		s[i]%=10;
		if(s[i]!=0)max=i;
		}
	j=0;
	for(i=max;i>=1;i--)o[j++]=s[i]+'0';o[j]='\0';
//	puts(o);
	}
int main(){
	memset(Fib,'\0',sizeof(Fib));
	sprintf(Fib[0],"0");
	sprintf(Fib[1],"1");
	int i;
	for(i=2;i<=5000;i++)plus(Fib[i-2],Fib[i-1],Fib[i]);
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("The Fibonacci number for %d is ",n);
		puts(Fib[n]);
		}
	return 0;
	} 

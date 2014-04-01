#include<stdio.h>
#include<string.h>
#define ENTER printf("\n")
#define SMAX 100000
char a[SMAX],b[SMAX],o[SMAX];
int x[SMAX],y[SMAX],s[SMAX];
/*
2147483647 * 1
2147483647 + 1
0 * 1000000000000
2147483648 * 0
2000000000 + 2000000000
1000000 * 1000000
0 * 0
0 + 0
2147483647 * 2147483647
2147483647 + 2147483647
0000000000000000350 + 20
    350 +      20
   0000350     +    00020
   测试数据真有前导0...... 
   */
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
void ex(char *a,char *bs,char *o){
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
		for(i=1;i<SMAX;i++)s[i]=0;
		for(i=1;i<=lena;i++){
			for(j=1;j<=lenb;j++)s[i+j-1]+=x[i]*y[j];
			}
		int max=1;
		for(i=1;i<SMAX;i++){
			s[i+1]+=s[i]/10;
			s[i]%=10;
			if(s[i]!=0)max=i;
			}
		j=0;
	for(i=max;i>=1;i--)o[j++]=s[i]+'0';o[j]='\0';
	}
char cmp[]="2147483647";
bool check(char *s){
	int max=strlen(s),i,temp=0;
	for(i=0;i<max;i++)if(s[i]=='0'){temp++;}else break;
	max-=temp;
//	printf("%dcheck %s:%s\n",max,s,cmp);
	if(max>10)return 1;
	if(max<10)return 0;
	for(i=0;i<=9;i++){
		int x=s[i]-cmp[i];
	//	printf("%c-%c=%d\n",s[i],cmp[i],x);
		if(x>0)return 1;
		if(x<0)return 0;
		}
	return 0;
	}
int main(){
	char c;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(o,0,sizeof(o));
	while(scanf("%s %c %s",a,&c,b)!=EOF){
		printf("%s %c %s\n",a,c,b);
		if(check(a))printf("first number too big\n");
		if(check(b))printf("second number too big\n");
		if(c=='+'){
			plus(a,b,o);
			if(check(o))printf("result too big\n");
			}
		else {
			ex(a,b,o);
			if(check(o))printf("result too big\n");
			}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(o,0,sizeof(o));
		}
	return 0;
	}

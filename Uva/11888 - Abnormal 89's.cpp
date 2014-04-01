#include<stdio.h>
#include<string.h>
char in_s[200010];
char s[400010];
int p[400010];
int ok[400010];
int min(int a,int b){
	if(a>b)return b;
	return a;
	}
int Manacher(char *s){
	int len=strlen(s);
	int i;
	int mx=1,id=1;
	int flag=0;
	for(i=0;i<len;i++)ok[i]=0;
	for(i=1;i<len;i++){
		if(mx>i)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while(s[i+p[i]]==s[i-p[i]])p[i]++;
		if(i+p[i]>mx){
			id=i;
			mx=i+p[i];
			}
		if(i-p[i]==0)ok[i+p[i]-1]=1;
		if(i+p[i]==len&&ok[i+1-p[i]]&&i+1!=len&&i!=p[i])flag=1;
		}
	int res=0;
	for(i=1;i<len;i++)if(p[i]>res)res=p[i];
	
//	for(i=0;i<len;i++)printf(" %d",i);printf("\n");
//	for(i=0;i<len;i++)printf(" %c",s[i]);printf("\n");
//	for(i=0;i<len;i++)printf(" %d",p[i]);printf("\n");
//	for(i=0;i<len;i++)printf(" %d",ok[i]);printf("\n");
	
	res--;
	if(flag)return 10;
	if(2*res+2==len)return 20;
	return 0;
	}
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%s",in_s);
		int len=strlen(in_s);
		s[0]='$';
		for(i=0;i<=len;i++){
			s[2*i+2]=in_s[i];
			s[2*i+1]='#';
			}
		int res=Manacher(s);
		     if(res==10)printf("alindrome");
		else if(res==20)printf("palindrome");
		else printf("simple");
		printf("\n");
		}
	return 0;
	}

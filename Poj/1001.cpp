#include <stdio.h>
#include <string.h>
struct BI{
	int s[250];
	int len,pnt;
	BI() {memset(s,0,sizeof(s));len=1;pnt=0;}
	BI operator * (const BI &tp)const{
		BI res;
		res.pnt=pnt+tp.pnt;
		int i,j;
		for(i=1;i<=len+tp.len;i++){
			for(j=1;j<=len;j++){
				if(i-j<=tp.len&&i-j>=1)res.s[i-1]+=tp.s[i-j]*s[j];
				}
			}
		i=1;
		while(i<=len+tp.len){
			int x=res.s[i];
			res.s[i]%=10;
			res.s[i+1]+=x/10;
			i++;
			}
		while(res.s[i]>9){
			int x=res.s[i];
			res.s[i]%=10;
			res.s[i+1]+=x/10;
			i++;
			}
		res.len=i;
		return res;
		} 
	};
int main(){
	char s[10];
	int n,i;
	while(scanf("%s%d",s,&n)!=EOF){
		//printf("%s %d\n",s,n);
		BI res;res.s[1]=1;
		BI a;
		int point=0;
		for(i=0;i<strlen(s);i++)if(s[i]=='.')point=1;
		if(point)for(i=strlen(s)-1;i>=1;i--)
			if(s[i]=='0')s[i]='\0';
			else break;
		int len=strlen(s);
		int p=0;
		for(i=len-1;i>=0;i--){
			if(s[i]!='.')a.s[++p]=s[i]-'0';
			else a.pnt=len-1-i;
			}
		a.len=len;
		for(i=1;i<=n;i++)res=a*res;
		int flag=0;
		int out=1;
		for(i=res.len;i>=1;i--){
			if(i==res.pnt){
				printf(".");
				flag=1;
				}
			if(!flag){
				if(!res.s[i])continue;
				else flag=1;
				}
			printf("%d",res.s[i]);
			out=0;
			}
		if(out)printf("0");
		printf("\n");
		}
	return 0;
	}

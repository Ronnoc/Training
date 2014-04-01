#include <cstdio>
#include<cstring>
int ak[210],ff[210],f[210],now[210],temp[210],n;
int main(){
	while(scanf("%d",&n)!=EOF){
		int i;
		for(i=1;i<=n;i++)ak[i]=i;
		for(i=1;i<=n;i++)scanf("%d",&ff[i]);
		memcpy(f[1],ff,sizeof(ff));
		for(i=2;i<=32;i++){
			memcpy(now,f[i-1],sizeof(f[i-1]));
			fun(now,f[i-1]);
			memcpy(f[i],now,sizeof(now));
		}
		int k;
		while(~scanf("%d",&k)&&k){
			char s[210];
			gets(s);
			int len=strlen(s);
			for(i=len;i>=1;i--)s[i]=s[i-1];
			while(k){
				if(k&1)fun()
				memcpy(f,)
			}
		}
	}
	return 0;
}

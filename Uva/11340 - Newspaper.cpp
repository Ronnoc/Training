#include<stdio.h>
#include<string.h>
long long va[900];
int main(){
	int t;
	scanf("%d%*c",&t);
	while(t--){
		int m,n,i;
		scanf("%d%*c",&m);
		char s[20010];
		for(i=0;i<=800;i++)va[i]=0;
		for(i=1;i<=m;i++){
			gets(s);
			char p;
			long long q;
			sscanf(s,"%c %lld",&p,&q);
			va[(int)p+200]=q; 
			}
		scanf("%d%*c",&n);
		long long res=0;
		for(i=1;i<=n;i++){
			gets(s);
			int j;
			int len=strlen(s);
			for(j=0;j<len;j++){
				res+=va[(int)s[j]+200];
				}
			} 
		printf("%lld.%02lld$\n",res/100,res%100);
		}
//	return main(); 
	return 0;
	}

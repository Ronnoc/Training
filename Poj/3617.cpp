#include <cstdio>
#include <cstring>
char sl[2010];
char sr[2010];
char s[10];
char ans[2010];
char *r,*l;
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int n;
	for(;~scanf("%d%*c",&n);){
		int i;
		for(i=0;i<n;i++){
			gets(s);
			sl[i]=s[0];
			sr[n-1-i]=s[0];
		}
		sl[n]=sr[n]='\0';
		l=&sl[0],r=&sr[0];
		for(i=0;i<n;i++){
			if(strcmp(l,r)<=0){
				ans[i]=*l;
				l++;
				int len=strlen(r);
				r[len-1]='\0';
			}
			else {
				ans[i]=*r;
				r++;
				int len=strlen(l);
				l[len-1]='\0';
			}
		}
		ans[n]='\0';
		for(i=0;i<n;i++){
			printf("%c",ans[i]);
			if((i+1)%80==0)printf("\n");
		}
		printf("\n");
	}
return 0;}

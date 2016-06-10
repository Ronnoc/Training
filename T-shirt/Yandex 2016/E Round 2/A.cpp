#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
int main(){
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int w[33],g[33];
		memset(w,-1,sizeof w);
		memset(g,0,sizeof g);
		char s[105];
		scanf("%s",s);
		for(i=0;s[i];i++)g[s[i]-'a']++;
		for(i=0;i<m;i++){
			int p,q;
			scanf("%d%d",&p,&q);
			scanf("%s",s);
			for(j=0;s[j];j++){
				char c=s[j];
				if(~w[c-'a'])cmin(w[c-'a'],q);
				else w[c-'a']=q;
			}
		}
		int fail=0;
		int ans=0;
		for(i=0;i<26;i++)if(g[i]){
			if(~w[i])ans+=w[i]*g[i];
			else fail=1;
		}
		if(fail)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
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
char s[55];
char G[111][55];
void solve(){
	int N,L;
	scanf("%d%d",&N,&L);
	int i,j;
	int fail=0;
	for(i=0;i<N;i++){
		scanf("%s",G[i]);
	}
	scanf("%s",s);
	for(i=0;i<N;i++)if(strcmp(G[i],s)==0){
		fail=1;
	}
	if(fail){
		printf("IMPOSSIBLE\n");
		return;
	}
	for(i=0;i<L;i++)printf("%c?",1-(s[i]-'0')+'0');
		printf(" ");
	int id=0;
	for(i=0;i<L;i++){
		printf("%c",1-(s[i]-'0')+'0');
		if(i+1!=L)printf("%c", s[i]);
	}
	printf("\n");
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d: ",CA);
		solve();
	}
	return 0;
}
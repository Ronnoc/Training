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
char s[200005];
void solve(){
	scanf("%s",s);
	int len=strlen(s);
	stack<char>S;
	int i;
	int ans=0;
	for(i=0;i<len;i++){
		if(S.empty())S.push(s[i]);
		else {
			char c=S.top();S.pop();
			if(c==s[i])ans+=10;
			else {
				S.push(c);
				S.push(s[i]);
			}
		}
	}
	printf("%d\n",S.SZ/2*5+ans);
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
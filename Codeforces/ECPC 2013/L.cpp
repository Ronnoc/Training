#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define BB second
#define AA first
#define SZ size()
typedef pair<int,int> PII;
typedef long long LL;
const double PI = acos(-1.);
const double eps = 1e-8;
int main(){
	freopen("mahdi.in","r",stdin);
	int i,j,T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		printf("Case %d:\n",CA);
		char s[1111];
		int len,mu,ad;
		scanf("%s%d%d%d",s,&len,&mu,&ad);
		s[0]=tolower(s[0]);
		int mem[33][33];
		memset(mem,-1,sizeof mem);
		mem[s[0]-'a'][0]=0;
		for(i=1;;i++){
			s[i]=((s[i-1]-'a')*mu+i*ad)%26+'a';
			if(~mem[s[i]-'a'][i%26]){
				s[i]='\0';
				break;
			}
			mem[s[i]-'a'][i%26]=i;
		}
		int turn=strlen(s);
		int next[1111][33];
		memset(next,-1,sizeof next);
		for(i=0;i<turn;i++)for(j=0;j<turn;j++){
			int &tp=next[i][s[j]-'a'];
			int f=j;
			if(f<i)f+=turn;
			if(tp==-1)tp=f-i;
			else tp=min(tp,f-i);
		}
		int n;
		scanf("%d",&n);
		while(n--){
			char c[105];
			int l,m,a;
			scanf("%s%d%d%d",c,&l,&m,&a);
			c[0]=tolower(c[0]);
			for(i=1;i<l;i++)
				c[i]=((c[i-1]-'a')*m+i*a)%26+'a';
			c[l]='\0';
//			cout<<c<<endl;
			int fail=0,w=0;
			for(i=0;i<l;i++){
//				cout<<w<<"~>";
				if(next[w%turn][c[i]-'a']==-1){fail=1;break;}
				else w+=next[w%turn][c[i]-'a']+1;
			}
			if(w>len||fail)printf("REPEAT\n");
			else printf("BRAVO\n");
		}
	}
	return 0;
}

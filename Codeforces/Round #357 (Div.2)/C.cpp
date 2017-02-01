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
char s[1111];
int main(){
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		multiset<int>S;
		vector<pair<char,int> >L;
		while(n--){
			scanf("%s",s);
			int x;
			if(s[0]=='i'){
				scanf("%d",&x);
				S.insert(x);
				L.PB(MP('i',x));
			}else if(s[0]=='g'){
				scanf("%d",&x);
				while(!S.empty()){
					int u=*S.OP;
					if(u<x){
						S.erase(S.OP);
						L.PB(MP('r',-1));
					}else break;
				}
				if(S.empty()){
					L.PB(MP('i',x));
					S.insert(x);
				}else {
					int u=*S.OP;
					if(u>x){
						L.PB(MP('i',x));
						S.insert(x);
					}
				}
				L.PB(MP('g',x));
			}else {//remove
				if(S.empty()){
					L.PB(MP('i',1));
					S.insert(1);
				}
				S.erase(S.OP);
				L.PB(MP('r',-1));
			}
		}
		printf("%d\n",L.SZ);
		for(auto x:L){
			if(x.AA=='i')printf("insert %d\n",x.BB);
			if(x.AA=='g')printf("getMin %d\n",x.BB);
			if(x.AA=='r')printf("removeMin\n");
		}
	}
	return 0;
}
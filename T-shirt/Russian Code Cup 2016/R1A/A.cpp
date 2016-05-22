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
	scanf("%d",&_T);
	while(_T--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b==c){
			if(b==0){
				if(a&&d){
					printf("impossible\n");
				}else if(a){
					for(i=0;i<=a;i++)putchar('0');
						putchar('\n');
				}else if(d){
					for(i=0;i<=d;i++)putchar('1');
						putchar('\n');
				}
			}else {
				for(i=0;i<=a;i++)putchar('0');
				for(i=0;i<=d;i++)putchar('1');
				putchar('0');
				for(i=1;i<b;i++){
					putchar('1');
					putchar('0');
				}
						putchar('\n');
			}
		}else if(b==c+1){
			for(i=0;i<a;i++)putchar('0');
				for(i=1;i<=b;i++){
					putchar('0');
					putchar('1');
				}
			for(i=0;i<d;i++)putchar('1');
						putchar('\n');
		}else if(c==b+1){
			for(i=0;i<d;i++)putchar('1');
				for(i=1;i<=c;i++){
					putchar('1');
					putchar('0');
				}
			for(i=0;i<a;i++)putchar('0');
						putchar('\n');
		}else printf("impossible\n");
	}
	return 0;
}
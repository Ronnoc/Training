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

int MA[2000005];
int main(){
    int i,j,k,_T;
    int n,x,y;
    while(~scanf("%d%d%d",&n,&x,&y)){
        LL g=__gcd(x,y);
        LL tu=1LL*x/g*y;
        LL per=tu/x+tu/y;
        LL tot=per-1;
        LL tx=tu/x,ty=tu/y;
        int cnt=-1;
        while(tx!=ty){
            while(tx<ty){
                cnt++;
                MA[cnt]=2;
                tx+=tu/x;
            }
            while(ty<tx){
                cnt++;
                MA[cnt]=1;
                ty+=tu/y;
            }
        }
        MA[++cnt]=0;
        MA[++cnt]=0;
        while(n--){
            int a;
            scanf("%d",&a);
            tot=a-1;
            tot%=per;
            if(MA[tot]==0)printf("Both\n");
            else printf("%s\n",MA[tot]==2?"Vanya":"Vova");
        }
    }
    return 0;
}


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
#define NAME ""
#define VER 1

int n,a[100005];
LL S[100005];
LL F[100005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        reverse(a+1,a+1+n);
        memset(F,0,sizeof F);
        S[0]=0;
        for(i=1;i<=n;i++)S[i]=S[i-1]+a[i];
        for(k=1;k<=100000;k++){
            int id=0,mul=0;
            LL len=1;
            while(id<n){
                F[k]+=(S[min(id+len,1LL*n)]-S[id])*mul;
                mul++;
                id=min(id+len,1LL*n);
                len*=k;
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--){
            scanf("%d",&k);
            cout<<F[k]<<"\n";
        }
    }
    return 0;
}


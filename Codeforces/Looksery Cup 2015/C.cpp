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
#define UsingFile 0

int f(int p,int q,int r,int s){
    if(r==0)return (p&1)==s;
    if(p){if(f(p-1,q,r-1,s^1));else return 1;}
    if(q){if(f(p,q-1,r-1,s^1));else return 1;}
    return 0;
}
int g(int p,int q,int r,int s){
    int flag;
    if(r==0||p==0||q==0)flag=f(p,q,r,1);
    else {
        if(p<q){
            if(r%2==1&&r<=2*p-1)flag=1;
            else flag=0;
        }else if(p>q){
            if(r<=2*q-1)flag=r&1;
            else flag=(p+q-r)&1;
        }else flag=r&1;
    }
    return flag;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,_T;
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        int p=0,q=0;
        for(i=0;i<n;i++){
            int w;
            scanf("%d",&w);
            if(w&1)p++;else q++;
        }
        int r=n-k;
        int flag=g(p,q,r,1);
        if(!flag)puts("Daenerys");
        else puts("Stannis");
    }
    return 0;
}


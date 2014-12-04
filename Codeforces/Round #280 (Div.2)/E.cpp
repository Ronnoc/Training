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
LL extGcd (LL a, LL b, LL &x, LL &y) {
    LL ret = a;
    if (b) {
        ret = extGcd (b, a % b, y, x);
        y -= (a / b) * x;
    } else x = 1, y = 0;
    return ret;
}
LL modInv (LL a, LL m) {
    LL x, y;
    extGcd(a,m,x,y);
    return (m+x%m)%m;
}
int main(){
    int i,j,k,_T;
    int n,m,dx,dy;
    while(~scanf("%d%d%d%d",&n,&m,&dx,&dy)){
        int iy=modInv(dy,n);
        map<LL,int>MA;
        for(i=0;i<m;i++){
            int p,q;
            scanf("%d%d",&p,&q);
            LL k=1LL*dx*iy%n;
            LL b=((p-k*q%n)%n+n)%n;
            MA[b]++;
        }
        vector<pair<LL,int> >L(MA.OP,MA.ED);
        int z=0;
        int cnt=0;
        for(i=0;i<L.SZ;i++)
            if(L[i].BB>cnt)cnt=L[i].BB,z=L[i].AA%n;
        printf("%d 0\n",z);
    }
    return 0;
}


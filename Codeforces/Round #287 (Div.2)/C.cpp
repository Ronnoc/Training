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
LL f[11][23][1<<11|1];	//initial with -1
int dig[23],ndig;		//ndig=max{i}:dig[i]!=0
int isTarget(int mask,int first,int aim){
    return __builtin_popcount(mask)==aim;
}
int vary(int mask,int a){
    for(int i=a;i<10;i++)if(mask>>i&1)
        return mask^(1<<i)^(1<<a);
    return mask^(1<<a);
}
LL dfs(int id,int mask,int aim,int even=1,int first=1){	//dfs(ndig,startMask,aim)
    if(id==-1)return isTarget(mask,first,aim);
    if(!even&&~f[aim][id][mask])return f[aim][id][mask];
    LL ret=0;
    if(even)ret+=dfs(id-1,vary(mask,dig[id]),aim,1,0);
    if(first)ret+=dfs(id-1,mask,aim,0,1);
    int u=even?dig[id]-1:9;
    for(int i=first?1:0;i<=u;i++)
        ret+=dfs(id-1,vary(mask,i),aim,0,0);
    return even?ret:f[aim][id][mask]=ret;
}
LL solve(LL re,int aim){
    ndig=0;
    while(re){dig[ndig++]=re%10;re/=10;}
    return dfs(--ndig,0,aim);
}
int main(){
    int i,j,k,_T;
    int q,w,e,r,t;
    while(~scanf("%d%d%d%d%d",&q,&w,&e,&r,&t)){
        double dx=w-r;
        double dy=e-t;
        double d=sqrt(dx*dx+dy*dy);
        int cnt=0;
        while(d>1e-8)d-=2*q,cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}


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
LL f[11][11][11];	//initial with -1
int dig[23],ndig;		//ndig=max{i}:dig[i]!=0
int isTarget(int mask,int first,int aim){
    return mask==aim;
}
int vary(int mask,int a){
    return mask+(a==4||a==7);
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
LL tot[11];
const LL MOD = 1000000007;
LL DFS(int id,int sum){
    LL ret=0;
    if(sum>9)return 0;
    int i;
    if(id==6){
        LL tong=0;
        for(i=sum+1;i<=9;i++)
            tong+=tot[i];
        return tong%MOD;
    }
    for(i=0;i<=9;i++)if(tot[i]){
        tot[i]--;
        ret+=DFS(id+1,sum+i)*(tot[i]+1)%MOD;
        tot[i]++;
    }
    return ret%MOD;
}
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    memset(f,-1,sizeof f);
    int m;
    while(cin>>m){
        for(i=0;i<=9;i++)
            tot[i]=solve(m,i);
        tot[0]--;
        LL ANS=DFS(0,0);
        cout<<ANS<<"\n";
    }
    return 0;
}


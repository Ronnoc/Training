#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
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
int x[30005];
vector<PII>G[305];
int p[30005],q[30005];
const LL MOD = 1000000007;
LL inv[30005];
int CT[30005];
int main(){
    int i,j,k,_T;
    for(inv[0]=inv[1]=1,i=2;i<=30000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    scanf("%d",&_T);
    while(_T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int mx=0;
        for(i=1;i<=n;i++)scanf("%d",&x[i]),cmax(mx,x[i]);
        for(i=0;i<m;i++)scanf("%d%d",&p[i],&q[i]);
        for(i=1;i<=mx;i++)CT[i]=0;
        int ss=sqrt(n);
        while(ss*ss<=n)ss++;//0~ss-1
        for(i=0;i<ss;i++)G[i].clear();
        for(i=0;i<m;i++)
            G[q[i]/ss].PB(MP(p[i],q[i]));
        vector<PII>L;
        for(i=0;i<ss;i++){
            sort(G[i].OP,G[i].ED);
            G[i].erase(unique(G[i].OP,G[i].ED),G[i].ED);
            for(j=0;j<G[i].SZ;j++)
                L.PB(G[i][j]);
        }
        map<PII,LL>Ans;
        int le=1,re=0;
        LL tmp=1;
        int cnt=0;
        for(i=0;i<L.SZ;i++){
            int l=L[i].AA,r=L[i].BB;
            while(re<r){
                re++,cnt++;
                LL v=CT[x[re]];
                CT[x[re]]++;
                tmp=tmp*cnt%MOD*inv[v+1]%MOD;
            }
            while(re>r){
                tmp=tmp*CT[x[re]]%MOD;
                CT[x[re]]--;
                tmp=tmp*inv[cnt]%MOD;
                re--,cnt--;
            }
            while(le<l){
                tmp=tmp*CT[x[le]]%MOD;
                CT[x[le]]--;
                tmp=tmp*inv[cnt]%MOD;
                le++,cnt--;
            }
            while(le>l){
                le--,cnt++;
                LL v=++CT[x[le]];
                tmp=tmp*cnt%MOD*inv[v]%MOD;
            }
            Ans[MP(l,r)]=tmp;
        }
        for(i=0;i<m;i++)
            printf("%I64d\n",Ans[MP(p[i],q[i])]);
    }
    return 0;
}


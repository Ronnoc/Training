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
const LL MOD = 1000000007;
char s[100005];
LL inv[100005];
LL comb(int n,int m){
    if(m<0||m>n)return 0;
    if(n==m||m==0)return 1;
    return comb(n,m-1)*(n-m+1)%MOD*inv[m]%MOD;
}
LL mpow(LL x,LL n){
    LL ret=1;
    while(n){
        if(n&1)ret=ret*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ret%MOD;
}
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    for(inv[1]=1,i=2;i<=100000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    int n;
    while(~scanf("%d%s",&n,s)){
        map<char,int>Z;
        int len=strlen(s);
        for(i=0;i<len;i++)Z[s[i]]++;
        vector<pair<char,int> >R(Z.OP,Z.ED);
        vector<int>L;
        for(i=0;i<R.SZ;i++)L.PB(R[i].BB);
        map<int,int>X;
        for(i=0;i<L.SZ;i++)X[L[i]]++;
        map<int,int>::iterator it=--X.ED;
            int p=(*it).AA;
            int q=(*it).BB;
            LL tot=mpow(q,n);
        cout<<tot%MOD<<"\n";
    }
    return 0;
}


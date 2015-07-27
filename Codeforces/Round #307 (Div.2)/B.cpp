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

int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    string a,b,c;
    while(cin>>a>>b>>c){
        int A[33],B[33],C[33];
        memset(A,0,sizeof A);
        memset(B,0,sizeof B);
        memset(C,0,sizeof C);
        for(i=0;i<a.SZ;i++)A[a[i]-'a']++;
        for(i=0;i<b.SZ;i++)B[b[i]-'a']++;
        for(i=0;i<c.SZ;i++)C[c[i]-'a']++;
        vector<PII >L;
        for(int p=0;;p++){
            int ok=1;
            for(i=0;i<26;i++)if(A[i]<B[i]*p)ok=0;
            if(!ok)break;
            for(i=0;i<26;i++)A[i]-=B[i]*p;
            int mx=1000000;
            for(i=0;i<26;i++)if(C[i])cmin(mx,A[i]/C[i]);
            for(i=0;i<26;i++)A[i]+=B[i]*p;
            L.PB(MP(-(mx+p),p));
        }
        sort(L.OP,L.ED);
        int p=L[0].BB;
        int q=-L[0].AA-p;
        for(i=0;i<26;i++)A[i]-=p*B[i]+q*C[i];
        while(p--)cout<<b;
        while(q--)cout<<c;
        for(i=0;i<26;i++)while(A[i]--)cout<<char('a'+i);
        cout<<"\n";
    }
    return 0;
}


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
const int MXN = 200005+10;
int a[200005];
int b[200005];
int c[200005];
int qa[200005];
int qb[200005];
int qm[200005];
int qc[200005];
inline int LB(int x){return x&(-x);}
struct BIT{
    LL _[MXN];
    int n;
    void init(int m){
        n=m+5;
        for(int i=0;i<=n;i++)_[i]=0;
    }
    LL query(int w){
        LL ret=0;
        for(w+=3;w>0;w-=LB(w))ret+=_[w];
        return ret;
    }
    void update(int w,LL d){
        for(w+=3;w<n;w+=LB(w))_[w]+=d;
    }
    int find_Kth(int k){		//UESTC_Dagon
        int idx=0;
        for(int i=20;i>=0;i--){
            idx|=1<<i;
            if(idx<=n&&_[idx]<k)k-=_[idx];
            else idx^=1<<i;
        }
        return idx-2;
    }
}Y;
int main(){
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<n;i++)scanf("%d",&b[i]);
        memset(qc,0,sizeof qc);
        for(i=0;i<n;i++)qm[i]=n-i;
        Y.init(n+5);
        for(i=0;i<n;i++)Y.update(a[i],1);
        for(i=0;i<n;i++){
            Y.update(a[i],-1);
            qa[i]=Y.query(a[i]);
        }
        Y.init(n+5);
        for(i=0;i<n;i++)Y.update(b[i],1);
        for(i=0;i<n;i++){
            Y.update(b[i],-1);
            qb[i]=Y.query(b[i]);
        }
        Y.init(n+5);
        for(i=n-1;i>=0;i--){
            qc[i]+=qa[i]+qb[i];
            while(qc[i]>=qm[i]){
                qc[i]-=qm[i];
                if(i)qc[i-1]++;
            }
        }
        Y.init(n+5);
        for(i=0;i<n;i++)Y.update(i,1);
        for(i=0;i<n;i++){
            c[i]=Y.find_Kth(qc[i]+1);
            Y.update(c[i],-1);
        }
        for(i=0;i<n;i++)printf("%s%d",i?" ":"",c[i]);
        printf("\n");
    }
    return 0;
}


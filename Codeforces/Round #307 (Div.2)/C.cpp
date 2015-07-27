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

int n,m;
int A[100005];
int C[100005];
LL sum[100005];
bool check(LL t){
    int i;
    int next=1;
    for(i=1;i<=n;i++)C[i]=A[i];
    for(i=1;i<=m;i++){
        LL rem=t;
        int id=0;
        while(1){
            while(next<=n&&C[next]==0)next++;
            if(next>n)return 1;
            if(next>id){
                rem-=next-id;
                if(rem<0)break;
                id=next;
            }
            if(rem>=C[next]){
                rem-=C[next];
                C[next]=0;
                next++;
            }else {
                C[next]-=rem;
                break;
            }
        }
    }
    return 0;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++){
            scanf("%d",&C[i]);
            A[i]=C[i];
        }
        sum[0]=0;
        for(i=1;i<=n;i++)sum[i]=sum[i-1]+C[i];
        LL le=0,re=1LL<<60,ge=-1;
        while(le!=re){
            if(re-le<=1){
                if(check(le))ge=le;
                else ge=re;
                break;
            }
            LL mid=(le+re)>>1;
            if(check(mid))re=mid;
            else le=mid;
        }
        cout<<ge<<"\n";
    }
    return 0;
}


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

int a[100005];
int b[100005];
int main(){
    int i,j,k,_T;
    int n,r,avg;
    while(~scanf("%d%d%d",&n,&r,&avg)){
        for(i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
        LL all=1LL*avg*n;
        LL now=0;
        for(i=0;i<n;i++)now+=a[i];
        priority_queue<PII>Q;
        for(i=0;i<n;i++)if(a[i]<r)
            Q.push(MP(-b[i],r-a[i]));
        LL ans=0;
        while(now<all){
            PII top=Q.top();
            Q.pop();
            int per=-top.AA;
            int cnt=top.BB;
            if(cnt+now>=all){
                cnt=all-now;
                ans+=1LL*per*cnt;
                now+=cnt;
                break;
            }else {
                ans+=1LL*per*cnt;
                now+=cnt;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}


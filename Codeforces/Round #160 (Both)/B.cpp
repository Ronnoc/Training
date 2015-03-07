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

int a[100005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T,n;
    while(~scanf("%d%d",&n,&k)){
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        priority_queue<int>Q;
        for(i=0;i<n;i++)Q.push(-a[i]);
        while(!Q.empty()&&k){
            int u=Q.top();
            Q.pop();
            k--;
            Q.push(-u);
        }
        LL ans=0;
        while(!Q.empty()){
            ans+=Q.top();
            Q.pop();
        }
        cout<<-ans<<"\n";
    }
    return 0;
}


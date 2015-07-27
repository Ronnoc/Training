#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define aa first
#define bb second
#define op begin()
#define ed end()
#define sz size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define name ""
#define usingfile 0

int main(){
    if(usingfile)freopen(name".in","r",stdin);
    if(usingfile)freopen(name".out","w",stdout);
    int i,j,k,_t,x;
    map<int,int>l,r,f;
    int n;
    while(~scanf("%d",&n)){
        l.clear();
        r.clear();
        f.clear();
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            if(l.find(x)==l.ed)l[x]=i;
            r[x]=i;
            f[x]++;
        }
        int le=1,re=n,cnt=0;
        for(map<int,int>::iterator it=f.op;it!=f.ed;++it){
            int x=(*it).aa;
            if(f[x]>=cnt){
                if(f[x]>cnt)le=l[x],re=r[x];
                cnt=f[x];
                if(re-le>r[x]-l[x]){
                    le=l[x];
                    re=r[x];
                }
            }
        }
        printf("%d %d\n",le,re);
    }
    return 0;
}


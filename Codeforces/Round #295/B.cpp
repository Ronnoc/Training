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

map<PII,int>F;
map<PII,int>::iterator it;
vector<int>L;
int x[100005];
int y[100005];
int s[100005];
int t[100005];
set<int>S,O;
const LL MOD = 1000000009;
bool check(int i){
    if(s[i]==0)
        return true;
    int only=0,a=i,id;
    it=F.find(MP(x[a]-1,y[a]+1));
    if(it!=F.ED){id=(*it).BB;if(O.count(id)==0&&t[id]==1)only=1;}
    it=F.find(MP(x[a],y[a]+1));
    if(it!=F.ED){id=(*it).BB;if(O.count(id)==0&&t[id]==1)only=1;}
    it=F.find(MP(x[a]+1,y[a]+1));
    if(it!=F.ED){id=(*it).BB;if(O.count(id)==0&&t[id]==1)only=1;}
    if(!only)
        return true;
    return false;
}
int dx[]={-2,-1,1,2,-1,0,1};
int dy[]={0,0,0,0,-1,-1,-1};
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int m;
    while(~scanf("%d",&m)){
        F.clear();
        L.clear();
        S.clear();
        O.clear();
        for(i=0;i<m;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(i=0;i<m;i++)
            F[MP(x[i],y[i])]=i,s[i]=0;
        int id;
        for(i=0;i<m;i++){
            int cnt=0;
            if(F.find(MP(x[i]-1,y[i]+1))!=F.ED)cnt++;
            if(F.find(MP(x[i],y[i]+1))!=F.ED)cnt++;
            if(F.find(MP(x[i]+1,y[i]+1))!=F.ED)cnt++;
            s[i]=cnt;
            cnt=0;
            if(F.find(MP(x[i]-1,y[i]-1))!=F.ED)cnt++;
            if(F.find(MP(x[i],y[i]-1))!=F.ED)cnt++;
            if(F.find(MP(x[i]+1,y[i]-1))!=F.ED)cnt++;
            t[i]=cnt;
        }
        for(i=0;i<m;i++)
            if(check(i))S.insert(i);
        LL ans=0;
        int flag=0;
        while(!S.empty()){
            flag^=1;
            int a;
            if(flag){
                a=*(--S.ED);
                S.erase(--S.ED);}
            else {
                a=*S.OP;
                S.erase(S.OP);
            }
            L.PB(a);
            O.insert(a);
            for(int p=x[a]-1;p<=x[a]+1;p++){
                it=F.find(MP(p,y[a]+1));
                if(it==F.ED)continue;
                id=(*it).BB;
                t[id]--;
            }
            for(int p=x[a]-1;p<=x[a]+1;p++){
                it=F.find(MP(p,y[a]-1));
                if(it==F.ED)continue;
                id=(*it).BB;
                s[id]--;
            }
            for(i=0;i<7;i++){
                int p=x[a]+dx[i],q=y[a]+dy[i];
                it=F.find(MP(p,q));
                if(it==F.ED)continue;
                int id=(*it).BB;
                if(O.count(id))continue;
                if(S.count(id))S.erase(S.find(id));
                if(check(id))S.insert(id);
            }
        }
        for(i=0;i<L.SZ;i++)
            ans=(ans*m+L[i])%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}


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
#define NAME "cs1"
#define UsingFile 1

vector<string>L[205];
char s[1000005];
LL hash(string s){
    LL ret=0;
    for(int i=0;i<s.SZ;i++)ret=ret*4437+s[i];
    return ret;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        int n;
        scanf("%d%*c",&n);
        map<LL,int>MA;
        for(i=n-1;i>=0;i--){
            gets(s);
            istringstream sin(s);
            string t;
            L[i].clear();
            while(sin>>t){L[i].PB(t);}
            sort(L[i].OP,L[i].ED);
            L[i].erase(unique(L[i].OP,L[i].ED),L[i].ED);
            for(j=0;j<L[i].SZ;j++)
                MA[hash(L[i][j])]|=1<<i;
        }
        int ans=2000000000;
        int m=n-2;
        int all=(1<<m)-1;
        for(i=0;i<1<<m;i++){
            int E=i|(1<<(m));
            int F=(all^i)|(1<<(m+1));
            int tmp=0;
            for(map<LL,int>::iterator it=MA.OP;it!=MA.ED;++it){
                int mask=(*it).BB;
                if(mask&E)if(mask&F)tmp++;
            }
            cmin(ans,tmp);
        }
        cerr<<CA<<"\n";
        printf("Case #%d: %d\n",CA,ans);
    }
    return 0;
}


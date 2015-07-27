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
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        char s[55][55];
        for(i=0;i<n;i++)scanf("%s",s[i]);
        set<char>S;
        S.insert('f');
        S.insert('a');
        S.insert('c');
        S.insert('e');
        int ans=0;
        for(i=0;i+1<n;i++)
            for(j=0;j+1<m;j++){
                set<char>T;
                T.insert(s[i][j]);
                T.insert(s[i][j+1]);
                T.insert(s[i+1][j]);
                T.insert(s[i+1][j+1]);
                if(S==T)ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}


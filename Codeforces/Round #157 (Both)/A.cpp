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

char s[16][16];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    for(i=0;i<8;i++)scanf("%s",s[i]);
    int flag=1;
    for(i=0;i<8;i++){
        int p=0;
        for(j=0;j<8;j++)if(s[i][j]=='W')p++;
        if(p!=4)flag=0;
        for(j=0;j<7;j++)
            if(s[i][j]==s[i][j+1])flag=0;
    }
    printf("%s\n",flag?"YES":"NO");
    return 0;
}


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

    char s[1000005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%s",s)){
        int x=0,y=0;
        for(i=0;s[i];i++)if(s[i]=='x')x++;else y++;
        while(x&&y)x--,y--;
        while(y--)putchar('y');
        while(x--)putchar('x');
        putchar('\n');
    }
    return 0;
}


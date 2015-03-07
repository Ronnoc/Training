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

char s[100005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%s",s)){
        int len=strlen(s);
        int flag=0;
        for(i=0;i<len;i++)if(s[i]=='0')flag=1;
        if(flag){
            for(i=0;i<len;i++){
                if(s[i]=='0'&&flag)flag=0;
                else printf("%c",s[i]);
            }
            printf("\n");
        }else {
            s[len-1]='\0';
            printf("%s\n");
        }
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define OP begin()
#define ED end()
#define SZ size()
#define AA first
#define BB second
#define SQ(x) ((x)*(x))
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
typedef long long LL;
typedef pair<int,int> PII;
char s[100005];
const int MXN = 100005;
int RMQ[20][MXN];
int query(int l,int r) {
  int len=r-l+1;
  int mx=31-__builtin_clz(len);
  return RMQ[mx][l]|RMQ[mx][r-(1<<mx)+1];
}
int main() {
  #define NAME "jingles"
  freopen(NAME".in","r",stdin);
  freopen(NAME".out","w",stdout);
  int T,i,j;
  scanf("%d",&T);
  while(T--) {
    scanf("%s",s);
    int len=strlen(s);
    for(i=0; i<len; i++)
      RMQ[0][i]=1<<(s[i]-'a');
    for(j=1; (1<<j)<=len; j++) {
      for(i=0; i+(1<<j)-1<len; i++)
        RMQ[j][i]=RMQ[j-1][i]|RMQ[j-1][i+(1<<(j-1))];
    }
    map<int,int>o;
    map<int,int>::iterator it;
    for(i=0; i<len; i++) {
      int all=query(i,len-1);
      cmax(o[all],len-i);
      int cnt=__builtin_popcount(all);
      int last=i-1;
      for(j=1; j<cnt; j++) {
        int le=last+1,re=len-1,ge=-1;
        while(re>=le) {
          if(re-le<=1) {
            if(__builtin_popcount(query(i,re))==j)
              ge=re;
            else ge=le;
            break;
          }
          int mid=(le+re)>>1;
          int fm=__builtin_popcount(query(i,mid));
          if(fm>j)re=mid-1;
          else le=mid;
        }
        last=ge;
        cmax(o[query(i,last)],last-i+1);
      }
    }
    LL ans=0,cnt=0;
    for(it=o.OP; it!=o.ED; ++it) {
      int mask=(*it).AA;
      int len=(*it).BB;
      ans+=1LL*(len)*__builtin_popcount(mask),cnt++;
    }
    cout<<cnt<<" "<<ans<<"\n";
  }
  return 0;
}

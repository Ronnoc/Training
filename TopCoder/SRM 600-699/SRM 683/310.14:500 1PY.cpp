#include <bits/stdc++.h> 
using namespace std; 
#define AA first 
#define BB second 
#define OP begin() 
#define ED end() 
#define SZ size() 
#define MP make_pair 
#define PB push_back 
#define cmax(x,y) x=max((x),(y)) 
#define cmin(x,y) x=min((x),(y)) 

typedef long long LL; 
typedef pair<int,int> PII; 
const LL MOD = 1000000007; 
const int N = 10000000; 
LL p[N+10], pn; 
bool flag[N+10];   //true[\u28051][\u21700][\u24718][\u37825][\u65533] 
void init(int n) { 
    pn = 0; 
    for(int i = 2; i <= n; i++) { 
        if(!flag[i]) 
            p[pn ++ ] = i; 
        for(int j = 0; j < pn && i * p[j] <= n; j++) { 
            flag[i * p [j]] = true; 
            if(i % p[j] == 0) 
                break; 
        } 
    } 
} 
vector<int>mul; 
vector<int>L; 
int tot[N+10]; 
class GCDLCM2 { 
public: 
  int getMaximalSum( vector <int> start, vector <int> d, vector <int> cnt ) { 
    init(10000000); 
    L.clear(); 
    int i,j,k; 
    LL ret=0; 
    for(i=0;i<start.SZ;i++) 
      for(j=0;j<cnt[i];j++) 
        L.PB(start[i]+j*d[i]); 
    //for(i=0;i<L.SZ;i++)cout<<L[i]<<" ";cout<<"\n"; 
    mul=L; 
    for(i=0;i<N;i++)tot[i]=0; 
    for(i=0;i<L.SZ;i++)mul[i]=1; 
    for(i=0;i<L.SZ;i++)tot[L[i]]++; 
    for(i=0;i<pn;i++){ 
      map<int,int>S; 
      int sum=L.SZ; 
      for(j=p[i];j<N;j+=p[i])if(tot[j]){ 
        int tmp=j,cnt=0; 
        while(tmp%p[i]==0)tmp/=p[i],cnt++; 
        S[cnt]+=tot[j]; 
        sum-=tot[j]; 
      } 
      vector<PII>R(S.OP,S.ED); 
      LL cnt=0; 
      for(j=0;j<R.SZ;j++){ 
        LL tmp=1; 
        while(cnt<R[j].AA)cnt++,tmp=tmp*p[i]%MOD; 
        mul[sum]=mul[sum]*tmp%MOD; 
        sum+=R[j].BB; 
      } 
    } 
    LL now=1; 
    for(i=0;i<L.SZ;i++){ 
      now=now*mul[i]%MOD; 
      ret+=now; 
    } 
    return ret%MOD; 
  } 
}; 
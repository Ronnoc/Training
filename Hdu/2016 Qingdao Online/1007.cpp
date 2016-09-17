//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<mlist>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;

int a[MXN];
int tot[1111];
int N,Z;
LL ok(int me){
    //cout<<"@"<<me<<"\n";
	map<int,int>S;
    int num=0;
    rep(i,1,1001)if(tot[i])S[i]=tot[i],num+=tot[i];
    LL ret=0;
    int fi=(num-1)%(me-1);
    while(!S.empty()){
        if(ret>Z)break;
        PII pr = *S.OP;
        S.erase(S.OP);
        if(S.empty()&&pr.BB==1)break;
        int aim=fi;
        fi=0;
        if(!aim)aim=me-1;
        aim++;
        if(pr.BB>=aim){
            pr.BB-=aim;
            if(pr.BB)S[pr.AA]=pr.BB;
            ret+=pr.AA*aim;
            S[pr.AA*aim]++;
            //cout<<"?"<<pr.AA*aim<<"\n";
            continue;
        }
        int cnt = pr.BB;
        int add = pr.BB*pr.AA;
        while(!S.empty()&&cnt<aim){
            PII rp = *S.OP;
            S.erase(S.OP);
            if(rp.BB>=aim-cnt){
                int d=aim-cnt;
                rp.BB-=d;
                cnt+=d;
                add+=rp.AA*d;
                if(rp.BB)S[rp.AA]=rp.BB;
                break;
            }else {
                cnt+=rp.BB;
                add+=rp.BB*rp.AA;
            }
        }
        //cout<<"?"<<add<<"\n";
        S[add]++;
        ret+=add;
    }
    //cout<<">"<<ret<<"\n";
    return ret;
}
void solve(){
	RI(N);
	RI(Z);
    rep(i,0,1001)tot[i]=0;
	rep(i,0,N){
        RI(a[i]);
        tot[a[i]]++;
    }
	int le=2,re=N,ge=-1;
	while(re>=le){
		if(re-le<=1){
			if(ok(le)<=Z)ge=le;
			else ge=re;
			break;
		}
		int me=(le+re)/2;
		if(ok(me)<=Z)re=me;
		else le=me;
	}
	printf("%d\n",ge);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}
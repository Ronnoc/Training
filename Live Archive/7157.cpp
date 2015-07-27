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

double SQ(double x){return x*x;}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    double w,h;
    int n;
    while(cin>>w>>h>>n){
        n++;
        double s=1;
        vector<double>L;
        double x=1;
        L.PB(x);
        double k=h/w;
        double q=(2*k*k)/(1-k*k);
        for(i=1;i<n;i++){
            double xn=x+q*s;
            double sn=xn+s;
            x=xn,s=sn;
            L.PB(xn);
        }
        double p=w/s;
        for(i=0;i<L.SZ;i++)L[i]*=p;
        s=0;
        double ans=0;
        for(i=0;i<L.SZ;i++){
            s+=L[i];
            if(i+1<L.SZ)
                ans-=SQ(s*k)/2;
            ans+=SQ(2*k*s+(1-k)*L[i])/4;
        }
        printf("%.16f\n",ans);
        s=0;
        for(i=0;i+1<L.SZ&&i<10;i++){
            s+=L[i];
            printf("%.16f\n",s);
        }
    }
    return 0;
}


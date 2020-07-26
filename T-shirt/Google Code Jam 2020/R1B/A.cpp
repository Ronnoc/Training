#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

int check(LL w){
    LL ww=w&1;
    if(ww==1)return 1;
    if(ww==-1)return 1;
    return 0;
}

void solve()
{
    int x,y;
    scanf("%d%d",&x,&y);
    LL X,Y;
    X=x,Y=y;
    // S:y-
    // N:y+
    // E:x+
    // w:x-
    string res="";
    for(int i=0;i<40;i++){
        // cout<<res<<" "<<i<<" "<<X<<" "<<Y<<"\n";
        if(X==0 && Y==0){
            cout<<res<<"\n";
            return;
        }
        if (check (X)==check(Y))
        {
            printf("IMPOSSIBLE\n");
            return;
        }
        if(check(X)==1){
            LL lx = (X+1) /2;
            LL rx = (X-1) /2;
            LL ny = Y /2;
            if(ny==0&&lx==0){
                res+="W";
                Y=ny;
                X=lx;
            }else if(ny==0&&rx==0){
                res += "E";
                Y = ny;
                X = rx;
            }
            else if (check(ny) != check(lx))
            {

                res += "W";
                Y = ny;
                X = lx;
            }
            else if (check(ny) != check(rx))
            {
                res += "E";
                Y = ny;
                X = rx;
            }
            else
            {
                cerr<<"fail!\n";
                return;
            }
        }else{
            LL ly = (Y+1) /2;//N
            LL ry = (Y-1) /2;//S
            LL nx = X /2;
            if(nx==0&&ly==0){
                res+="S";
                Y=ly;
                X=nx;
            }else if(nx==0&&ry==0)
            {
                res += "N";
                Y = ry;
                X = nx;
            }
            else if (check(nx) != check(ly))
            {
                res += "S";
                Y = ly;
                X = nx;
            }
            else if (check(nx) != check(ry))
            {
                res += "N";
                Y = ry;
                X = nx;
            }
            else
            {
                cerr << "fail!\n";
                return;
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return;
}

int main()
{
    int i, j, k, _T;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d: ", CA);
        solve();
    }
    return 0;
}
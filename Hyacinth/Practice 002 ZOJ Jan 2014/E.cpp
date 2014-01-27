#include<stdio.h>
typedef long long LL;
int main()
{
    LL n,ans;
    while(~scanf("%lld",&n))
    {
        if(n&1)ans=(n*n-n+2)*(n-1)+n+(n-3)*(n-1)/2;
        else ans=(n-2)*(n-2)/2+n+(n*n-n+2)*(n-1);
        printf("%lld\n",ans);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
 int n;
 while(scanf("%d",&n)==1)
    {
                         double p;
                         scanf("%lf",&p);
                         double a,b;
                         b=log(p);
                         double out=floor(exp(b/n)+0.5);
                         printf("%.0f\n",out);
                         }
    return 0;
}

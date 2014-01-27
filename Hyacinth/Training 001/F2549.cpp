#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define AA first
#define BB second
#define MP make_pair

pair<int,int>A[1000010];
pair<int,int>B[1000010];
int n,a[1010],acnt,bcnt;

bool cmpa(pair<int,int>X,pair<int,int>Y)
{
    return X.AA<Y.AA;
}
bool cmpb(pair<int,int>X,pair<int,int>Y)
{
    return X.AA+X.BB<Y.AA+Y.BB;
}
bool judge(pair<int,int>&X,pair<int,int>&Y)
{
    int a=X.AA-X.BB;
    int b=X.BB;
    int c=Y.BB;
    int d=Y.AA+Y.BB;
    if(a!=c && a!=d && b!=d && c!=d && a!=b && b!=c)return true;
    return false;
}
int main()
{
    //freopen("for F.txt","r",stdin);
    int i,j,ans,flag;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        acnt=0;
        bcnt=0;
        for(i=2;i<=n;i++)
            for(j=1;j<i;j++)
                A[++acnt]=MP(a[i]+a[j],a[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j && a[j]*3>a[i])B[++bcnt]=MP(a[i]-a[j],a[j]);
        sort(A+1,A+acnt+1,cmpa);
        sort(B+1,B+bcnt+1,cmpb);
        /*for(i=1;i<=acnt;i++)
            printf("%I64d %I64d\n",A[i].AA,A[i].BB);
        printf("\n");
        for(i=1;i<=bcnt;i++)
            printf("%I64d %I64d\n",B[i].AA,B[i].BB);
        printf("\n");*/
        flag=0;
        for(i=bcnt;i>=1;i--)
        {
            int x=lower_bound(A+1,A+acnt+1,B[i],cmpa)-A;
            int y=upper_bound(A+1,A+acnt+1,B[i],cmpa)-A;
            //printf("%I64d %I64d %I64d\n",i,x,y);
            for(j=x;j<y;j++)
                if(judge(A[j],B[i]))break;
            if(j<y)
            {
                ans=B[i].AA+B[i].BB;
                flag=1;
                break;
            }
        }
        if(flag)printf("%d\n",ans);
        else printf("no solution\n");
    }
    return 0;
}

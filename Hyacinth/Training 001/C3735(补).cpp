#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
    int z,y,l,r;
    int v;
}pool[400010];
int pcnt;
int n,m,q,tm[100010],a[100010],b[100010];

void build(int p,int zz,int yy)
{
    int mid=(zz+yy)>>1;
    pool[p].z=zz;
    pool[p].y=yy;
    if(zz==yy)
    {
        pool[p].v=tm[zz];
        return;
    }
    build(pool[p].l=++pcnt,zz,mid);
    build(pool[p].r=++pcnt,mid+1,yy);
    pool[p].v=max(pool[pool[p].l].v,pool[pool[p].r].v);
}
int get(int p,int zz,int yy)
{
    int mid=(pool[p].z+pool[p].y)>>1;
    if(pool[p].z==zz && pool[p].y==yy)return pool[p].v;
    if(yy<=mid)return get(pool[p].l,zz,yy);
    else if(mid<zz)return get(pool[p].r,zz,yy);
    else return max(get(pool[p].l,zz,mid),get(pool[p].r,mid+1,yy));
}
int main()
{
    int i,j,tt,tmp,ans;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&q);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=a[1]-1;
        tt=0;tmp=a[0];
        for(i=1;i<=n;i++)
        {
            if(a[i]!=tmp)
            {
                tt++;
                tm[tt]=0;
            }
            tmp=a[i];
            a[i]=tt;
            tm[tt]++;
        }
        m=tt;
        //for(i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
        //for(i=1;i<=m;i++)printf("%d ",tm[i]);printf("\n");
        pcnt=0;
        build(0,1,m);
        for(i=1;i<=q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(a[l]==a[r])printf("%d\n",r-l+1);
            else
            {
                ans=0;
                if(a[r]-a[l]>=2)ans=get(0,a[l]+1,a[r]-1);
                ans=max(ans,upper_bound(a+1,a+n+1,a[l])-a-l);
                ans=max(ans,r-(lower_bound(a+1,a+n+1,a[r])-a)+1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

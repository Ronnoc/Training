#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;

struct node
{
    int z,y,l,r;
    int v;
}pool[320010];
int pcnt;
int a[100010],b[100010],n;
LL ans;

void build(int p,int zz,int yy)
{
    int mid=(zz+yy)>>1;
    pool[p].z=zz;
    pool[p].y=yy;
    pool[p].v=n+1;
    if(zz==yy)return;
    build(pool[p].l=++pcnt,zz,mid);
    build(pool[p].r=++pcnt,mid+1,yy);
}
void add(int p,int pos,int vv)
{
    int mid=(pool[p].z+pool[p].y)>>1;
    if(pool[p].z==pool[p].y)
    {
        pool[p].v=vv;
        return;
    }
    if(pos<=mid)add(pool[p].l,pos,vv);
    else add(pool[p].r,pos,vv);
    pool[p].v=min(pool[pool[p].l].v,pool[pool[p].r].v);
}
int get(int p,int zz,int yy)
{
    int mid=(pool[p].z+pool[p].y)>>1;
    if(pool[p].z==zz && pool[p].y==yy)return pool[p].v;
    if(yy<=mid)return get(pool[p].l,zz,yy);
    else if(zz>mid)return get(pool[p].r,zz,yy);
    else return min(get(pool[p].l,zz,mid),get(pool[p].r,mid+1,yy));
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    ans=0;
    pcnt=0;
    build(0,1,n);
    for(i=n;i>=1;i--)
    {
        int bb=get(0,a[i],n);
        ans+=bb-i-1;
        add(0,a[i],i);
    }
    printf("%I64d\n",ans);
    return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define AA first
#define BB second
#define HUGE 500010
#define l(p) pool[p].l
#define r(p) pool[p].r

struct node
{
    int z,y,l,r;
    int v;
}pool[200010];
int pcnt,n,m;
pair<int,int>mac[500010];

void build(int p,int zz,int yy)
{
    pool[p].z=zz;
    pool[p].y=yy;
    pool[p].v=HUGE;
    if(zz==yy)return;
    int mid=(zz+yy)>>1;
    build(l(p)=++pcnt,zz,mid);
    build(r(p)=++pcnt,mid+1,yy);
    pool[p].v=min(pool[l(p)].v,pool[r(p)].v);
}
void add(int p,int pos,int vv)
{
    if(pool[p].z==pool[p].y)
    {
        pool[p].v=min(vv,pool[p].v);
        return;
    }
    int mid=(pool[p].z+pool[p].y)>>1;
    if(pos<=mid)add(l(p),pos,vv);
    else add(r(p),pos,vv);
    pool[p].v=min(pool[l(p)].v,pool[r(p)].v);
}
int get(int p,int zz,int yy)
{
    if(pool[p].z==zz && pool[p].y==yy)return pool[p].v;
    int mid=(pool[p].z+pool[p].y)>>1;
    if(yy<=mid)return get(l(p),zz,yy);
    else if(mid<zz)return get(r(p),zz,yy);
    else return min(get(l(p),zz,mid),get(r(p),mid+1,yy));
}
int main()
{
    //freopen("2.txt","r",stdin);
    int i,ans,zero=0;
    scanf("%d%d",&n,&m);
    //while(~scanf("%d%d",&n,&m)){
    for(i=1;i<=m;i++)
        scanf("%d%d",&mac[i].AA,&mac[i].BB);
    //sort(mac+1,mac+m+1,cmp);
    pcnt=0;
    build(0,0,n);
    add(0,1,0);
    for(i=1;i<=m;i++)
        add(0,mac[i].BB,get(0,mac[i].AA,mac[i].BB-1)+1);
    ans=get(0,n,n);
    if(ans>=HUGE)i=1/zero;
    printf("%d\n",ans);
    return 0;
}

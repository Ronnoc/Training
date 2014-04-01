#include<stdio.h>
int first=1;
int out(int q,int k)
{
if(q==0)return 0;
if(first)
{
	first=0;
	if(q<0){printf("-");q=-q;}
	if(!(q==1 && k!=9))printf("%d",q);
	if(k==8)printf("x");
	else if(k==9)printf("");
	else printf("x^%d",9-k);
	}
else
{
	if(q>0)
	{
		printf(" + ");
		}
	else
	{
		q=-q;
		printf(" - ");
		}
	if(!(q==1&&k!=9))printf("%d",q);
	if(k==8)printf("x"); 
	else if(k==9)printf("");
	else printf("x^%d",9-k);
	}
return 0;
}
int main()
{
	int q,w,e,r,t,y,u,i,o;
	while(scanf("%d%d%d%d%d%d%d%d%d",&q,&w,&e,&r,&t,&y,&u,&i,&o)!=EOF)
	{
		out(q,1);
		out(w,2);
		out(e,3);
		out(r,4);
		out(t,5);
		out(y,6);
		out(u,7);out(i,8);out(o,9);
		if(q==0 && w==0 && e==0&&r==0&&t==0&&y==0&&u==0&&i==0&&o==0)printf("0");
		printf("\n");
		first=1;
		}
	return 0;
	} 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define eps 1e-8
struct pak{
	char s[40];
	bool operator<(const pak &tp)const{return strcmp(s,tp.s)<0;}
	bool operator==(const pak &tp)const{return strcmp(s,tp.s)==0;}
	}tp;
vector<pak>L;
double abs(double x){if(x>0)return x;return -x;}
int cho[10];
int q,w,e,r;
int z,x,c;
int a[10];
int flag=0;
int po;
char g(int t){
	if(t==1)return '+';
	if(t==2)return '-';
	if(t==3)return '*';
	if(t==4)return '/';
	}
bool check(int t){
	int i;
	for(i=1;i<t;i++)if(cho[i]==cho[t])return 0;
	return 1;
	}
double f(double a,double b,int t){
	if(t==1)return a+b;
	if(t==2)return a-b;
	if(t==3)return a*b;
	if(t==4&&b==0)return -100000000;
	if(t==4)return ((double)a)/b;
	}
void op(int t){
	int i;
	for(i=1;i<=4;i++)cho[i]=i;
		for(z=1;z<=4;z++)for(x=1;x<=4;x++)for(c=1;c<=4;c++){
			double res,res1,res2;
			res=f(a[cho[1]],a[cho[2]],z);
			res=f(res,a[cho[3]],x);
			res=f(res,a[cho[4]],c);
			if(abs(res-24)<=eps){flag=1;sprintf(tp.s,"((%d%c%d)%c%d)%c%d\n",a[cho[1]],g(z),a[cho[2]],g(x),a[cho[3]],g(c),a[cho[4]]);L.push_back(tp);}
			res1=f(a[cho[1]],a[cho[2]],z);
			res2=f(a[cho[3]],a[cho[4]],c);
			res=f(res1,res2,x);
			if(abs(res-24)<=eps){flag=1;sprintf(tp.s,"(%d%c%d)%c(%d%c%d)\n",a[cho[1]],g(z),a[cho[2]],g(x),a[cho[3]],g(c),a[cho[4]]);L.push_back(tp);}
			res=f(a[cho[2]],a[cho[3]],x);
			res=f(a[cho[1]],res,z);
			res=f(res,a[cho[4]],c);
			if(abs(res-24)<=eps){flag=1;sprintf(tp.s,"(%d%c(%d%c%d))%c%d\n",a[cho[1]],g(z),a[cho[2]],g(x),a[cho[3]],g(c),a[cho[4]]);L.push_back(tp);}
			res=f(a[cho[2]],a[cho[3]],x);
			res=f(res,a[cho[4]],c);
			res=f(a[cho[1]],res,z);
			if(abs(res-24)<=eps){flag=1;sprintf(tp.s,"%d%c((%d%c%d)%c%d)\n",a[cho[1]],g(z),a[cho[2]],g(x),a[cho[3]],g(c),a[cho[4]]);L.push_back(tp);}
			res=f(a[cho[3]],a[cho[4]],c);
			res=f(a[cho[2]],res,x);
			res=f(a[cho[1]],res,z);
		//	if(c==4&&x==2&&z==4)printf("%lf\n",res); //非常不能理解3,3,8,8时候程序的结果!:eps太小了.... 
			if(abs(res-24)<=eps){flag=1;sprintf(tp.s,"%d%c(%d%c(%d%c%d))\n",a[cho[1]],g(z),a[cho[2]],g(x),a[cho[3]],g(c),a[cho[4]]);L.push_back(tp);}
			}
	}
int main(){
	int i;
	while(scanf("%d%d%d%d",&q,&w,&e,&r)!=EOF){
		L.clear();
		flag=0;
		a[1]=q;a[2]=w;a[3]=e;a[4]=r;
		op(1);
		sort(L.begin(),L.end());
		L.erase(unique(L.begin(),L.end()),L.end());
		if(!flag)printf("NONE\n"); 
		else for(i=0;i<L.size();i++)printf("%s",L[i].s);
		}
	return 0;
	}

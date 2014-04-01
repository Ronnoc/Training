#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define N 50010
struct BI{
    int s[10];
    int len;
    BI() {	len=1;	memset(s,0,sizeof(s));	}
    BI operator = (const char *num){
		len=strlen(num);
		for(int i=0;i<len;i++)s[i]=num[len-1-i]-'0';	
		}
	BI operator + (const BI tp){
		BI c;
  		c.len=max(len,tp.len);
		for(int i=0;i<c.len;i++){
		    c.s[i]+=s[i]+tp.s[i];
			while(c.s[i]>=100000000){	c.s[i+1]+=c.s[i]/100000000;	c.s[i]%=100000000;	}
	        }
	    if(c.s[c.len])c.len++;
		return c;			
		}
    }tree[6][N];	//tree[i][j]以j为第i大元素的子序列个数 
vector<int>L,map;
vector<int>::iterator iter;
int n;
int locate(int x){
	iter=lower_bound(map.begin(),map.end(),x);
	return iter+2-map.begin();
	}
int LB(int x){return x&(-x);}
void add(int tt,int w,BI d){
	for(;w<=n+3;w+=LB(w))tree[tt][w]=tree[tt][w]+d;
	}
BI get_sum(int tt,int w){
	BI res;
	for(;w>0;w-=LB(w))res=res+tree[tt][w];
	return res;
	}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		int i,x;
		L.clear();	map.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			L.push_back(x);
			map.push_back(x);
			}
		sort(map.begin(),map.end());
		memset(tree,0,sizeof(tree));
		for(i=0;i<n;i++){
			x=L[i];
			x=locate(x);
			BI tp;	tp="1";
			add(1,x,tp);
			for(int j=2;j<6;j++)add(j,x,get_sum(j-1,x-1));
			}
		BI res=get_sum(5,n+3);
		printf("%d",res.s[res.len-1]);
		for(i=res.len-2;i>=0;i--)printf("%08d",res.s[i]);
		printf("\n");
		}
	return 0;
	}

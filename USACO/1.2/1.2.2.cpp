/*
ID: kybconn1
PROG: transform
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct at{
	int x,y;
	bool operator <(const at &tp)const{
		if(x-tp.x)return x<tp.x;
		return y<tp.y;
		}
	bool operator==(const at &tp)const
		{return x==tp.x&&y==tp.y;}
	}tp;
int n;
vector<at>L,R;
vector<at>::iterator iter;
void out(at tp){printf("%d %d\n",tp.x,tp.y);}
int main(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	char s[10];
	int i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%s",s);
			for(j=0;j<n;j++)if(s[j]=='@'){
				tp.x=i;tp.y=j;
				L.push_back(tp);
				}
			}
		for(i=0;i<n;i++){
			scanf("%s",s);
			for(j=0;j<n;j++)if(s[j]=='@'){
				tp.x=i;tp.y=j;
				R.push_back(tp);
				}
			}
		sort(L.begin(),L.end());
		sort(R.begin(),R.end());
		if(L.size()!=R.size()){printf("7\n");continue;}	
		int flag=1;
		for(i=0;i<L.size();i++){
			tp.x=L[i].y;
			tp.y=n-1-L[i].x;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
		//	if(flag)out(*iter);
			}	
		if(flag){printf("1\n");continue;}
		
		flag=1;
		for(i=0;i<L.size();i++){
			tp.x=n-1-L[i].x;
			tp.y=n-1-L[i].y;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
			}	
		if(flag){printf("2\n");continue;}
		
		flag=1;
		for(i=0;i<L.size();i++){
			tp.x=n-1-L[i].y;
			tp.y=L[i].x;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
			}	
		if(flag){printf("3\n");continue;}	
		
		flag=1;
		for(i=0;i<L.size();i++){
			tp.x=L[i].x;
			tp.y=n-1-L[i].y;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
			}	
		if(flag){printf("4\n");continue;}
		
		int lx,ly;
		flag=1;
		for(i=0;i<L.size();i++){
			lx=L[i].x;
			ly=n-1-L[i].y;
			tp.x=ly;
			tp.y=n-1-lx;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
			}	
		if(flag){printf("5\n");continue;}
		
		flag=1;
		for(i=0;i<L.size();i++){
			lx=L[i].x;
			ly=n-1-L[i].y;
			tp.x=n-1-lx;
			tp.y=n-1-ly;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
			}	
		if(flag){printf("5\n");continue;}
		
		flag=1;
		for(i=0;i<L.size();i++){
			lx=L[i].x;
			ly=n-1-L[i].y;
			tp.x=n-1-ly;
			tp.y=lx;
			iter=lower_bound(R.begin(),R.end(),tp);
			if(!(*iter==tp))flag=0;
			}	
		if(flag){printf("5\n");continue;}
		
		flag=1;
		for(i=0;i<L.size();i++)if(!(L[i]==R[i]))flag=0;
		if(flag){printf("6\n");continue;}
					
		printf("7\n");
		}
	return 0;
	}

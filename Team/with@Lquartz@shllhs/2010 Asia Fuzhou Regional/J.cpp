//kybconnor
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <string.h>
using namespace std;
char a[11],b[11],c[11];
int la,lb,lc;
int ans;
int cho[11];
vector<char>L;
bool check(int h){
	int i;
	for(i=0;i<h;i++)if(cho[i]==cho[h])return 0;
	return 1;
}
void dfs(int h){
	int i;
	if(h>=L.size()){
		long long A=0LL,B=0LL,C=0LL;
		map<char,int>P;
		for(i=0;i<L.size();i++)P[L[i]]=cho[i];
		for(i=0;i<la;i++)A=A*10+P[a[i]];
		for(i=0;i<lb;i++)B=B*10+P[b[i]];
		for(i=0;i<lc;i++)C=C*10+P[c[i]];
		if(la>1&&P[a[0]]==0)return;
		if(lb>1&&P[b[0]]==0)return;
		if(lc>1&&P[c[0]]==0)return;
//		if(C==1)printf("%lld %lld %lld\n",A,B,C);
		if(A+B==C)ans++;//,printf("%lld+%lld=%lld\n",A,B,C);
		if(A-B==C)ans++;//,printf("%lld-%lld=%lld\n",A,B,C);
		if(A*B==C)ans++;//,printf("%lld*%lld=%lld\n",A,B,C);
		if(B!=0&&A==B*C)ans++;//,printf("%lld/%lld=%lld\n",A,B,C);
		return;
	}
	for(i=0;i<=9;i++){
		cho[h]=i;
		if(check(h))dfs(h+1);
	}
}
int main(){
	int T,i;
	scanf("%d",&T);
	while(T--){
		set<char>S;
		set<char>::iterator iter;
		scanf("%s%s%s",a,b,c);
		la=strlen(a),lb=strlen(b),lc=strlen(c);
		for(i=0;i<la;i++)S.insert(a[i]);
		for(i=0;i<lb;i++)S.insert(b[i]);
		for(i=0;i<lc;i++)S.insert(c[i]);
		L.clear();
		for(iter=S.begin();iter!=S.end();iter++)L.push_back(*iter);
		ans=0;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

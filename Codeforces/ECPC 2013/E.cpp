#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("ghanophobia.in","r",stdin);
	int T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		int a,b;
		scanf("%d:%d",&a,&b);
		a++;
		b+=6;
		if(a==b){
			b+=b-6;
			a++;
		}
		printf("Case %d: ",CA);
		if(a>b)printf("YES\n");
		else if(a<b)printf("NO\n");
		else printf("PENALTIES\n");
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	char s[10];
	while(scanf("%s",s)!=EOF){
		int q=s[0]-'0',w=s[2]-'0',e=s[4]-'0',r=s[6]-'0';
		int gcd=__gcd(w,r);
		q*=r/gcd;
		e*=w/gcd;
		w*=r/gcd;r=w;
		int x,y=w;
		if(s[3]=='+')x=q+e;
		else x=q-e;
		if(x){
			gcd=__gcd(abs(x),abs(y));
			x/=gcd,y/=gcd;
			if(y>1)cout<<x<<"/"<<y<<endl;
			else cout<<x<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int q,w,e,r;
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int T;
	cin>>T;
	while(T--){
		cin>>q>>w>>e>>r;
		if(w-q==e-w&&w-q==r-e){
			printf("%d %d %d %d %d\n",q,w,e,r,r+r-e);
		}
		else printf("%d %d %d %d %d\n",q,w,e,r,(int)(r*((double)r/e)));
	}
return 0;}

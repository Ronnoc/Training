#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double FF=((sqrt(5)+1)/2);
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a<b)swap(a,b);
		int t=a-b;
		if((int)(t*FF)==b)printf("0\n");
		else printf("1\n");
	}
	return 0;
}

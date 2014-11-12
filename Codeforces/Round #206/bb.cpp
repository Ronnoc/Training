#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second

typedef long long LL;
typedef pair<int, int> PII;

LL c1,c2,c3,c4,n,m;
LL nn[1111],mm[1111];
int main(){
	while(cin>>c1>>c2>>c3>>c4>>n>>m){
		int i;
		for(i=1;i<=n;i++)cin>>nn[i];
		for(i=1;i<=m;i++)cin>>mm[i];
		for(i=1;i<=n;i++)nn[i]=c1*nn[i];
		for(i=1;i<=m;i++)mm[i]=c1*mm[i];
		for(i=1;i<=n;i++)if(nn[i]>c2)nn[i]=c2;
		for(i=1;i<=m;i++)if(mm[i]>c2)mm[i]=c2;
		LL nnn=0,mmm=0;
		for(i=1;i<=n;i++)nnn+=nn[i];
		for(i=1;i<=m;i++)mmm+=mm[i];
		if(nnn>c3)nnn=c3;
		if(mmm>c3)mmm=c3;
		LL res=nnn+mmm;
		if(res>c4)res=c4;
		cout<<res<<endl;
	}
	
	return 0;
}

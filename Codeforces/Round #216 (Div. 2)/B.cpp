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
#define OP begin()
#define ED end()
//10 3 1 5 21 10
typedef long long LL;
typedef pair<int, int> PII;
int a[1111];
void solve(){
	int n,k,l,r,sk,sall;
	while(cin>>n>>k>>l>>r>>sall>>sk){
		int i;
		for(i=1;i<=n;i++){
			a[i]=l;
			sall-=l;
			if(i<=k)sk-=l;
		}
//		for(i=1;i<=n;i++)cout<<a[i]<<" ";
//		cout<<endl;
		while(sk){
			for(i=1;sk&&i<=k;i++){
				a[i]++;
				sk--;
				sall--;
			}
		}
//		for(i=1;i<=n;i++)cout<<a[i]<<" ";
//		cout<<endl;
		for(i=k+1;i<=n;i++){
			if(sall>=(a[k]-a[i])){
				sall-=a[k]-a[i];
				a[i]=a[k];
			}else {
				a[i]+=sall;
				sall=0;
			}
		}
		for(i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}

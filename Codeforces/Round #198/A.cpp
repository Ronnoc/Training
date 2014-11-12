#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
long long a[100010],ans,g;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
int main(){
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ans=0;
	for(i=1;i<=n;i++)ans+=a[i];
	for(i=2;i<=n;i++){
		int l=i-1,r=i;
		ans+=2*l*(n-r+1)*(a[i]-a[i-1]);
//		cout<<(2*l*(n-r+1))<<"*"<<(a[i]-a[i-1])<<endl;
	}
	g=gcd(n,ans);
	cout<<ans/g<<" "<<n/g<<endl;
return 0;
}

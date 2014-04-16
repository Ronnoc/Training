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
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;

int main(){
	freopen("od.txt","w",stdout);
	int i,j;
	int a[10];
	int n=4;
	for(i=0;i<n;i++)a[i]=i+1;
	int now=0;
	do{
		int add=0;
		for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(a[i]>a[j])add++;
		for(i=0;i<n;i++)cout<<a[i]<<" ";
		now+=add;
		cout<<now-add<<"-->"<<now<<endl;
	}while(next_permutation(a,a+n));
	return 0;
}

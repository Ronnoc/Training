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

int ch[11],tot;
bool check(int id){
	int i,j,k;
	for(i=1;i<id;i++)for(j=i+1;j<id;j++)for(k=j+1;k<id;k++)
		if(ch[i]>ch[j]&&ch[j]>ch[k])return 0;
	return 1;
}
void dfs(int id,int n,int k){
	int i;
	if(id>3)if(!check(id))return;
	if(id>n){
		if(check(id))tot++;
	}
	else {
		for(i=1;i<=k;i++){
			ch[id]=i;
			dfs(id+1,n,k);
		}
	}
}
int solve(int n,int k){
	int i,j;
	tot=0;
	dfs(1,n,k);
	return tot;
}
int main(){
	int n,k,p;
	for(n=1;n<=8;n++)for(k=1;k<=10;k++)cout<<n<<" "<<k<<" "<<solve(n,k)<<endl;
	return 0;
}
/*
1 1 1
1 2 2
1 3 3
1 4 4
1 5 5
1 6 6
1 7 7
1 8 8
1 9 9
1 10 10
2 1 1
2 2 4
2 3 9
2 4 16
2 5 25
2 6 36
2 7 49
2 8 64
2 9 81
2 10 100
3 1 1
3 2 8
3 3 26
3 4 60
3 5 115
3 6 196
3 7 308
3 8 456
3 9 645
3 10 880
4 1 1
4 2 16
4 3 72
4 4 210
4 5 485
4 6 966
4 7 1736
4 8 2892
4 9 4545
4 10 6820
5 1 1
5 2 32
5 3 192
5 4 692
5 5 1897
5 6 4368
5 7 8904
5 8 16584
5 9 28809
5 10 47344
6 1 1
6 2 64
6 3 496
6 4 2168
6 5 6965
6 6 18368
6 7 42168
6 8 87312
6 9 166881
6 10 299200
7 1 1
7 2 128
7 3 1248
7 4 6512
7 5 24250
7 6 72648
7 7 186636
7 8 427416
7 9 895059
7 10 1744600
8 1 1
8 2 256
8 3 3072
8 4 18880
8 5 80720
8 6 272718
8 7 779562
8 8 1965414
8 9 4492125
8 10 9488050
*/

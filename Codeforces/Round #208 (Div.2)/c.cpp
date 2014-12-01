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

typedef long long LL;
typedef pair<int, int> PII;
int q[111111];
int mx[111111];
int out[111111];
int w[111111];
void solve() {
  memset (mx, 0, sizeof mx);
  memset (out, 0, sizeof out);
  stack<PII>S;
  deque<PII>D;
  queue<PII>Q;
  priority_queue<PII>pQ;
  int n;
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) cin >> q[i];
  int tot = 0;
  for (i = 1; i <= n; i++) {
    if (q[i])
      pQ.push (MP (q[i], i));
    else {
      if (pQ.size() >= 3) {
        for (int k = 1; k <= 3; k++) {
          PII tp = pQ.top();
          pQ.pop();
          out[tp.BB] = i;
          mx[i]++;
        }
        while(!pQ.empty())pQ.pop();
      } else {
        while (!pQ.empty()) {
          PII tp = pQ.top();
          pQ.pop();
          out[tp.BB] = i;
          mx[i]++;
        }
      }
    }
  }
//  for (i = 1; i <= n; i++) cout << q[i] << " ";
//  cout << endl;
//  for (i = 1; i <= n; i++) cout << mx[i] << " ";
//  cout << endl;
//  for (i = 1; i <= n; i++) cout << out[i] << " ";
//  cout << endl;
  for(i=1;i<=n;i++){
		if(q[i]){
			if(!out[i]){D.push_back(MP(q[i],out[i]));cout<<"pushBack\n";continue;}
			
			if(Q.empty()){Q.push(MP(q[i],out[i]));cout<<"pushQueue\n";continue;}
			else if(Q.back().BB<out[i]){Q.push(MP(q[i],out[i]));cout<<"pushQueue\n";continue;}
			
			if(S.empty()){S.push(MP(q[i],out[i]));cout<<"pushStack\n";continue;}
			else if(S.top().BB>out[i]){S.push(MP(q[i],out[i]));cout<<"pushStack\n";continue;}
			
			if(D.empty()){D.push_front(MP(q[i],out[i]));cout<<"pushFront\n";continue;}
			else if(D.front().BB>out[i]){D.push_front(MP(q[i],out[i]));cout<<"pushFront\n";continue;}
			{D.push_back(MP(q[i],out[i]));cout<<"pushBack\n";continue;}
		} else {
			cout<<mx[i];
			if(!S.empty()&&S.top().BB==i)cout<<" popStack",S.pop();
			if(!Q.empty()&&Q.front().BB==i)cout<<" popQueue",Q.pop();
			if(!D.empty()&&D.front().BB==i)cout<<" popFront",D.pop_front();
			if(!D.empty()&&D.back().BB==i)cout<<" popBack",D.pop_back();
			cout<<endl;
		}
  }
}
/*
6
8 2 1 4 0 0
5
8 2 1 4 0
*/
int main() {
//  while (1)
    solve();
  return 0;
}

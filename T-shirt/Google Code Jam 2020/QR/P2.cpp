#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

void solve()
{
    string s;
    cin >> s;
    string o;
    int d = 0;
    for (auto c : s)
    {
        int x = c - '0';
        while (x > d)
        {
            o += '(';
            d++;
        }
        while (x < d)
        {
            o += ')';
            d--;
        }
        o += c;
    }
    while (d--)
    {
        o = o + ')';
    }
    cout << o << endl;
}

int main()
{
    int i, j, k, _T;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d: ", CA);
        solve();
    }
    return 0;
}
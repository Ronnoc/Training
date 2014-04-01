#include <iostream>
using namespace std;
int main() {
    int m;
    while ( cin>>m ) {
        if ( !m )
            break;
        int i,a[110];
        for ( i=1; i<=m; i++ )
            cin>>a[i];
        int tp=0;
        for ( i=1; i<=m; i++ )
            tp=tp xor a[i];
        int res=0;
        if ( tp>0 )
            for ( i=1; i<=m; i++ )
                if ( ( a[i] xor tp )< a[i] )
                    res++;
        cout<<res<<endl;
        }
    return 0;
    }

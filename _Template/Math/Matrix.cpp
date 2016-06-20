const int MXN = 500+5;
template <typename T> class Matrix{
    public:
    int n,m ;
    T a[MXN][MXN];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
        n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
    T* operator[] (int i) {return a[i];}
    Matrix friend operator * (Matrix A , Matrix B){
        Matrix ans(A.n , B.m);
        for (int i = 0 ; i < A.n ; ++ i)
            for (int j = 0 ; j < A.m ; ++ j)if(A[i][j]!=0)
                for (int k = 0 ; k < B.m ; ++ k)
                    ans[i][k]=ans[i][k]+A[i][j]*B[j][k];
        return ans;
    }
};
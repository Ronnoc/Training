const int MOD = (int)1e9 + 7;

inline void add(int &a,int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
int det(int A[16][16],int n) {
    int ret = 1;
    for (int i = 0; i < n; ++ i) {
        if (A[i][i] == 0) {
            for (int j = i + 1; j < n; ++ j) {
                if (A[j][i]) {
                    for (int k = i; k < n; ++ k) {
                        std::swap(A[i][k],A[j][k]);
                    }
                    ret = -ret;
                    break;
                }
            }
            if (A[i][i] == 0) return 0;
        }
        for (int j = i + 1; j < n; ++ j) {
            int a = 1,b = 0,c = 0,d = 1;
            int x = A[i][i],y = A[j][i];
            while (y) {
                int t = x / y;
                if (t < 0) t += MOD;
                add(a,MOD - c * 1ll * t % MOD);
                add(b,MOD - d * 1ll * t % MOD);
                std::swap(a,c);
                std::swap(b,d);
                x %= y;
                std::swap(x,y);
                ret = -ret;
            }
            for (int k = 0; k < n; ++ k) {
                int q = A[i][k],w = A[j][k];
                A[i][k] = (a * 1ll * q + b * 1ll * w) % MOD;
                A[j][k] = (c * 1ll * q + d * 1ll * w) % MOD;
            }
        }
        ret = A[i][i] * 1ll * ret % MOD;
    }
    if (ret < 0) {
        ret += MOD;
    }
    return ret;
}

//**NTT数论变换**
//>EternalReality

//g是p的原根,p为素数且len|p-1&&len=2^?
//998244353=119*2^23+1
const int p = 998244353, g = 3;
const int N = 1<<18;
LL pm(LL a, int n, int m = p) {
    LL r = 1;
    for (; n; n >>= 1, a = a * a % p)
        if (n & 1) r = r * a % p;
    return r;
}
int rb(int x, int m) {
    int r = 0;
    for (; m > 1; m >>= 1, x >>= 1)r = r << 1 | (x & 1);
    return r;
}
void ntt(int *a, int len) {
    for (int i = 0, j; i < len; ++i)
        if (i < (j = rb(i, len)))swap(a[i], a[j]);
    for (int m = 1; m < len ; m <<= 1) {
        LL w = 1; int w0 = pm(g, (p - 1) / m >> 1);
        for (int k = 0; k < len; k += (m << 1), w = 1)
            for (int j = 0; j < m; ++j , w = w * w0 % p) {
                int t = w * a[k + j + m] % p;
                a[k + j + m] = (a[k + j] + p - t) % p;
                a[k + j] = (a[k + j] + t) % p;
            }
    }
}
int wa[N], wb[N];
void conv(int *a, int *b, int *c, int len) {
    rep (i, 0,len) wa[i] = a[i], wb[i] = b[i];
    ntt(wa, len);
    ntt(wb, len);
    int inv = pm(len, p - 2);
    rep (i,0, len) c[i] = wa[i] * (LL)wb[i] % p * inv % p;
    reverse(c + 1, c + len);
    ntt(c, len);
}
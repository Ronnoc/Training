//FFT
//> 验题: NEERC 2013 Eastern subregional G

const int MXN = 1 << 20;
double ax[MXN], ay[MXN];
double bx[MXN], by[MXN];
double ansx[MXN], ansy[MXN];
int revv(int x, int mask) {
	int ret = 0;
	for (int i = 0; i < mask; i++) {
		ret <<= 1;
		ret |= x & 1;
		x >>= 1;
	}
	return ret;
}
void fft(double * rl, double * ig, int n, bool sign) {
	int d = 0;
	while ((1 << d) < n) ++d;
	for (int i = 0; i < n; i++) {
		int j = revv(i, d);
		if (i < j) swap(rl[i], rl[j]), swap(ig[i], ig[j]);
	}
	for (int m = 2; m <= n; m <<= 1) {
		int mh = m >> 1;
		double _wr = cos(2 * PI / m), _wi = sin(2 * PI / m);
		if (sign) _wi *= -1.0;
		for (int i = 0; i < n; i += m) {
			double wr = 1, wi = 0;
			for (int j = i; j < mh + i; j++) {
				int k = j + mh;
				double er = rl[k] * wr - ig[k] * wi;
				double ei = rl[k] * wi + ig[k] * wr;
				double cr = rl[j], ci = ig[j];
				rl[j] += er, ig[j] += ei;
				rl[k] = cr - er, ig[k] = ci - ei;
				double qr = wr * _wr - wi * _wi;
				double qi = wr * _wi + wi * _wr;
				wr = qr, wi = qi;
			}
		}
	}
	if (sign) for (int i = 0; i < n; i++)
			rl[i] /= n, ig[i] /= n;
}
int fftmultiply(int *a, int la, int *b, int lb, LL *ans) {
	int lans = max(la, lb), ln = 0, i;
	while ((1 << ln) < lans) ++ln;
	lans = 2 << ln;
	for (i = 0; i < lans; i++)
		ax[i] = i < la ? a[i] : 0, ay[i] = 0;
	fft(ax, ay, lans, 0);
	for (i = 0; i < lans; i++)
		bx[i] = i < lb ? b[i] : 0, by[i] = 0;
	fft(bx, by, lans, 0);
	for (i = 0; i < lans; i++) {
		ansx[i] = ax[i] * bx[i] - ay[i] * by[i];
		ansy[i] = ax[i] * by[i] + ay[i] * bx[i];
	}
	fft(ansx, ansy, lans, 1);
	for (i = 0; i < lans; i++)
		ans[i] = ansx[i] + 0.5;
	return lans;
}
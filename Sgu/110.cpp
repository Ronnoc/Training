#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double eps = 1e-7;

double X0, Y0, Z0, dx, dy, dz;
int n;
double x[55], y[55], z[55], r[55];
double pow2(double t){return t*t;}
int getTime (int id, double &t) {
	double A = dx * dx + dy * dy + dz * dz;
	double B = 2.0 * dx * (X0 - x[id]) + 2.0 * dy * (Y0 - y[id]) + 2.0 * dz * (Z0 - z[id]);
	double C = pow2(X0-x[id])+pow2(Y0-y[id])+pow2(Z0-z[id]) - r[id] * r[id];
	double delta = B * B - 4.0 * A * C;
	if (delta + eps < 0) return 0;
	double t1 = (-B + sqrt (delta)) / (2.0 * A);
	double t2 = (-B - sqrt (delta)) / (2.0 * A);
	int flag = 0;
	if (t1 > eps || t2 > eps) flag = 1;
	if (!flag) return 0;
	t = fabs (t1) + fabs (t2);
	if (t1 > eps) t = min (t, t1);
	if (t2 > eps) t = min (t, t2);
//	printf (">> to %d within %lf\n", id, t);
//	printf ("IN >> %lf %lf %lf d:: %lf %lf %lf\n", X0, Y0, Z0, dx, dy, dz);
//	printf (">> A:%lf B:%lf C:%lf delta:%lf\n", A, B, C, delta);
//	printf ("  >> t1::%lf t2::%lf\n", t1, t2);
//	printf ("  >> f(t1)=%lf f(t2)=%lf\n", A * t1 * t1 + B * t1 + C, A * t2 * t2 + B * t2 + C);
	return 1;
}
void solve() {
	int Case = 11;
	vector<int>out;
	while (Case--) {
//		printf ("Dount count:: %d\n", Case);
//		printf ("before >> %lf %lf %lf d:: %lf %lf %lf\n", X0, Y0, Z0, dx, dy, dz);
		int i, id = 0;
		double t, td = 1e200;
		for (i = 1; i <= n; i++)
			if (getTime (i, t))
				if (t < td + eps)
					td = t, id = i;
		if (!id) break;
		out.push_back (id);
		double xx = X0 + td * dx;
		double yy = Y0 + td * dy;
		double zz = Z0 + td * dz;
		double rx = xx - x[id];
		double ry = yy - y[id];
		double rz = zz - z[id];
		double temp = rx * dx + ry * dy + rz * dz;
		double k = -2.0 * temp / (r[id] * r[id]);
		dx += k * rx, dy += k * ry, dz += k * rz;
		X0 = xx, Y0 = yy, Z0 = zz;
//		printf ("after  >> %lf %lf %lf d:: %lf %lf %lf\n\n", X0, Y0, Z0, dx, dy, dz);
	}
	for (int i = 0; i < min(10,(int)out.size()); i++) printf ("%d ", out[i]);
	if(out.size()>10)printf("etc.\n");
	else printf ("\n");
}
int main() {
	while (~scanf ("%d", &n)) {
		int i;
		for (i = 1; i <= n; i++) scanf ("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
		scanf ("%lf%lf%lf", &X0, &Y0, &Z0);
		scanf ("%lf%lf%lf", &dx, &dy, &dz);
		dx-=X0,dy-=Y0,dz-=Z0;
		solve();
	}
	return 0;
}

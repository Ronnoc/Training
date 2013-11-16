//Lquartz
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 21000
#define M 110000
#define eps (1e-10)

int T, n, B, Case=1;
struct node {
	double S;
	int P;
	double left;
	bool operator < (const node & b) const {
		if (this->left - b.left > eps) return true;
		return false;
	}
} task[N];
priority_queue < node > Q;
double time;

bool cmp (const node & a, const node & b) {
	if (b.S - a.S > eps) return true;
	else if (a.S - b.S > eps) return false;
	else return a.P > b.P;
}

int main() {
	while (scanf ("%d%d%d", &T, &n, &B) != EOF && T && n && B) {
		for (int i = 1; i <= T; i++) {
			scanf ("%lf%d", &task[i].S, &task[i].P);
			task[i].left = (task[i].S) * (100.0 - task[i].P) /100.0;
		}
		sort (task + 1, task + 1 + T, cmp);
////        for(int i = 1; i <= T; i++)
////            printf("xx %d %lf %d\n", i, task[i].S, task[i].P);
		time = 0;
		while (!Q.empty()) Q.pop();
		for (int i = 1; i <= n; i++)
			Q.push (task[i]);
//        for(priority_queue < node > ::iterator xxx = Q.begin(); xxx != Q.end(); xxx++)
//        {
//            printf("xx %lf %d\n", xxx->S, xxx->P);
//        }

		time = 0.0;
		for (int i = n + 1; i <= T;) {
			node temp = Q.top(), temp1;
			Q.pop();
			//printf("yy %lf %lf %d\n", temp.left, temp.S, temp.P);
			double t = temp.left / (1.0 * B / (double) (Q.size() + 1));
			task[i].left += t * (1.0 * B / (double) (Q.size() + 1));
			Q.push (task[i]);
			i++;
			while (!Q.empty()) {
				temp1 = Q.top();
				if (temp1.left - temp.left < eps) {
					Q.pop();
					if (i <= T) {
						task[i].left += t * (1.0 * B / (double) (Q.size() + 1));
						Q.push (task[i]);
						i++;
					}
				} else break;
			}
			time = t;
		}
		double sum = time * (1.0*B/ (double) n);
		//printf("sum %lf\n", sum);
		while (!Q.empty()) {
			node temp = Q.top(), temp1;
			Q.pop();
			//printf("zz %lf %lf %d\n", temp.left, temp.S, temp.P);
			double t = (temp.left - sum) / (1.0*B / (double) (Q.size() + 1));
			sum = temp.left;
			time += t;
		}
		printf ("Case %d: %.2lf\n", Case, time);
		printf ("\n");
		Case++;
	}
	return 0;
}

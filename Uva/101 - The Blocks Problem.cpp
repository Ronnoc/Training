#include<string.h>
#include<stdio.h>
#include <iostream>
using namespace std;
int r[30][30];
int h[30];
char move[] = "move", quit[] = "quit", pile[] = "pile", onto[] = "onto", over[] = "over";
int x[30], y[30], n;
void out() {
	int i, j;
	for (i = 0; i < n; i++) {
		cout<<" "<<i<<":";
		for (j = 0; j < h[i]; j++) cout<<" "<<r[i][j];
		cout<<endl;
		}
	}
void clear (int z) {
//	printf("clear(%d)",z);
	int i, j;
	int hz = h[x[z]], yz = y[z];
	for (i = yz + 1; i < hz; i++) {
		h[x[z]]--;
		int m = r[x[z]][i];
		h[m] = 1;
		r[m][0] = m;
		x[m] = m;
		y[m] = 0;
		//	printf("%d ",m);
		}
//		printf("\n");
	}
void move_onto (int p, int q) {
	clear (p);
	clear (q);
//	printf("move_onto(%d %d)\n",p,q);
	r[x[q]][h[x[q]]] = p;
	h[x[p]]--;
	h[x[q]]++;
	x[p] = x[q];
	y[p] = y[q] + 1;
	}
void pile_onto (int p, int q) {
//	printf("pile_onto(%d %d)\n",p,q);
	clear (q);
	int i;
	for (i = y[p]; i < h[x[p]]; i++) r[x[q]][h[x[q]]++] = r[x[p]][i];
	int hxp = h[x[p]];
	for (i = y[p]; i < hxp; i++) h[x[p]]--;
	for (i = 0; i < h[x[q]]; i++) {
		int z = r[x[q]][i];
		x[z] = x[q];
		y[z] = i;
		}
	}
int main() {
//	freopen("inin.txt","r",stdin);
//	freopen("outt.txt","w",stdout);
	int i, j;
	scanf ("%d", &n);
	for (i = 0; i < n; i++) x[i] = i;
	for (i = 0; i < n; i++) y[i] = 0;
	for (i = 0; i < n; i++) h[i] = 1;
	for (i = 0; i < n; i++) r[i][0] = i;
	char order[100], how[100];
	while (scanf ("%s", order) != EOF) {
		if (strcmp (order, quit) == 0) break;
		int f, t;
		scanf ("%d %s %d", &f, how, &t);
		int is_move = (strcmp (move, order) == 0) ;
		int is_onto = (strcmp (onto, how) == 0) ;
		//	printf("%d %d\n",is_move,is_onto);
		if (x[f] == x[t]) continue;
		if (is_move && is_onto) {		//move f onto t
			clear (f); clear (t);
			move_onto (f, t);
			}
		else if (is_move && !is_onto) {	//move f over t
			//	printf("2\n");
			clear (f);
			int p = r[x[t]][h[x[t]] - 1];
			move_onto (f, p);
			}
		else if (is_onto) {			//pile f onto t
			clear (t);
			pile_onto (f, t);
			}
		else {						//pile f over t
			int p = r[x[t]][h[x[t]] - 1];
			pile_onto (f, p);
			}
		//	out();
		//	for(i=0;i<n;i++)printf("%4d",i);printf("\n");
		//	for(i=0;i<n;i++)printf("%4d",x[i]);printf("\n");
		//	for(i=0;i<n;i++)printf("%4d",y[i]);printf("\n");
		}
	out();
//	return main();
	return 0;
	}

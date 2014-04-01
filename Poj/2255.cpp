#include <cstdio>
#include <cstring>
char P[33], I[33];
void tree (int pl, int pr, int il, int ir) {
	char root = P[pl];
	int i, Iroot, bk;
	for (i = il; i <= ir; i++) if (I[i] == root) Iroot = i;
	bk = pl + Iroot - il;
	if (bk > pl && Iroot > il)
		tree (pl + 1, bk, il, Iroot - 1);
	if (bk < pr && Iroot < ir)
		tree (bk + 1, pr, Iroot + 1, ir);
	printf ("%c", root);
}
int main() {
	while (scanf ("%s%s", P, I) != EOF) {
		int i, len = strlen (P), root;
		tree (0, len - 1, 0, len - 1);
		printf ("\n");
	}
	return 0;
}

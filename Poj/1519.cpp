#include <cstdio>
int f (int x) {
	if (x < 10) return x;
	int tot = 0;
	while (x) {
		tot += x % 10;
		x /= 10;
	}
	return f (tot);
}
char s[100010];
int main() {
	for (; scanf ("%s", s) != EOF;) {
		if(s[0]=='0')break;
		int n = 0;
		for (int i = 0; s[i] != 0; i++) n += s[i] - '0';
		printf ("%d\n", f (n));
	}
	return 0;
}

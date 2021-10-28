#include <bits/stdc++.h>

int bigmod(int b, int p, int m)
{
	int r = 1;

	b %= m;
	while (p) {
		if (p & 1)
			r = r * b % m;
		b = b * b % m;
		p >>= 1;
	}
	return r;
}

int first_digit(int a, int b, int l)
{
	double x, y;

	x = b * log10(a);
	x = x - floor(x);
	y = floor(pow(10, l + x));

	return (int)y;
}

int main(void)
{
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);

		printf("%d...%03d\n", first_digit(n, k, 2), bigmod(n, k, 1000));
	}
	return 0;
}

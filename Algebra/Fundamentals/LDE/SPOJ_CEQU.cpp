#include <bits/stdc++.h>

using namespace std;

int ext_gcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1, g;
	g = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}

int main(void)
{
	int t, a, b, c, x, y, g;

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &a, &b, &c);
		g = ext_gcd(a, b, x, y);
		if (c % g)
			printf("Case %d: No\n", i);
		else
			printf("Case %d: Yes\n", i);
	}
	return 0;
}

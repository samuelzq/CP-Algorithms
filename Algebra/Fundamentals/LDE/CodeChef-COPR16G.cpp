// 利用Chicken McNugget Thearem

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	long long t, a, b, g;

	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &a, &b);
		if (a > b)
			g = gcd(a, b);
		else
			g = gcd(b, a);
		if (g > 1)
			printf("%d\n", -1);
		else
			printf("%lld\n", (a - 1) * (b - 1));
	}
	return 0;
}

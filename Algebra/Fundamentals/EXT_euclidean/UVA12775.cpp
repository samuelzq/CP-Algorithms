// 统计x*a + y*b + z*c = p 所有正整数解的组数。
// 暴力解法会TLE。
// 利用扩展欧几里得算法和贝祖定理，将原式转换为x*a + y*b = p - z*c
// 设a、b的最大公约数为g, 如果p - z*c不是g的倍数，则无整数解。
// 由于扩展欧几里得算法得到的x和y可能有负值，因此需要将负数转换成
// 非负数。

#include <bits/stdc++.h>

using namespace std;
#define LL long long
LL a, b, c, p, x, y, g;
LL ans;

LL ext_gcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	LL x1, y1, d;
	d = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

LL solve(LL n)
{
	// 无法满足贝祖定理，因此无解
	if (n % g)
		return 0;

	LL t = n / g;
	LL xx, yy, k1, k2, k;
	xx = t * x;
	yy = t * y;
	k1 = a / g;
	k2 = b / g;

	// a的系数是负数，将其转换成非负数
	if (xx < 0) {
		k = -(xx / k2) + ((xx % k2) ? 1 : 0);
		xx += k * k2;
		// 需要将b转换成a，因此b的系数减少了
		yy -= k * k1;
	}

	// b的系数是负数，将其转换成非负数
	if (yy < 0) {
		k = -(yy / k1) + ((yy % k1) ? 1 : 0);
		yy += k * k1;
		// 需要将a转换成b，因此a的系数减少
		xx -= k * k2;
	}

	// 无法保证同时非负，无解
	if (xx < 0 || yy < 0)
		return 0;

	LL x1, x2;    // a的系数的上下极限，其间可能包含多少个b
	k = xx / k2;
	x1 = xx - k * k2;
	yy += k * k1;
	k = yy / k1;
	x2 = x1 + k * k2;

	return (x2 - x1) / k2 + 1;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {

		scanf("%lld %lld %lld %lld", &a, &b, &c, &p);
		g = ext_gcd(a, b, x, y);

		ans = 0;
		for (LL i = 0; i <= p / c; i++)
			ans += solve(p - i * c);

		printf("Case %d: %lld\n", i, ans);
	}
	return 0;
}

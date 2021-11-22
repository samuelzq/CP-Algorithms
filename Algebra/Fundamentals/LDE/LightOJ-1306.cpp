// 首先使用扩展欧几里得算法找到一个一般解。
// 然后在x的取值区间内找到x值的左右边界。
// 接着在y的取值区间内计算x对应的左右边界。
// x可取值的区间是以上两区间的交集。
// 需要考虑A、B、C取值为0时的情况。

#include <bits/stdc++.h>

using namespace std;
#define LL long long
LL gcd(LL a, LL b, LL& x, LL& y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	LL x1, y1;
	LL d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_any_solution(LL a, LL b, LL c, LL &x0, LL &y0, LL &g)
{
	g = gcd(abs(a), abs(b), x0, y0);
	if (c % g) {
		return false;
	}

	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)
		x0 = -x0;
	if (b < 0)
		y0 = -y0;
	return true;
}

void shift_solution(LL &x, LL &y, LL a, LL b, LL cnt)
{
	x += cnt * b;
	y -= cnt * a;
}

LL find_all_solutions(LL a, LL b, LL c,
		       LL minx, LL maxx,
		       LL miny, LL maxy)
{
	LL x, y, g;
	if (!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g;
	b /= g;

	LL sign_a = a > 0 ? +1 : -1;
	LL sign_b = b > 0 ? +1 : -1;

	shift_solution(x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	LL lx1 = x;

	shift_solution(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution(x, y, a, b, -sign_b);
	LL rx1 = x;

	shift_solution(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift_solution(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	LL lx2 = x;

	shift_solution(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift_solution(x, y, a, b, sign_a);
	LL rx2 = x;

	if (lx2 > rx2)
		swap(lx2, rx2);
	LL lx = max(lx1, lx2);
	LL rx = min(rx1, rx2);

	if (lx > rx)
		return 0;
	return (rx - lx) / abs(b) + 1;
}

int main(void)
{
	LL t;

	scanf("%lld", &t);
	for (LL i = 1; i <= t; i++) {
		LL a, b, c, x1, x2, y1, y2;
		LL ans;
		scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);
		c *= -1;
		if (a != 0 && b != 0) {
			ans = find_all_solutions(a, b, c, x1, x2, y1, y2);
		} else if (a == 0 && b != 0) {
			if (c % b)
				ans = 0;
			else {
				LL d = c / b;
				if (d < y1 || d > y2)
					ans = 0;
				else
					ans = x2 - x1 + 1;
			}
		} else if (b == 0 && a != 0) {
			if (c % a)
				ans = 0;
			else {
				LL d = c / a;
				if (d < x1 || d > x2)
					ans = 0;
				else
					ans = y2 - y1 + 1;
			}
		} else {
			if (c == 0)
				ans = (x2 - x1 + 1) * (y2 - y1 + 1);
			else
				ans = 0;
		}
		printf("Case %lld: %lld\n", i, ans);
	}
	return 0;
}

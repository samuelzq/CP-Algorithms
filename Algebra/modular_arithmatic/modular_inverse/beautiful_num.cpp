/**
 * Codeforces 300C - Beautiful Numbers
 * http://codeforces.com/problemset/problem/300/C
 * https://vjudge.net/problem/CodeForces-300C
 *
 * @File:   beautiful_num.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-28
 *
 **/
#include <bits/stdc++.h>

using namespace std;
#define LL long long

const int MOD = 1e9 + 7;

int invmod(int n)
{
	int b = MOD - 2;
	LL ret = 1;
	LL a = n;
	while (b) {
		if (b & 1)
			ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main(void)
{
	int a, b, n;

	LL tot;

	cin >> a >> b >> n;

	if (a > b)
		swap(a, b);

	tot = n * a - (b - a);

	LL sum = 0, tt = 1;

	for (int i = 0; i <= n; i++) {
		bool fg = 0;
		int tmp = tot;

		tot += (b - a);
		tmp = tot;
		while (tmp) {
			int d = tmp % 10;
			if (d != a && d != b) {
				fg = 1;
				break;
			}
			tmp /= 10;
		}

		if (i == 0) {
			tt = 1;
		} else {
			tt = tt * (n - i + 1) % MOD * invmod(i) % MOD;
		}
		if (!fg)
			sum = (sum + tt) % MOD;
	}
	cout << sum << endl;
	return 0;
}

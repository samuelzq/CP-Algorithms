/**
 * SPOJ - FACT1
 * https://www.spoj.com/problems/FACT1/
 * https://vjudge.net/problem/SPOJ-FACT1
 *
 * 使用gcc的uint128数据类型可以满足数据长度的要求。
 * 尝试法会超时。
 * 先使用Miller-Rabin算法检验输入是否为素数，对于和数使用rho算法分解。
 * c++的标准库输入输出无法时别u128，因此必须自己实现输出输入。
 *
 * @File:   spoj_fact1.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-14
 *
 **/
#include <bits/stdc++.h>

using namespace std;
using u128 = __uint128_t;

vector<pair<u128, int>> trial_division2(u128 n)
{
	vector<pair<u128, int>> factorization;
	int cnt = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt++;
	}
	if (cnt)
		factorization.push_back({2, cnt});
	for (u128 d = 3; d * d <= n; d += 2) {
		cnt = 0;
		while (n % d == 0) {
			n /= d;
			cnt++;
		}
		if (cnt)
			factorization.push_back({d, cnt});
	}
	if (n > 1)
		factorization.push_back({n, 1});
	return factorization;
}

void geti(u128 &x)
{
	char c;

	do {
		c = getchar();
	} while (c < '0' || c > '9');

	x = 0;
	do {
		x = x * 10 + (c - '0');
		c = getchar();
	} while(c >= '0' && c <= '9');
}

void outputi(u128 x)
{
	stack<char> buf;

	while (x) {
		char c;
		c = (x % 10) + '0';
		buf.push(c);
		x /= 10;
	}

	while (!buf.empty()) {
		char c = buf.top();
		putchar(c);
		buf.pop();
	}
}

u128 mult(u128 a, u128 b, u128 mod)
{
	return a * b % mod;
}

u128 f(u128 x, u128 c, u128 mod)
{
	return (mult(x, x, mod) + c) % mod;
}

u128 binarye(u128 a, u128 b, u128 mod)
{
	u128 ret = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			ret = mult(ret, a, mod);
		a = mult(a, a, mod);
		b >>= 1;
	}
	return ret;
}

int miller_rabin(u128 n)
{
	if (n < 2 || (n != 2 && n % 2 == 0))
		return 0;

	int s = 0;
	u128 d = n - 1;
	while (!(d & 1)) {
		s++;
		d >>= 1;
	}

	u128 a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
	for (int i = 0; i < 13 && a[i] < n - 1; i++) {
		u128 x = binarye(a[i], d, n);
		if (x == 1 || x == n - 1)
			continue;
		int cmp = 1;
		for (int j = 1; j < s; j++) {
			x = mult(x, x, n);
			if (x == 1)
				return 0;
			else if (x == n - 1) {
				cmp = 0;
				break;
			}
		}
		if (cmp)
			return 0;
	}
	return 1;
}

u128 egcd(u128 a, u128 b)
{
	u128 g;
	if (b < a) {
		g = a;
		a = b;
		b = a;
	}

	while (b) {
		a %= b;
		g = b;
		b = a;
		a = g;
	}
	return a;
}

u128 rho(u128 n, int x0 = 2, int c = 1) {
	u128 x = x0;
	u128 y = x0;
	u128 g = 1;
	while (g == 1) {
		x = f(x, c, n);
		y = f(y, c, n);
		y = f(y, c, n);
		if (x > y)
			g = egcd(x - y, n);
		else
			g = egcd(y - x, n);
	}
	return g;
}

map<u128, u128> facts;
void factorize(u128 n)
{
	if (n == 1)
		return;
	if (miller_rabin(n)) {
		facts[n]++;
		return;
	}

	u128 a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41};
	u128 d = n;
	for (int i = 0; i < 13 && a[i] < n - 1 && d == n; i++)
		d = rho(n, a[i]);

	if (d == n) { // 无法使用rho算法分解，使用尝试法
		while (n % 2 == 0) {
			facts[2]++;
			n /= 2;
		}
		for (int i = 3; i * i <= n; i += 2) {
			while (n % i == 0) {
				facts[i]++;
				n /= i;
			}
		}
		if (n > 1)
			facts[n]++;
	} else {
		factorize(d);
		factorize(n/d);
	}
}

int main(void)
{
	u128 t;

	while (1) {
		geti(t);
		if (!t)
			break;

		facts.clear();
		factorize(t);
		int i;
		for (auto x : facts) {
			outputi(x.first);
			putchar('^');
			outputi(x.second);
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}

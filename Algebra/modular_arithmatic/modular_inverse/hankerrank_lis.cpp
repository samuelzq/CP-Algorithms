/**
 * Hackerrank - Longest Increasing Subsequence Arrays
 * https://www.hackerrank.com/contests/world-codesprint-5/challenges/longest-increasing-subsequence-arrays
 * https://vjudge.net/problem/HackerRank-longest-increasing-subsequence-arrays
 *
 *  首先要满足存在长度为n的LIS， 如果不考虑其它位置上的元素，则有C(n, m)种安置方
 *  式。在每种安排之后，尚余m-n个空余位置。为了避免出现重复的排列方式，需要以下规
 *  范：n之后的空余可以做任意选择（n个选择）；1必须在1之后，2不能在1和2之间，
 *  3不能在2和3之间....则n之前的每个空余有n-1个可选。
 *  设LIS中n的位置是Sn，则其后有x=m-Sn个空余，之前有Sn - n = m - n - x个空余。
 *  Sn可选的位置是n到m，循环累加每种情况下的组合数即得到最终结果。
 *  除法时需要考虑逆模运算。
 *
 * @File:   hankerrank_lis.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-28
 *
 **/
#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int M = 5e5;
const int N = 1e5;
const int MOD = 1e9 + 7;

LL f[M + 1];
LL invf[M + 1];

LL bpower(LL a, LL b)
{
	LL ret = 1;
	while (b) {
		if (b & 1)
			ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

void factorials(void)
{
	LL ret = 1;

	f[0] = 1;
	for (int i = 1; i <= M; i++)
		f[i] = ret = ret * i % MOD;

	invf[M] = bpower(f[M], MOD - 2);
	for (int i = M - 1; i >= 0; i--)
		invf[i] = invf[i + 1] * (i + 1) % MOD;
}

LL ext_gcd(LL a, LL b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int g = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}

LL get_inv(int a, int m)
{
	int x, y;
	int g = ext_gcd(a, m, x, y);
	if (g != 1)
		x = -1;
	else
		x = (x % m + m) % m;
	return x;
}

LL comb(LL a, LL b)
{
	if (a < b)
		return 0;
	if (a == b)
		return 1;
	return f[a] * (invf[a - b] * invf[b] % MOD) % MOD;
}

int main(void)
{
	int p;

	factorials();

	cin >> p;
	while (p--) {
		LL m, n, nn, bb, invb;
		cin >> m >> n;
		LL ans = 0;
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		nn = 1;
		bb = bpower(n - 1, m - n);
		invb = get_inv(n - 1, MOD);
		for (int i = 0; i <= m - n; i++) {
			LL nm;
			nm = nn * bb % MOD;
			nm = nm * comb(m - i - 1, n - 1) % MOD;
			ans = (ans + nm) % MOD;
			nn = nn * n % MOD;
			bb = bb * invb % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}

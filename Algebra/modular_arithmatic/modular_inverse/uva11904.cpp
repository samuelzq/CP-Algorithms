/**
 * UVa 11904 - One Unit Machine
 * https://vjudge.net/problem/UVA-11904
 *
 * @File:   uva11904.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-27
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6;
#define LL long
LL f[N + 1];
LL k[N + 1];

void factorials(void)
{
	LL ret = 1;
	f[0] = ret;
	for (int i = 1; i <= N; i++)
		f[i] = ret = ret * i % MOD;

}

int ext_euclidean(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int g = ext_euclidean(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return g;
}

int inv_mod(int a, int m)
{
	int x, y;
	int g = ext_euclidean(a, m, x, y);
	if (g != 1) {
		//cout << "No solution!\n";
		x = -1;
	} else {
		x = (x % m + m) % m;
		//cout << x << endl;
	}
	return x;
}

LL comb(LL a, LL b)
{
	if (a < b)
		return 0;
	if (a == b)
		return 1;
	return f[a] * inv_mod(f[a - b] * f[b] % MOD, MOD) % MOD;
}

int main(void)
{
	int t;

	factorials();
	cin >> t;
	for (int i = 1; i <= t; i++) {
		LL n, sum, ans;
		cin >> n;
		ans = 1;
		sum = 0;
		while (n--) {
			int k;
			cin >> k;
			ans = ans * comb(k - 1 + sum, sum);
			sum += k;
			ans %= MOD;
		}
		cout << "Case " << i << ": " << ans << '\n';
	}
	return 0;
}

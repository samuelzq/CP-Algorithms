/**
 * SPOJ - G Force
 * https://www.spoj.com/problems/DCEPC12G/
 * https://vjudge.net/problem/SPOJ-DCEPC12G
 *
 * @File:   spoj_dcepc12g.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-25
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e7;
const int MOD = 1e9 + 7;
int phi[N + 1];
int g[N + 1];

int bin_exp(int a, int b, int mod)
{
	int ret = 1;
	a = a % mod;
	while (b) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int factorial(int a, int mod)
{
	int ret = 1;

	for (int i = 1; i <= a; i++)
		ret = ret * i % mod;

	return ret;
}

void sieve(void)
{
	for (int i = 0; i <= N; i++)
		phi[i] = i;

	g[1] = 1;
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
			cnt++;
		}
		int f = factorial(cnt - phi[i], MOD);
		g[i] = bin_exp(phi[i], f, MOD);
	}
}

int main(void)
{
	sieve();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << g[n] << '\n';
	}
	return 0;
}

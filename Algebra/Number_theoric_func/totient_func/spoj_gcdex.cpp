/**
 * SPOJ - GCDEX
 * https://www.spoj.com/problems/GCDEX/
 * https://vjudge.net/problem/SPOJ-GCDEX
 *
 * GCD队列求和的快速算法
 *
 * @File:   spoj_gcdex.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-24
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
long long ans[N + 1];
long long g[N + 1];
int phi[N + 1];

void gcd_sum(void)
{
	for (int i = 0; i <= N; i++)
		phi[i] = i;

	g[0] = 0;
	g[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
		}
		g[i] = phi[i] - i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			g[j] += i * phi[j / i];
		}
	}
	
	for (int i = 2; i <= N; i++)
		ans[i] = ans[i - 1] + g[i];
}

int main(void)
{
	int n;

	gcd_sum();
	while (cin >> n && n) {
		cout << ans[n] << '\n';
	}
	return 0;
}

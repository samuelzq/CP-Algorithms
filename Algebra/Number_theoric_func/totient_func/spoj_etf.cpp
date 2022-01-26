/**
 * SPOJ #4141 "Euler Totient Function" [Difficulty: CakeWalk]
 * https://www.spoj.com/problems/ETF/
 * https://vjudge.net/problem/SPOJ-ETF
 *
 * @File:   etf.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-19
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

int phi[N + 1];

void phi_one2n(int n)
{
	for (int i = 0; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}
int main(void)
{
	phi_one2n(N);
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << phi[n] << '\n';
	}
	return 0;
}

/**
 * SPOJ - Playing with GCD
 * https://www.spoj.com/problems/NAJPWG/
 * https://vjudge.net/problem/SPOJ-NAJPWG
 *
 * 去掉互斥的数即为满足要求的配对。
 *
 * @File:   spoj_najpwg.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-24
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int phi[N + 1];
int ans[N + 1];

void phi_one2n(void)
{
	for (int i = 0; i <= N; i++)
		phi[i] = i;

	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
		}
		ans[i] = ans[i - 1] + (i - phi[i]) ;
	}
}

int main(void)
{
	int t, n;

	phi_one2n();
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		cout << "Case " << i << ": " << ans[n] << '\n';
	}
	return 0;
}

/**
 * SPOJ - Totient Extreme
 * https://www.spoj.com/problems/DCEPCA03/
 * https://vjudge.net/problem/SPOJ-DCEPCA03
 *
 * 最终结果即为一级累加的平方。
 *
 * @File:   spoj_dcepca03.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-24
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;
long long h[N + 1];
int phi[N + 1];

void get_h(void)
{
	for (int i = 0; i <= N; i++)
		phi[i] = i;

	h[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
		}
		for (int j = 1; j <= i; j++)
			h[i] += phi[j];
		h[i] = h[i] * h[i];
	}
}

int main(void)
{
	get_h();
	int t;

	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << h[n] << '\n';
	}
	return 0;
}

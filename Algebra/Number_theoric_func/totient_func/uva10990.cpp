/**
 * UVA 10990 - Another New Function
 * https://vjudge.net/problem/UVA-10990
 *
 * 计算depthphi时需要利用DP算法以提升效率
 *
 * @File:   uva10990.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-20
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 2e6;
int phi[N + 1];
int depthphi[N + 1];

void phi_one2n(void)
{
	for (int i = 0; i <= N; i++) {
		depthphi[i] = 1;
		phi[i] = i;
	}

	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
		}
	}

	for (int i = 3; i <= N; i++) {
		depthphi[i] = depthphi[phi[i]] + 1;
	}
}

int main(void)
{
	int t;

	phi_one2n();
	cin >> t;
	while (t--) {
		int n, m;
		long long sodf = 0;
		cin >> m >> n;
		for (int i = m; i <= n; i++)
			sodf += depthphi[i];
		cout << sodf << '\n';
	}
	return 0;
}

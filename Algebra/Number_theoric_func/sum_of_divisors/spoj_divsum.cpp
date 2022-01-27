/**
 * Number of divisors
 * https://www.spoj.com/problems/DIVSUM/
 * https://vjudge.net/problem/SPOJ-DIVSUM
 *
 * @File:   spoj_divsum.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;
#define LL long long

const int N = 5e5;
LL d[N + 1];

void pre_solve(void)
{
	d[1] = 0;
	for (int i = 2; i <= N; i++) {
		d[i] += 1;
		for (int j = 2 * i; j <= N; j += i)
			d[j] += i;
	}
}

int main(void)
{
	pre_solve();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
	return 0;
}

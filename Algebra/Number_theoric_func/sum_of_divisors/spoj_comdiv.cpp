/**
 * SPOJ - COMDIV
 * https://www.spoj.com/problems/COMDIV/
 * https://vjudge.net/problem/SPOJ-COMDIV
 *
 * @File:   spoj_comdiv.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int d[N + 1];

void sieve(void)
{
	d[0] = d[1] = 1;
	for (int i = 2; i <= N; i++) {
		d[i]++;
		for (int j = i; j <= N; j += i) {
			d[j]++;
		}
	}
}

int gcd(int a, int b)
{
	if (!b)
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	int t;

	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	cin >> t;
	while (t--) {
		int a, b, g;
		cin >> a >> b;
		g = gcd(a, b);
		cout << d[g] << '\n';
	}
	return 0;
}

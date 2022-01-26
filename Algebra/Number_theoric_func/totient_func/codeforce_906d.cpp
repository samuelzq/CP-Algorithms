/**
 * Codeforces - Power Tower
 * http://codeforces.com/problemset/problem/906/D
 * https://vjudge.net/problem/CodeForces-906D
 *
 * @File:   codeforce_906d.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-26
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int phi[N + 1];
int mod;
int w[N + 1];

int getphi(int n)
{
	int ret = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			ret -= ret / i;
		}
	}
	if (n > 1)
		ret -= ret / n;
	return ret;
}

#define MOD(x, y)  (x) < (y) ? (x) : ((x) % (y) + (y))
int bpower(int a, int b, int m)
{
	int ret = 1;

	while (b) {
		if (b & 1)
			ret = MOD(1LL * ret * a,  m);
		a = MOD(1LL * a * a, m);
		b >>= 1;
	}
	return ret;
}

int euler_power(int l, int r, int m)
{
	if (l == r)
		return w[l] >= phi[m] ? MOD(w[l], phi[m]) : w[l];

	if (phi[m] == 1)
		return 1;

	return bpower(w[l], euler_power(l + 1, r, m + 1), phi[m]);

}

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	int cnt, p;
	cnt = 1;
	p = phi[cnt] = m;// = getphi(m);

	while (p > 1)
		phi[cnt] = p = getphi(phi[cnt++]);

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << euler_power(l, r, 1) % m << '\n';
	}
	return 0;
}

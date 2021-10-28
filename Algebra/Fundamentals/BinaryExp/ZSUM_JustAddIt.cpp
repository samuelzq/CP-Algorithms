// ans = 2(n-1)^k + n^k + 2(n-1)^(n-1) + n^n

#include <bits/stdc++.h>

using namespace std;

const int mod = 10000007;

long long ep(long long b, int p)
{
	long long r = 1;
	long long a = b;

	while (p) {
		if (p & 1)
			r = r * a % mod;
		a = a * a % mod;
		p >>= 1;
	}
	return r;
}

int main(void)
{
	int n, k;
	long long ans;

	while (scanf("%d %d", &n, &k) != EOF && n && k) {
		int t = min(k, n - 1);
		long long b, a;

		a = ep(n - 1, t);
		b = ep(n, t);
		ans = ((2 * a) % mod) * ((ep(n - 1, k - t) + ep(n - 1, n - 1 - t)) % mod) % mod;
		ans = (ans + b * ((ep(n, k - t) + ep(n, n - t)) % mod) % mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}

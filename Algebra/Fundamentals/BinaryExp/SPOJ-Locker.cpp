#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;

long long pp(long long a, long long b)
{
	long long n, ans;
	n = a, ans = 1;
	while (b > 0) {
		if (b & 1)
			ans = ans * n % mod;
		n = n * n % mod;
		b >>= 1;
	}
	return ans;
}

int main(void)
{
	int t;

	scanf("%d", &t);

	while (t--) {
		long long n;
		long long  rem, ans;

		scanf("%lld", &n);
		rem = n % 3;

		if (n < 4)
			ans = n;
		else if (rem == 1)
			ans = pp(3, (n - 4) / 3) * 4 % mod;
		else if (rem == 2)
			ans = pp(3, (n - 2) / 3) * 2 % mod;
		else
			ans = pp(3, n / 3);
		printf("%lld\n", ans);
	}
	return 0;
}

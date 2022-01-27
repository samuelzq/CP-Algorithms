/**
 * SPOJ - DIVSUM2
 * https://www.spoj.com/problems/DIVSUM2/
 * https://vjudge.net/problem/SPOJ-DIVSUM2
 *
 * @File:   spoj_divsum2.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-27
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 11e7;
#define LL long long

vector<bool> is_prime(N + 1, true);
vector<int> primes;

void sieve(void)
{
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (is_prime[i] == true) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = false;
		}
	}

	primes.emplace_back(2);
	for (int i = 3; i <= N; i += 2) {
		if (is_prime[i] == true)
			primes.emplace_back(i);
	}
}

LL power(LL a, LL b)
{
	LL ret = 1;
	while (b) {
		if (b & 1)
			ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

LL d(LL n)
{
	LL ret = 1;

	for (LL i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
		int cnt = 0;

		if (n % primes[i] == 0) {
			while (n % primes[i] == 0) {
				cnt++;
				n /= primes[i];
			}
			//cout << primes[i] << " " << cnt << " " << ret << endl;
			ret *= (power(primes[i], cnt + 1) - 1) / (primes[i] - 1);
		}
	}

	if (n > 1)
		ret *= 1LL + n;
	return ret;
}

int main(void)
{
	int t;

	sieve();
	cin >> t;
	while (t--) {
		LL n;
		cin >> n;
		cout << d(n) - n << '\n';
	}
	return 0;
}

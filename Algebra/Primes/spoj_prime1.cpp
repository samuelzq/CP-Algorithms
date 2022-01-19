/**
 * SPOJ - Prime Generator
 * https://www.spoj.com/problems/PRIME1/
 * https://vjudge.net/problem/SPOJ-PRIME1
 *
 * 使用分段筛法直接输出。
 *
 * @File:   spoj_prime1.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-07
 *
 **/

#include <bits/stdc++.h>

using namespace std;

#define LL long long

void segment_sieve(int l, int r)
{
	LL lim = sqrt(r) + 1;

	vector <bool> mark(lim, false);
	vector <LL> primes;

	for (LL i = 2; i <= lim; i++) {
		if (!mark[i]) {
			primes.emplace_back(i);
			for (LL j = i * i; j <= lim; j += i)
				mark[j] = true;
		}
	}

	vector<char> is_prime(r - l + 1, true);
	for (auto i : primes) {
		for (LL j = max(i * i, (l - 1 + i) / i * i); j <= r; j += i)
			is_prime[j - l] = false;
	}
	if (l == 1)
		is_prime[0] = false;

	for (int i = 0; i < is_prime.size(); i++) {
		if (is_prime[i])
			cout << i + l << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;
	while (t--) {
		int l, r;

		cin >> l >> r;
		segment_sieve(l, r);
		cout << '\n';
	}
	return 0;
}

/**
 * SPOJ - Bazinga!
 * https://www.spoj.com/problems/DCEPC505/
 * https://vjudge.net/problem/SPOJ-DCEPC505
 *
 * 先筛出所有满足条件的数。
 *
 * @File:   Bazinga.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-31
 *
 **/

#include <bits/stdc++.h>

using namespace std;
const int N = 11000000;
vector<bool> is_primes(N + 1, true);
vector<long long> primes;
vector<long long> fpd(N + 1);
vector<long long> bazinga;

void sieve(void)
{
	is_primes[0] = is_primes[1] = false;

	for (int i = 2; i <= N; i++)
		fpd[i] = i;
	fpd[1] = 1;

	for (int i = 2; i * i <= N; i++) {
		if (is_primes[i]) {
			for (int j = i * i; j <= N; j += i) {
				if (fpd[j] == j)
					fpd[j] = i;
				is_primes[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (is_primes[i])
			primes.push_back(i);
	}
}

bool check(long long n)
{
	long long d = n / fpd[n];
	if (is_primes[n] || !is_primes[d] || fpd[n] == d)
		return false;

	return true;
}

int main(void)
{
	int d, cnt = 0;

	sieve();
	d = 4;
	while (cnt <= 2000000) {
		if (check(d)) {
			bazinga.push_back(d);
			cnt++;
		}
		d++;
	}
	int t, k;
	cin >> t;
	while (t--) {
		cin >> k;
		cout << bazinga[k - 1] << '\n';
	}
	return 0;
}

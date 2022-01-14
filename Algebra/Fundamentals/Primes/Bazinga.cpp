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
const int N = 1000000006;
vector<bool> is_primes(N, true);
vector<long long> primes;
vector<long long> bazinga;

void sieve(void)
{
	is_primes[0] = is_primes[1] = false;

	for (int i = 2; i * i <= N; i++) {
		if (is_primes[i]) {
			for (int j = i * i; j <= N; j += i)
				is_primes[j] = false;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (is_primes[i])
			primes.push_back(i);
	}
}

void all_bazinga(void)
{
	long long p;

	for (<vector<long long>::iterator it = primes.begin(); it != primes.end(); it++) {
		for (<vector<long long>::iterator iit = primes.begin(); iit != primes.end(); iit++) {
	}
}
bool check(long long n)
{
	int cnt = 0;
	long long d = 2;
	long long tmp = n;

	while (tmp >= d) {
		if (tmp % d) {
			d++;
			continue;
		}
		cnt++;
		tmp /= d;
	}
	return cnt == 2 && tmp == 1;
}

int main(void)
{
	int d, cnt = 0;

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
		cout << bazinga[k] << '\n';
	}
	return 0;
}

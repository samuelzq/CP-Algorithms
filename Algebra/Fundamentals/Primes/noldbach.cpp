/**
 * Codeforces - Nodbach Problem
 * https://codeforces.com/problemset/problem/17/A
 * https://vjudge.net/problem/CodeForces-17A
 *
 * 筛出区间内的质数，然后暴力枚举。
 *
 * @File:   noldbach.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-11
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

char is_prime[N];
int primes[N];
int primes_cnt = 0;

void sieve(void)
{
	is_prime[0] = is_prime[1] = 1;

	for (int i = 2; i * i <= N; i++) {
		if (is_prime[i] == 0) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = 1;
		}
	}

	primes[0] = 2;
	primes_cnt = 1;
	for (int i = 3; i <= N; i += 2) {
		if (is_prime[i] == 0) {
			primes[primes_cnt++] = i;
		}
	}
}

int main(void)
{
	int n, k;

	sieve();
	cin>> n >> k;
	int cnt = 0;

	for (int i = 0; primes[i] <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (primes[j + 1] + primes[j] == primes[i] - 1) {
				//printf("%d + %d = %d\n", primes[j + 1], primes[j], primes[i]-1);
				cnt++;
			}
		}
	}
	if (cnt >= k)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

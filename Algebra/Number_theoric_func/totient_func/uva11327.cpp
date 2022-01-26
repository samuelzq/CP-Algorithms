/**
 * UVA #11327 "Enumerating Rational Numbers" [Difficulty: Medium]
 * https://vjudge.net/problem/UVA-11327
 *
 * 先算出每个正整数的phi。然后利用它们找到分母（输入虽然很大，但它是累加和，
 * 分母不会大于200000），然后通过暴力枚举找到符合要求的分子。
 *
 * @File:   uva11327.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-20
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int primes[N];
int prime_num = 0;
int phi[N + 5];

void sieve(void)
{
	for (int i = 0; i <= N; i++)
		phi[i] = i;

	primes[0] = 1;
	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			primes[++prime_num] = i;
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}

int gcd(int a, int b)
{
	return b ? gcd (b, a % b) : a;
}

int main(void)
{
	long long n;

	sieve();
	while (cin >> n && n) {

		if (n == 1) {
			cout << "0/1\n";
			continue;
		}
		int i;
		n--;

		for (i = 0; i <= N; i++) {
			if (phi[i] >= n)
				break;
			n -= phi[i];
		}
		int j = 0, k = 0;
		while (j < n) {
			k += 1;
			if (gcd(i, k) == 1)
				j++;
		}
		cout << k << '/' << i << '\n';
	}
	return 0;
}

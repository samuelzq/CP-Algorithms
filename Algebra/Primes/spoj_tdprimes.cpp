/**
 * Printing some primes SPOJ - TDPRIMES
 * https://www.spoj.com/problems/TDPRIMES/
 * https://vjudge.net/problem/SPOJ-TDPRIMES
 *
 * 筛出所有的质数，每隔100输出一个
 *
 * @File:   spoj_tdprimes.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-23
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 100000001;
vector<bool> is_prime(N+1, true);

void check_primes(void)
{
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = false;
		}
	}
}

int main(void)
{
	int idx = 0;
	check_primes();
	for (int i = 2; i < N; i++) {
		if (is_prime[i] == true) {
			if (!(idx % 100))
				printf("%d\n", i);
			idx++;
		}
	}
	return 0;
}

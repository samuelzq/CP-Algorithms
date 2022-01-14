/**
 * UVA 11353 - A Different Kind of Sorting
 * https://vjudge.net/problem/UVA-11353
 *
 * 在埃氏筛法基础上进行。
 * 使用DP计算每个合数的因数个数：
 * 1、质数的因数只有1个；
 * 2、如果一个合数c的最小质因子为p1，c = p1*c2。
 *    则其因数的个数等于c2质因数的个数加1。
 *
 * @File:   uva11353.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-10
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;
struct prime{
	int idx;
	int cnt;
} primes[N + 0xAC] = {0, };

int is_primes[N + 0xAC] = {0};

bool cmp(struct prime p1, struct prime p2)
{
	if (p1.cnt == p2.cnt)
		return p1.idx < p2.idx;
	return p1.cnt < p2.cnt;
}
void sieve(void)
{
	for (int i = 2; i * i <= N; i++) {
		if (is_primes[i] == 0) {
			for (int j = i * 2; j <= N; j += i)
				is_primes[j] = i;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (is_primes[i])
			is_primes[i] = is_primes[i / is_primes[i]] + 1;
		else
			is_primes[i] = 1;
		primes[i].idx = i;
		primes[i].cnt = is_primes[i];

	}
	primes[1].cnt = 1;
	primes[1].idx = 1;

}

int main(void)
{
	int k = 1;
	int n;

	sieve();
	sort(primes, primes + N + 1, cmp);
#if 0
	for (int i = 1; i < N; i++) {
		printf("%8d %8d\n", primes[i].idx, primes[i].cnt);
	}
#endif
	while (scanf("%d", &n) && n) {
		printf("Case %d: %d\n", k++, primes[n].idx);
	}
	return 0;
}

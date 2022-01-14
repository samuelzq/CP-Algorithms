/**
 * SPOJ - Binary Sequence of Prime Numbers
 * https://www.spoj.com/problems/BSPRIME/
 * https://vjudge.net/problem/SPOJ-BSPRIME
 *
 * @File:   spoj_bsprime.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-06
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const long long Limit = 1.1e8;
vector <bool> is_prime(Limit + 1);
int prime[5899179], numPrime;
const int L1D_CACHE_SIZE = 37768;
void simple_sieve(long long limit, vector<int> &primes)
{
	is_prime[0] = is_prime[1] = true;

	primes.emplace_back(2);
	for (long long i = 3; i <= Limit; i += 2) {
		if (!is_prime[i]) {
			for (long long j = i * i; j <= Limit; j += i)
				is_prime[j] = 1;
			primes.emplace_back(i);
		}
	}
}

vector<int> primes;
vector<bool> mark(5899179 + 1, true);
inline void segmented_sieve(int n, int segment_size = L1D_CACHE_SIZE)
{
	int lim = sqrt(n) + 1;
	int cnt = 0;

	primes.reserve(lim);
	simple_sieve(lim, primes);

	int low = lim;
	int high = low + segment_size;

	while (low < n) {
		if (high >= n)
			high = n;


		for (int i = 0; i < primes.size(); i++) {
			int p = primes[i];
			int lo = (low + p - 1) / p * p;

			for (int j = lo; j < high; j += p)
				mark[j - low] = false;
		}

		for (int i = low; i < high; i++) {
			if (mark[i - low] == true) {
				prime[cnt++] = i;
			}
			else
				mark[i - low] = true;
		}
		low += segment_size;
		high += segment_size;
	}
	numPrime = cnt;
}

int main(void)
{
	int t, n;
	clock_t tstart, tend;
	tstart = clock();
	simple_sieve(Limit, primes);
	tend = clock();
	cout << "Run time: "<<(double)(tend - tstart) / CLOCKS_PER_SEC<<"S"<<endl;
	return 0;
}

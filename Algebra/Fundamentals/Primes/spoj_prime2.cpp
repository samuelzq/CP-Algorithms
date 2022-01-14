/**
 * SPOJ - Binary Sequence of Prime Numbers
 * https://www.spoj.com/problems/BSPRIME/
 * https://vjudge.net/problem/SPOJ-BSPRIME
 *
 * @File:   spoj_prime2.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-06
 *
 **/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <cstdio>
#include <cstring>


#define LL long long
const int Limit = 101865020;
const int L1D_CACHE_SIZE = 37768;
const int N = 1.5e8 + 7;
unsigned prime[5899179],numPrime;
unsigned binary[150000007];
using namespace std;

void simple_sieve(LL lim, vector<bool> &is_prime)
{
	for (LL i = 2; i * i <= lim; i++) {
		if (is_prime[i]) {
			for (LL j = i * i; j <= lim; j += i)
				is_prime[j] = 0;
		}
	}
}

inline void segmented_sieve(int limit, int segment_size = L1D_CACHE_SIZE)
{
	int sqrt = (int)std::sqrt(limit);
	int count = (limit < 2) ? 0 : 1;
	int s = 2;
	int n = 3;

	vector<char> segment(segment_size);

	vector<bool> is_prime(sqrt + 1, 1);
	simple_sieve(sqrt + 1, is_prime);

	vector<unsigned> primes;
	vector<unsigned> next;
	int p = 2;
	for (unsigned low = 0; low <= limit; low += segment_size) {
		fill(segment.begin(), segment.end(), 1);

		int high = min(low + segment_size - 1, (unsigned)limit);
		for (; s * s <= high; s++) {
			if (is_prime[s]) {
				primes.push_back((int) s);
				next.push_back((int)(s * s - low));
			}
		}

		for (size_t i = 1; i < primes.size(); i++) {
			int k = primes[i] * 2;
			int j = next[i];
			for (; j < segment_size; j += k)
				segment[j] = 0;
			next[i] = j - segment_size;
		}
		prime[1] = 2;
		prime[2] = 3;
		for (; n <= high; n += 2) {
			if (segment[n - low])
				prime[p++] = n;
		}
	}
	numPrime = p;
}

void compute()
{
	int b = 0, ind = 1;

	for (int i = 1; i < numPrime; i++) {
		int j, flag = 0;
		int num;
		num = prime[i];
		for (j=0; j < 32; j++) {
			if (num < 0) {
				b += 1;
				binary[ind++] = b;
				flag = 1;
			} else if (flag) {
				binary[ind++] = b;
			}
			num =  num << 1;
		}
	}
}

int main()
{
	unsigned tc,n;
	segmented_sieve(Limit, L1D_CACHE_SIZE);

	compute();
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		cout << binary[n] << '\n';
	}
}

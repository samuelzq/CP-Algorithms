/**
 * SPOJ - Primal Fear
 * https://www.spoj.com/problems/VECTAR8/
 * https://vjudge.net/problem/SPOJ-VECTAR8
 *
 * 首先生成Primal Fear列表，然后利用二分法查找左边界
 *
 * @File:   SPOJ_VECTAR8.cpp
 * @File:   spoj_vectar8.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-23
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;
vector<bool> is_primes(N, true);
vector<int> primal_fear;

void sieve_p(void)
{
	is_primes[0] = is_primes[1] = false;

	for (int i = 2; i * i < N; i++) {
		if (is_primes[i]) {
			for (int j = i * i; j < N; j+= i)
				is_primes[j] = false;
		}
	}
}

bool check(int n)
{
	int d = 0, i = 1;
	vector<int> a;
	while (n) {
		int b;
		b = n % 10;
		if (b == 0)
			return false;

		d = d + b * i;
		a.push_back(d);
		n /= 10;
		i *= 10;
	}

	for (int i = 0; i < a.size(); i++) {
		if (!is_primes[a[i]])
			return false;
	}
	return true;
}

int main(void)
{
	int t;

	sieve_p();

	primal_fear.push_back(2);
	int r = 3;
	while (r < N) {
		if (is_primes[r] && check(r))
		primal_fear.push_back(r);
		r += 2;
	}

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (n < 2) {
			cout << "0\n";
			continue;
		}
		int l = 0, r = primal_fear.size() - 1, mid;

		while (l < r) {
			mid = (l + r + 1) / 2;
			if (primal_fear[mid] > n)
				r = mid - 1;
			else
				l = mid;
		}
		cout << l + 1 << '\n';
	}
	return 0;
}

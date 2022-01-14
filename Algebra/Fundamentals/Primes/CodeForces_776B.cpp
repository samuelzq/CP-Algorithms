/**
 * Sherlock and his girlfriend CodeForces - 776B
 * http://codeforces.com/contest/776/problem/B
 * https://vjudge.net/problem/CodeForces-776B
 *
 * 所有质数使用一种颜色，所有和数使用另一种颜色。
 *
 * @File:   CodeForces_776B.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-29
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector<bool> is_primes(N, true);

void sieve(int n)
{
	is_primes[0] = is_primes[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_primes[i] == true) {
			for (int j = i * i; j <= n; j += i)
				is_primes[j] = false;
		}
	}
}

int main(void)
{
	int n;

	cin >> n;

	if (n <= 2) {
		cout << "1\n";
		cout << "1";
		for (int i = 1; i < n; i++)
			cout << " 1";
		cout << '\n';
	} else {
		sieve(n + 1);
		cout << "2\n";
		cout << "1";
		for (int i = 2; i <= n; i++) {
			if (is_primes[i + 1])
				cout << " 1";
			else
				cout << " 2";
		}
		cout << '\n';
	}
	return 0;
}

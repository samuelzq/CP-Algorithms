/**
 * Project Euler - Prime pair connection
 * https://www.hackerrank.com/contests/projecteuler/challenges/euler134/problem
 * https://vjudge.net/problem/HackerRank-euler134
 *
 * 本题的题意找到最小的可以被p2整除的x*tens(p1)+p1 。tens(N)表示大于N的最小的10的
 * 幂。暴力解法能够得到正确结果，但OJ会超时。
 *
 * 设     x*tens(p1) + p1 = y*p2，
 * 转化成 x*tens(p1) - y*p2 = -p1。
 * 两边同时加上p2，x*tens(p1) - (y-1)p2 = p2-p1。
 * 令tens(p1)=a，p2=b，p2-p1=c。
 * 由于a和b互质，因此可以利用扩展欧几里德算法快速求得x。
 * 另外需要考虑的是，结果是一个大数，需要实现大数加法。
 *
 * @File:   HackerRank_euler134.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-04
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;
int cnt = 0;
long long primes[N];
vector<char> isPrime(N);
int ans[100];

long long ext_gcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	long long x1, y1;
	long long d = ext_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void sieve()
{
	// generate all primes up to sqrt(R)
	for (long long i = 3; i * i <= N; i += 2) {
		if (!isPrime[i]) {
			for (long long j = i * i; j <= N; j += i)
				isPrime[j] = true;
		}
	}

	cnt = 0;
	primes[cnt++] = 2;
	for (int i = 3; i <= N; i += 2) {
		if (isPrime[i] == false)
			primes[cnt++] = i;
	}
}

int main(void)
{
	int t;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	cin >> t;
	while (t--) {
		long long l, r, sum, prv;
		cin >> l >> r;

		for (int i = 0; i <= r - l + 1000 ; i++)
			isPrime[i] = true;

		for (long long k = 0; k < cnt; k++) {
			long long i = primes[k];
			for (long long j = max(i * i, (l + i - 1) / i * i); j <= r + 500; j += i) {
				isPrime[j - l] = false;
			}
		}

		prv = sum = 0;
		for (int i = 0; i < 100; i++)
			ans[i] = 0;
		for (int i = l; i < r + 1000; i++) {
			if (prv > r)
				break;

			if (isPrime[i - l] == false)
				continue;

			if (prv == 0) {
				prv = i;
				continue;
			}

			long long t = prv;
			int d = 1, b = 0;
			while (t) {
				b++;
				t /= 10;
				d *= 10;
			}

			long long x, y;
			ext_gcd(d, i, x, y);
			x = x * (i - prv) % i;
			if (x < 0)
				x += i;
			//cout << x * d + prv << '\n';
			long long tmp = x * d + prv;
			for (long long k = 0, c = 0; k < 40; k++) {
				ans[k] += (tmp % 10 + c);
				c = ans[k] / 10;
				ans[k] %= 10;
				tmp /= 10;
			}
			

			//cout << prv << ' ' << i + l << ' ' << t << '\n';
			prv = i;
		}
		//cout << sum << '\n';
		int i = 40;
		while (ans[i] == 0)
			i--;
		while (i >= 0)
			cout << ans[i--];
		cout << '\n';
	}
	return 0;
}

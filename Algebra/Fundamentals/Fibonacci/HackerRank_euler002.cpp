/**
* Project Euler - Even Fibonacci numbers
* https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
* https://vjudge.net/problem/HackerRank-euler002
*
* 本题使用枚举法穷举。
# @File:   HackerRank_euler002.cpp
* @Author: Lao Zhang <samuelzhang77@yahoo.com>
# @Date:   2021-12-20
#
**/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		long long n;
		long long a, b, c, sum;
		a = 1, b = 1, c = a + b;
		cin >> n;
		sum = 0;
		while (c <= n) {
			if (c % 2 == 0)
				sum += c;
			a = b;
			b = c;
			c = a + b;
		}
		cout << sum << '\n';
	}
	return 0;
}

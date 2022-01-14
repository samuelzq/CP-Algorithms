/**
 * Almost Prime
 * http://codeforces.com/contest/26/problem/A
 * https://vjudge.net/problem/CodeForces-26A
 *
 * 采用埃拉托色艾尼筛法，从2开始累除。Almost Prime只能够被两个不同的数整除。
 *
 * @File:   Almost_primes.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-29
 *
 **/

#include <bits/stdc++.h>

using namespace std;

int check(int n)
{
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		if (n % i == 0)
			cnt++;
		while (n % i == 0)
			n /= i;
		if (n == 0)
			break;
	}
	return cnt;
}

int main(void)
{
	int cnt, n;
	cin >> n;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check(i) == 2)
			cnt++;
	}
	cout << cnt << '\n';

	return 0;
}

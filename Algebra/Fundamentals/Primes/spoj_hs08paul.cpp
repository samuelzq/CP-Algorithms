/**
 * SPOJ - A Conjecture of Paul Erdos
 * https://www.spoj.com/problems/HS08PAUL/
 * https://vjudge.net/problem/SPOJ-HS08PAUL
 *
 * 首先建立满足x^2+y^4形式的质数表。
 * 然后，针对每个输入使用二分法查表，找到左边边界。
 *
 * @File:   spoj_hs08paul.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2021-12-23
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 10000007;
vector<bool> is_prime(N, true);
vector<int> x2y4;

void check_primes(void)
{
	int d = sqrt(N) + 1;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= d; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = false;
		}
	}
}

int main(void)
{
	int t;

	check_primes();
	for (int i = 1; i <= N; i++) {
		int x = i * i;
		if (x > N)
			break;
		for (int j = 1; j <= N; j++) {
			int y = j * j * j * j;
			if ((x + y) > N)
				break;
			if (is_prime[x + y])
				x2y4.push_back(x + y);
		}
	}

	// 去重
	sort(x2y4.begin(), x2y4.end());
	vector<int>::iterator it;
	it = unique(x2y4.begin(), x2y4.end());
	x2y4.resize(distance(x2y4.begin(), it));

	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		if (n == 1) {
			printf("%d\n", 0);
		} else {
			int l = 0, r = x2y4.size() - 1, mid;

			while (l < r) {
				mid = (l + r + 1) / 2;

				if (x2y4[mid] > n)
					r = mid - 1;
				else
					l = mid;
			}
			printf("%d\n", l + 1);
		}
	}
	return 0;
}

/**
 * SPOJ - LCM Sum
 * https://www.spoj.com/problems/LCMSUM/
 * https://vjudge.net/problem/SPOJ-LCMSUM
 *
 * 利用的数论知识：lcm(i, n) == lcm(n-i,n) (0 < i < n)   lcm(n,n) = n
 * S = lcm(1,n) + lcm(2,n) + lcm(3,n) + ... + lcm(n-1,n) + lcm(n,n)
 * S - n = lcm(1,n) + lcm(2,n) + lcm(3,n) + ... + lcm(n-1,n)
 * S - n = lcm(n-1,n) + lcm(n-2,n) + lcm(n-3,n) + ... + lcm(1,n)
 * 2 * (S - n) = lcm(1,n) +  lcm(n-1,n) + lcm(2,n) + lcm(n-2,n) + ... + lcm(1,n) + lcm(n-1,n)
 * lcm(i,n) + lcm(n-i,n) = (i*n + (n-i)*n) / gcd(i,n) = n^2 / gcd(i,n)
 * 2 * (S - n) = n * ∑(n / gcd(i, n))  (1 <= i <= n)  存在1 < j < i < n；gcd(i,n) == gcd(j,n)
 * 2 * (S - n) = n * ∑(cnt * (n / d))   d为一个公因数，cnt为共享该因数的数的个数。
 * 因此，现在问题转换成求每个d对应的cnt，而cnt=phi(n/d).
 *
 * @File:   spoj_lcmsum.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-21
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6;
long long sum[N + 1];
int phi[N + 1];

void get_sum(void)
{
	for (int i = 0; i <= N; i++)
		phi[i] = i;

	for (int i = 2; i <= N; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i)
				phi[j] -= phi[j] / i;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i)
			sum[j] += (long long)i * (long long)phi[i];
		sum[i] = (sum[i] + 1) * (long long)i / 2;
	}
}

int main(void)
{
	int t;

	get_sum();
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sum[n] << '\n';
	}
	return 0;
}

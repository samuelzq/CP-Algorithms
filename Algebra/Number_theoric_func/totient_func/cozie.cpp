/**
 * Codechef - Golu and Sweetness
 * https://www.codechef.com/problems/COZIE
 * https://vjudge.net/problem/CodeChef-COZIE
 *
 * phi值都是偶数，而偶数中只有2是质数。所有正整数中只有3、4、6的phi值是2。
 *
 * @File:   cozie.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-21
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int a[N + 1];

int main(void)
{
	int n, q;
	cin >> n >> q;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		if (b == 3 || b == 4 || b == 6)
			a[i] = 1;
		a[i] += a[i - 1];
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l - 1] << '\n';
	}
	return 0;
}

/**
 * SGU #249 "Matrix"      [Difficulty: medium]
 * https://codeforces.com/problemsets/acmsguru/problem/99999/249
 * https://vjudge.net/problem/SGU-249
 *
 * 以S型输出Gray code
 *
 * @File:   matrix.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-08
 *
 **/
#include <bits/stdc++.h>

using namespace std;

int bpower(int a, int b)
{
	int r = 1;
	while (b) {
		if (b & 1)
			r *= a;
		a *= a;
		b >>= 1;
	}
	return r;
}

int g (int n)
{
	return n ^ (n >> 1);
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	n = bpower(2, n);
	m = bpower(2, m);

	for (int i = 0; i < n; i++) {
		int t, j = 0;
		if ((i & 1) == 0) {
			for (j = 0; j < m - 1; j++) {
				t = i * m + j;
				cout << g(t) << ' ';
			}
			t++;
			cout << g(t) << '\n';
		} else {
			for (j = m - 1; j > 0; j--) {
				t = i * m + j;
				cout << g(t) << ' ';
			}
			t--;
			cout << g(t) << '\n';
		}
	}
	return 0;
}

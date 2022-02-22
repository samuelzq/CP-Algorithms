/**
 * Codeforces - Maximum of Maximums of Minimums
 * http://codeforces.com/problemset/problem/872/B
 * https://vjudge.net/problem/CodeForces-872B
 *
 * @File:   codeforce_872B.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-21
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int K = 16;
long long a[N + 5];

int main(void)
{
	int n, k, mx, mn, ans;

	cin >> n >> k;

	mx = -0x7fffffff;
	mn = 0x7fffffff;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > mx)
			mx = tmp;

		if (tmp < mn)
			mn = tmp;

		a[i] = tmp;
	}

	if (k == 1)
		ans = mn;
	else if (k == 2) {
		ans = max(a[0], a[n - 1]);
	} else
		ans = mx;
	cout << ans << '\n';
	return 0;
}

/**
 * Codechef - SEAD
 * https://www.codechef.com/problems/SEAD
 * https://vjudge.net/problem/CodeChef-SEAD
 *
 * @File:   codechef_sead.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-18
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
const int LOGN = 17;

int st[LOGN][MAXN + 5];
int arr[MAXN + 5];
int L[MAXN + 5];

void init(int n)
{
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	arr[n + 1] = arr[n];
	for (int i = 1; i <= n; i++)
		st[0][i] = arr[i + 1] - arr[i];

	for (int i = 2; i <= n; i++)
		L[i] = L[i >> 1] + 1;
	int k = L[n - 1];

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int max_in_range(int l, int r)
{
	int j = L[r - l];
	return max(st[j][l], st[j][r - (1 << j)]);
}

int main(void)
{
	int n, m;

	cin >> n;
	init(n);
	cin >> m;
	while (m--) {
		int t, d, p;
		cin >> t >> d;

		p = upper_bound(arr + 1, arr + n + 1, t) - arr - 1;
		int l, r, mid, ans = p;
		l = 1;
		r = p;

		while (l <= r) {
			mid = l + (r - l) / 2;
			int det = max_in_range(mid, p);
			if (d >= det) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}

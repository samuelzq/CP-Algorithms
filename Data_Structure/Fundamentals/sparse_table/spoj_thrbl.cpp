/**
 * SPOJ - THRBL
 * https://www.spoj.com/problems/THRBL/
 * https://vjudge.net/problem/SPOJ-THRBL
 *
 * @File:   spoj_thrbl.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-17
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4;
const int LOGN = 16;

int st[LOGN][MAXN + 5];
int arr[MAXN + 5];

int getlog(int n)
{
	int r = 0;

	for (int i = 31; i >= 0; i--) {
		if (n & (1 << i))
			break;
		r++;
	}
	return 31 - r;
}

void init(int n)
{
	int k = getlog(n);

	for (int i = 1; i <= n; i++)
		st[0][i] = arr[i];

	for (int j = 1; j <= k; j++)
		for (int i = 1; i + (1 << j) <= n; i++)
			st[j][i] = max(st[j-1][i], st[j - 1][i + (1 << (j - 1))]);
}

int max_in_range(int l, int r)
{
	int q = getlog(r - l + 1);

	return max(st[q][l], st[q][r - (1 << q) + 1]);
}

int main(void)
{
	int n, q, ans;

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(n);
	ans = 0;
	while (q--) {
		int a, b, h;
		cin >> a >> b;

		if (a == b)
			ans++;
		else if (a < b)
			h = max_in_range(a, b - 1);
		else
			h = max_in_range(b + 1, a);
		if (h == arr[a])
			ans++;
	}
	cout << ans << '\n';
	return 0;
}

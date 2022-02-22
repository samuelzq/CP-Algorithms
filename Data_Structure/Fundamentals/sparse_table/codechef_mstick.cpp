/**
 * Codechef - MSTICK
 * https://www.codechef.com/problems/MSTICK
 * https://vjudge.net/problem/CodeChef-MSTICK
 *
 * 被点燃的区间，最短火柴棒燃烧完毕之后，其余火柴棒燃烧速度加倍。
 * 区间外火柴棒开始燃烧。
 *
 * 需要记录区间最小和最大值。
 *
 * @File:   codechef_mstick.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-17
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int LOGN = 17;

int st[LOGN][MAXN + 5];
int st2[LOGN][MAXN + 5];
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

int init(int n)
{
	int k = getlog(n);

	for (int i = 0; i < n; i++) {
		st[0][i] = arr[i];
		st2[0][i] = arr[i];
	}

	for (int j = 1; j <= k; j++)
		for (int i = 0; i < n; i++) {
			st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
			st2[j][i] = min(st2[j - 1][i], st2[j - 1][i + (1 << (j - 1))]);
		}
}

int max_in_range(int l, int r)
{
	if (r < l)
		return 0;
	int q = getlog(r - l + 1);
	return max(st[q][l], st[q][r - (1 << q) + 1]);
}

int min_in_range(int l, int r)
{
	if (r < l)
		return 0;
	int q = getlog(r - l + 1);
	return min(st2[q][l], st2[q][r - (1 << q) + 1]);
}

int main(void)
{
	int n, q, l, r;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(n);
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> l >> r;
		c = min_in_range(l, r);
		a = 2 * (max_in_range(0, l - 1) + c);
		b = 2 * (max_in_range(r + 1, n - 1) + c);
		c = max_in_range(l, r) + min_in_range(l, r);

		//cout << a << ' ' << b << ' ' << c << '\n';
		int ans = max(max(a, b), c);
		cout << ans / 2;
		if (ans & 1)
			cout << ".5\n";
		else
			cout << ".0\n";
	}
	return 0;
}

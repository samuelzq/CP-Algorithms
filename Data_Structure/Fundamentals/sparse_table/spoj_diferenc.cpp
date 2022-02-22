/**
 * SPOJ - Diferencija
 * https://www.spoj.com/problems/DIFERENC/
 * https://vjudge.net/problem/SPOJ-DIFERENC
 *
 * 每一个大区间的最值都是其中每个包含该元素的子区间的最值，
 * 因此可以利用乘法原理快速得到所有包含该元素的子区间的最值之和。
 * 接着以该最值为界，将原区间分为左右两部分，分别计算最值之和。
 *
 * @File:   spoj_diferenc.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-22
 *
 **/
#include <bits/stdc++.h>

using namespace std;

#define LL unsigned long long
const int N = 3e5;
pair<LL, int> st[22][N + 2];
int L[N + 2];
LL a[N + 2];

void precalc(void)
{
	L[0] = L[1] = 0;

	for (int i = 2; i <= N; i++)
		L[i] = L[i / 2] + 1;
}

void build_max(int n)
{
	for (int i = 1; i <= L[n]; i++)
		for (int j = 0; j + (1 << (i - 1)) <= n; j++)
			st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

void build_min(int n)
{
	for (int i = 1; i <= L[n]; i++)
		for (int j = 0; j + (1 << (i - 1)) <= n; j++)
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

pair<LL, int> q1(int l, int r)
{
	int j = L[r - l + 1];
	return min(st[j][l], st[j][r - (1 << j) + 1]);
}

pair<LL, int> q2(int l, int r)
{
	int j = L[r - l + 1];
	return max(st[j][l], st[j][r - (1 << j) + 1]);
}

LL get_max(int l, int r)
{
	if (r < l)
		return 0;
	pair<LL, int> p = q2(l, r);
	LL lsum, rsum;
	int m = p.second;

	lsum = get_max(l, m - 1);
	rsum = get_max(m + 1, r);
	return lsum + rsum + p.first * (m - l + 1) * (r - m + 1);
}

LL get_min(int l, int r)
{
	if (r < l)
		return 0;
	pair<LL, int> p = q1(l, r);
	LL lsum, rsum;
	int m = p.second;

	lsum = get_min(l, m - 1);
	rsum = get_min(m + 1, r);
	return lsum + rsum + p.first * (m - l + 1) * (r - m + 1);
}

int main(void)
{
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	precalc();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st[0][i] = {a[i], i};
	}

	LL ans = 0;

	build_max(n);
	ans = get_max(0, n - 1);

	build_min(n);
	ans -= get_min(0, n - 1);
	cout << ans << endl;
	return 0;
}

/**
 * Codeforces - Turn off the TV
 * http://codeforces.com/contest/863/problem/E
 * https://vjudge.net/problem/CodeForces-863E
 *
 * 先记录每一个时刻开着的TV数量，然后查询是否存在最小值大于1的区间。
 * 由于区间跨度会比较大，因此需要进行数据压缩以提升运行效率。
 *
 * @File:   codeforce_863e.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-23
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 600500; //2e5;
int st[22][N + 2];
int L[N + 2];
int c[N + 2];
int v[N + 2][2];
map<int, int> t;

void precalc(void)
{
	L[0] = L[1] = 0;
	for (int i = 2; i <= N; i++)
		L[i] = L[i / 2] + 1;
}

void build(int n)
{
	for (int i = 0; i < n; i++) {
		if (i)
			c[i] += c[i - 1];
		st[0][i] = c[i];
	}

	for (int i = 1; i <= L[n]; i++)
		for (int j = 0; j + (1 << i) <= n; j++)
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int querry(int l, int r)
{
	int j = L[r - l + 1];
	return min(st[j][l], st[j][r - (1 << j) + 1]);
}

int main(void)
{
	int n, m, ans;

	precalc();
	cin >> n;
	m = 0;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		m = max(m, r);
		v[i][0] = l;
		v[i][1] = r;
		t[l];
		t[r];
		t[r + 1];
	}

	int id = 0;
	for (auto &i : t)
		i.second = id++;
	for (int i = 0; i < n; i++) {
		c[t[v[i][0]]]++;
		c[t[v[i][1] + 1]]--;
	}
	build(id);

	ans = -1;
	for (int i = 0; i < n; i++) {
		if (querry(t[v[i][0]], t[v[i][1]]) > 1) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

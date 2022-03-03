/**
 * TIMUS - Anansi's Cobweb
 * https://acm.timus.ru/problem.aspx?space=1&num=1671
 * https://vjudge.net/problem/URAL-1671
 *
 * 本题倒序解决。
 * 先统计最后一次扫除之后仍有的连接；然后倒序添加之前的连接
 *
 * @File:   timus_1671.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
const int M = 1e5;
int p[N + 5];
int t[M + 5][2];
int c[M + 5];
int v[M + 5];
int ans[M + 5];
int s;

int find_set(int a)
{
	if (a == p[a])
		return a;
	return p[a] = find_set(p[a]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		p[b] = a;
		s--;
	}
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		p[i] = i;
	s = n;

	for (int i = 1; i <= m; i++)
		cin >> t[i][0] >> t[i][1];

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {

		cin >> v[i];
		c[v[i]] = -1;
	}
	for (int i = 1; i <= m; i++) {
		if (c[i] != -1)
			union_set(t[i][0], t[i][1]);
	}
	ans[q - 1] = s;
	for (int i = q - 1; i > 0; i--) {
		union_set(t[v[i]][0], t[v[i]][1]);
		ans[i - 1] = s;
	}

	for (int i = 0; i < q - 1; i++)
		cout << ans[i] << ' ';
	cout << ans[q - 1] << '\n';

	return 0;
}

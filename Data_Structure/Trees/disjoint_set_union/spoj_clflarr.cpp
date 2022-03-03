/**
 * SPOJ - COLORFUL ARRAY
 * https://www.spoj.com/problems/CLFLARR/
 * https://vjudge.net/problem/SPOJ-CLFLARR
 *
 * @File:   spoj_clflarr.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-03
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e6;
const int MAXQ = 2e6;

struct paint{
	int l;
	int r;
	int c;
} pp[MAXQ + 2];
int p[MAXN + 2];
int ans[MAXN + 2];

int find(int v)
{
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

int main(void)
{
	int n, q;

	cin >> n >> q;
	for (int i = 0; i <= MAXN; i++)
		p[i] = i;

	for (int i = 0; i < q; i++)
		cin >> pp[i].l >> pp[i].r >> pp[i].c;

	for (int i = q - 1; i >= 0; i--) {
		int l = pp[i].l;
		int r = pp[i].r;
		int c = pp[i].c;
		for (int v = find(l); v <= r; v = find(v)) {
			ans[v] = c;
			p[v] = v + 1;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}

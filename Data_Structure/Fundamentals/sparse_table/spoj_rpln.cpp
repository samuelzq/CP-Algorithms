/**
 * SPOJ - Negative Score
 * https://www.spoj.com/problems/RPLN/
 * https://vjudge.net/problem/SPOJ-RPLN
 *
 * @File:   spoj_rpln.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-22
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 100000;
int st[22][N + 2];
int L[N + 2];
int s[N + 2];

void precalc(void)
{
	L[0] = L[1] = 0;
	for (int i = 2; i <= N; i++)
		L[i] = L[i / 2] + 1;
}

void build(int n)
{
	for (int i = 1; i <= n; i++)
		st[0][i] = s[i];

	for (int j = 1; j <= L[n]; j++)
		for (int i = 1; i + (1 << (j - 1)) <= n; i++)
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

int querry(int l, int r)
{
	int j = L[r - l + 1];
	return min(st[j][l], st[j][r - (1 << j) + 1]);
}

int main(void)
{
	int t;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	precalc();
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> s[i];
		build(n);
		cout << "Scenario #" << i << ":\n";
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << querry(l, r) << '\n';
		}
	}
	return 0;
}

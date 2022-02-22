/**
 * SPOJ - Miraculous
 * https://www.spoj.com/problems/TNVFC1M/
 * https://vjudge.net/problem/SPOJ-TNVFC1M
 *
 * 需要到着查询稀疏表。
 * 如果当前价格是前向查询的最小值，则买入（买入的数量由后续未买次数决定），
 * 否则未买次数加一
 *
 * @File:   spoj_tnvfc1m.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-21
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;
const int K = 16;

int st[K][N + 2];
int L[N + 2], a[N + 2], t[N + 2];

void init(int n)
{
	for (int i = 1; i < n; i++)
		st[0][i] = a[i];

	for (int i = 1; i <= L[n]; i++)
		for (int j = 1; j + (1 << i) <= n; j++)
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int querry(int l, int r)
{
	int j = L[r - l + 1];
	return min(st[j][l], st[j][r - (1 << j) + 1]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	L[0] = L[1] = 0;
	for (int i = 2; i <= N; i++)
		L[i] = L[i / 2] + 1;

	int n, h, b, e;
	while (cin >> n >> h >> b >> e) {
		bool te;
		int tmp = 0;
		te = true;
		cin >> a[1];
		for (int i = 2; i <= n; i++) {
			cin >> tmp;
			if (tmp != a[i - 1])
				te = false;
			a[i] = tmp;
		}

		if (te == true) {
			for (int i = 1; i <= n; i++)
				t[i] = 1;
		} else {
			init(n);

			int p = 0;
			for (int i = n; i > 0; i--) {
				int l, r;
				r = i;
				l = max(i - h + 1, 1);
				if (a[i] == querry(l, r)) {
					t[i] = p + 1;
					p = 0;
				} else {
					p++;
					if (p == h) {
						t[i] = h;
						p = 0;
					} else {
						t[i] = 0;
					}
				}
			}
		}

		for (int i = b; i < e; i++)
			cout << t[i] << ' ';
		cout << t[e] << endl;
	}
	return 0;
}

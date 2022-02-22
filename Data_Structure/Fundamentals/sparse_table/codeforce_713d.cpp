/**
 * Codeforces - Animals and Puzzles
 * https://codeforces.com/contest/713/problem/D
 * https://vjudge.net/problem/CodeForces-713D
 *
 * 二维空间最值，因此稀疏表是4维的。
 * 从（0、0）开始的区间，其内部最大的正方形面积可以使用DP的方法求得。
 *
 * @File:   codeforce_713d.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-24
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
const int M = 1000;
int L[N + 5];
int arr[N + 5][M + 5];
int dp[N + 5][M + 5];            // 从（0、0）开始的区间，其内部最大的正方形面积
int st[10][10][N + 5][M + 5];

void build(int n, int m)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 1) {
				if (i == 1 && j == 1)
					dp[i][j] = arr[i][j];
				else
					dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			st[0][0][i][j] = dp[i][j];

	for (int k = 1; k < 10; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j + (1 << (k - 1)) <= m; j++)
				st[0][k][i][j] = max(st[0][k - 1][i][j], st[0][k - 1][i][j + (1 << (k - 1))]);

	for (int k = 1; k < 10; k++)
		for (int i = 1; i + (1 << (k - 1)) <= n; i++)
			for (int j = 1; j <= m; j++)
				st[k][0][i][j] = max(st[k - 1][0][i][j], st[k - 1][0][i + (1 << (k - 1))][j]);

	for (int k = 1; k <10; k++) {
		for (int l = 1; l < 10; l++) {
			for (int i = 1; i + (1 << (k - 1)) <= n; i++) {
				for (int j = 1; j + (1 << (l - 1)) <= m; j++) {
					int d1 = i + (1 << (k - 1));
					int d2 = j + (1 << (l - 1));
					int t = max(st[k - 1][l - 1][d1][j], st[k - 1][l - 1][i][d2]);
					t = max(t, st[k - 1][l - 1][d1][d2]);
					st[k][l][i][j] = max(st[k - 1][l - 1][i][j], t);
				}
			}
		}
	}
}

int querry(int a, int b, int c, int d)
{
	int l1 = L[c - a + 1];
	int l2 = L[d - b + 1];
	int t;

	t = max(st[l1][l2][a][b], st[l1][l2][c - (1 << l1) + 1][d - (1 << l2) + 1]);
	t = max(t, st[l1][l2][c - (1 << l1) + 1][b]);
	return max(t, st[l1][l2][a][d - (1 << l2) + 1]);
}

int main(void)
{
	int n, m;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	L[0] = L[1] = 0;
	for (int i = 2; i <= N; i++)
		L[i] = L[i / 2] + 1;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	build(n, m);
	int q, ans;
	cin >> q;
	ans = 0;
	while (q--) {
		int a, b, c, d, l, r, m;
		cin >> a >> b >> c >> d;
		l = 0;
		r = min(c - a + 1, d - b + 1);
		while (l <= r) {
			m = (l + r) / 2;
			if (querry(a + m - 1, b + m - 1, c, d) >= m) {
				l = m + 1;
				ans = m;
			} else
				r = m - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}

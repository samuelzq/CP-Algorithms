/**
 * SPOJ - Strange Food Chain
 * https://www.spoj.com/problems/CHAIN/
 * https://vjudge.net/problem/SPOJ-CHAIN
 *
 * 升级版朋友敌人问题。
 * 由于存在三个相互克制的角色，因此需要三个表存放相互关系。
 *
 * @File:   spoj_chain.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-01
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 5e4;
int p[N * 3 + 5];

int find_set(int a)
{
	if (a == p[a])
		return p[a];
	return p[a] = find_set(p[a]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
		p[b] = a;
}

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n, k, ans;
		cin >> n >> k;

		for (int i = 1; i <= 3 * n; i++)
			p[i] = i;

		ans = 0;
		for (int i = 0; i < k; i++) {
			int o, x, y;
			cin >> o >> x >> y;

			if (x > n || y > n) {
				ans++;
			} else {
				if (o == 2) { // x eat y
					if (find_set(x) == find_set(y) ||
					    find_set(y + n) == find_set(x)) {
						ans++;
					} else {
						union_set(y, x + n);
						union_set(y + n, x + n + n);
						union_set(y + n + n, x);
					}
				} else if (o == 1) {
					if (find_set(x + n) == find_set(y) ||
					    find_set(y + n) == find_set(x)) {
						ans++;
					} else {
						union_set(y, x);
						union_set(y + n, x + n);
						union_set(y + n + n, x + n + n);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/**
 * SPOJ - A Famous City
 * https://www.spoj.com/problems/CITY2/
 * https://vjudge.net/problem/SPOJ-CITY2
 *
 * SPOJ - Postering 类似，但是较为复杂的是：多个测试用例。楼组之间有空隙
 *
 * @File:   spoj_city2.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-22
 *
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
//int h[N + 2];

int main(void)
{
	int n, k = 1;
	stack<int> s;

	while (cin >> n) {
		int ans = 0;
		while (!s.empty())
			s.pop();
		for (int i = 1; i <= n; i++) {
			int t;
			cin >> t;

			if (t == 0) {
				while (!s.empty())
					s.pop();
			} else {
				while (!s.empty() && s.top() > t)
					s.pop();
				if (s.empty() || s.top() < t) {
					s.push(t);
					ans++;
				}
			}
		}
		cout << "Case " << k++ << ": " << ans << '\n';
	}
	return 0;
}

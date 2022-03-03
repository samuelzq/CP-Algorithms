/**
 * Codeforces - Roads not only in Berland
 * http://codeforces.com/contest/25/problem/D
 * https://vjudge.net/problem/CodeForces-25D
 *
 * 如果n-1条线未能将n个点联通，则断路数等于重复线路数。
 * 先统计重复的线路，然后枚举查找所有根结点。
 *
 * @File:   codeforce_25d.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-02
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
int p[N + 2];

int find_set(int v)
{
	if (v == p[v])
		return v;
	return p[v] = find_set(p[v]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		p[b] = a;
	}
}

bool same_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	return a == b;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		p[i] = i;

	vector<pair<int, int>> c;
	vector<int> r;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		if (same_set(a, b))
			c.push_back({a, b});
		else
			union_set(a, b);
	}

	for (int i = 1; i <= n; i++) {
		if (i == p[i])
			r.push_back(i);
	}

	cout << c.size() << '\n';
	for (int i = 0; i < c.size(); i++)
		cout << c[i].first << ' ' << c[i].second << ' ' << r[i] << ' ' << r[i + 1] << '\n';
	return 0;
}

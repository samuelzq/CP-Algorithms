/**
 * Queries with Fixed Length
 * https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
 * https://vjudge.net/problem/HackerRank-queries-with-fixed-length
 *
 * 利用两个栈来实现的最大队列
 *
 * @File:   qfixlen.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-10
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 0xAC;
int arr[N];
stack<pair<int, int>> s1, s2;

void init(void)
{
	while (!s1.empty())
		s1.pop();
	while (!s2.empty())
		s2.pop();
}
int get_max(void)
{
	int maxnum;
	if (s1.empty() || s2.empty())
		maxnum = s1.empty() ? s2.top().second : s1.top().second;
	else
		maxnum = max(s1.top().second, s2.top().second);
	return maxnum;
}

void add(int n)
{
	int maxnum = s1.empty() ? n : max(n, s1.top().second);
	s1.push({n, maxnum});
}

void remove(void)
{
	if (s2.empty()) {
		while (!s1.empty()) {
			int element = s1.top().first;
			s1.pop();
			int maxmum = s2.empty() ? element : max(element, s2.top().second);
			s2.push({element, maxmum});
		}
	}
	int remove_element = s2.top().first;
	s2.pop();
}

int main(void)
{
	int n, q, ans;

	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	while (q--) {
		init();

		int d, i;
		cin >> d;

		for (i = 0; i < d; i++)
			add(arr[i]);
		ans = get_max();
		for (; i < n; i++) {
			remove();
			add(arr[i]);
			ans = min(ans, get_max());
		}
		cout << ans << '\n';
	}
	return 0;
}

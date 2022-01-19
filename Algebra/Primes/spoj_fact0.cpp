/**
 * SPOJ - FACT0
 * https://www.spoj.com/problems/FACT0/
 * https://vjudge.net/problem/SPOJ-FACT0
 *
 * @File:   spoj_fact0.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-13
 *
 **/
#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, int>> trial_division2(long long n)
{
	vector<pair<long long, int>> factorization;
	int cnt = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt++;
	}
	if (cnt)
		factorization.push_back({2, cnt});
	for (long long d = 3; d * d <= n; d += 2) {
		cnt = 0;
		while (n % d == 0) {
			n /= d;
			cnt++;
		}
		if (cnt)
			factorization.push_back({d, cnt});
	}
	if (n > 1)
		factorization.push_back({n, 1});
	return factorization;
}

int main(void)
{
	long long t;

	while (cin >> t && t) {
		long long d1, d2, cnt;
		vector<pair<long long, int>> dividors = trial_division2(t);
		int i;
		for (i = 0; i < dividors.size() - 1; i++) {
			cout << dividors[i].first << '^' << dividors[i].second << ' ';
		}
		cout << dividors[i].first << '^' << dividors[i].second << '\n';
	}
	return 0;
}

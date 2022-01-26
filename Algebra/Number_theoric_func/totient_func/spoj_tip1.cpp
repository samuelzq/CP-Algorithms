/**
 * SPOJ - Totient in Permutation (easy)
 * https://www.spoj.com/problems/TIP1/
 * https://vjudge.net/problem/SPOJ-TIP1
 *
 * 此题有一定难度，需要考虑如何规避浮点数比大小以及提高查找效率。
 *
 * @File:   spoj_tip1.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-19
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int M = 1e7;
const int T = 1e5;

int phi[M + 0xac];
int ans[M + 0xac];

bool check(int n, int m)
{
	char bit1[10], bit2[10];
	memset(bit1, 0, sizeof(bit1));
	memset(bit2, 0, sizeof(bit2));
	while (n) {
		int b = n % 10;
		bit1[b]++;
		n /= 10;
	}

	while (m) {
		int b = m % 10;
		bit2[b]++;
		m /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (bit1[i] != bit2[i])
			return false;
	}
	return true;
}

void phi_one2n(void)
{
	for (int i = 0; i <= M; i++)
		phi[i] = i;

	for (int i = 2; i <= M; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= M; j += i)
				phi[j] -= phi[j] / i;
		}
	}

	int ans1 = 21;
	for (int i = 21; i <= M; i++) {
		if (check(i, phi[i]) && ((long long)i * phi[ans1] <= (long long)ans1 * phi[i]))
			ans1 = i;
		ans[i] = ans1;
	}
}

int main(void)
{
	phi_one2n();

	int t;

	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		if (ans[m - 1] == 0)
			cout << "No solution.\n";
		else
			cout << ans[m - 1] << '\n';
	}
	return 0;
}

/**
 * SPOJ - RMQSQ
 * https://www.spoj.com/problems/RMQSQ/
 * https://vjudge.net/problem/SPOJ-RMQSQ
 *
 * @File:   spoj_rmqsq.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-16
 *
 **/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int LOGN = 17;

int arr[MAXN];
int ans[MAXN][LOGN];

int getlog(int n)
{
	int r = 0;

	for (int i = 31; i >= 0; i--) {
		if (n & (1 << i))
			break;
		r++;
	}
	return 31 - r;
}

void init(int n)
{
	int k = getlog(n);

	for (int i = 0; i < n; i++)
		ans[i][0] = arr[i];

	for (int j = 1; j <= k; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			ans[i][j] = min(ans[i][j-1], ans[i + (1 << (j - 1))][j - 1]);
}

int querry(int l, int r)
{
	int j = getlog(r - l + 1);
	return min(ans[l][j], ans[r - (1 << j) + 1][j]);
}

int main(void)
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(n);

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << querry(l, r) << '\n';
	}
	return 0;
}

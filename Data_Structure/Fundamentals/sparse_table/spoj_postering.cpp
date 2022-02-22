/**
 * SPOJ - Postering
 * https://www.spoj.com/problems/POSTERIN/
 * https://vjudge.net/problem/SPOJ-POSTERIN
 *
 * 如果该高度只有一栋建筑，则需要使用一张海报。如果A、B为等高建筑，它们之间存在
 * 建筑C，C的高度在[A， B]区间之内最低，则高度为C的海报可以覆盖A到B的区间，A和B
 * 均需要额外的海报覆盖。如果A、B之间的建筑均高于A和B，则高为A/B的海报可以覆盖
 * A到B之间的区域，A和B不需要额外的海报。由于存在多个等高建筑，因此需要需要和
 * 植树问题一样考虑边界处的处理。
 *
 * @File:   spoj_postering.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-02-22
 *
 **/
#include <bits/stdc++.h>

using namespace std;
const int N = 300000;
set<int> height;                // 记录建筑物的不同高度
map<int, vector<int>> heights;  // 记录具有相同高度的建筑的位置
int h[N + 5];                   // 每栋建筑高度
int st[17][N + 5];              // 稀疏表
int L[N + 5];

void precal(void)
{
	L[0] = L[1] = 0;
	for (int i = 2; i < N; i++)
		L[i] = L[i / 2] + 1;
}

void build(int n)
{
	for (int i = 0; i < n; i++)
		st[0][i] = h[i];

	for (int j = 1; j <= L[n]; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

int querry(int l, int r)
{
	int j = L[r - l + 1];
	return min(st[j][l], st[j][r - (1 << j) + 1]);
}

int main(void)
{
	int n, d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> h[i];
		heights[h[i]].push_back(i);
		height.insert(h[i]);
	}
	precal();
	build(n);
	int ans = 0;
	for (auto w : height) {
		int e = heights[w].size();
		if (e == 1) {
			ans++;
		} else {
			for (int i = 0; i < e - 1; i++) {
				int m = querry(heights[w][i], heights[w][i + 1]);
				if (i + 1 == e - 1) {
					if (m < w)
						ans += 2;
					else
						ans += 1;
				} else {
					if (m < w)
						ans += 1;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

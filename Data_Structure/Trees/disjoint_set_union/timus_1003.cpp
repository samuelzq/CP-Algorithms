/**
 * TIMUS - Parity
 * https://acm.timus.ru/problem.aspx?space=1&num=1003
 * https://vjudge.net/problem/URAL-1003
 *
 * 实质上是“朋友敌人”问题。
 * 考虑到区间内[a, b]只有0、1，所以区间[a, b]内1的个数即为区间和。
 * 区间和等于前缀和之差。因此区间[a, b]的和是偶数表明两个前缀Sa和Sb同奇偶；
 * 否则不同奇偶。本题的另一个问题是，字符长度比较大，区间的跨度比较大，
 * 因此需要进行压缩处理。
 *
 * @File:   timus_1003.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-03
 *
 **/
#include <bits/stdc++.h>

using namespace std;
#define N 10010 //最多10000个点
#define M 5010

int m, np;
struct ran {
	int l, r, v;
} a[M];

struct point {
	int n, m;
} c[N];

int p[2 * N];

int cmp(struct point a, struct point b)
{
	return a.n < b.n;
}

int init() //输入数据和离散化
{
	scanf("%d", &m);
	np = 0;

	for (int i = 0; i < m; i++) {
		int l, r;
		char s[5];
		scanf("%d%d%s", &l, &r, s);
		a[i].v = (s[0] == 'o');
		c[np].m = i;
		c[np].n = l;
		c[np+1].m = i;
		c[np+1].n = r;
		np += 2;
	}
	sort(c, c + np, cmp);
	int mm, nn = 0;
	for (int i = 0; i < np; i++) {
		if (i == 0 || c[i].n != c[i-1].n)
			++nn;
		mm = c[i].m;
		a[mm].l = a[mm].r;
		a[mm].r = nn;
	}
	//for(int i=0; i<m; i++) printf("[%d,%d] %d\n",a[i].l,a[i].r,a[i].v);
	//离散化结束
	return nn;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

void solve(int n)
{
	for (int i = 0; i <= 2 * N + 1; i++)
		p[i] = i;
	int res = m;

	for (int i = 0; i < m; i++) {
		int l = a[i].l, r = a[i].r, v = a[i].v;
		int t = max(l, r), tt = min(l, r);
		l = tt - 1;
		r = t;

		int fal, far, eml, emr;
		fal = find(l);
		far = find(r);
		eml = find(l + n + 1);
		emr = find(r + n + 1);

		if (!v) {
			if (fal == emr && far == eml) {
				res = i;
				break;
			}
			p[fal] = far;
			p[eml] = emr;
		} else {
			if (fal == far) {
				res = i;
				break;
			}
			p[fal] = emr;
			p[far] = eml;
		}
	}
	printf("%d\n", res);
}

int main()
{
	int n;
	while (scanf("%d", &n)!=EOF && n!=-1) {
		n = init();
		solve(n);
	}
	return 0;
}

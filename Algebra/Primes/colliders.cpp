/**
 * Codefoces - Colliders
 * https://codeforces.com/problemset/problem/154/B
 * https://vjudge.net/problem/CodeForces-154B
 *
 * 需要一张表记录每个反应堆运行状态。
 * 还需要一张表记录每个数的最小质因数。通过遍历该最小质因数表
 * 可以得到每个数的所有质因数。
 * 通过以上两张表就可以得到正确解。但是，当输入较多和数后，查询表1并分解质因数
 * 的过程还是比较耗时，会导致运行超时。
 * 为加快查询，需增添第三张表，记录当前运行的反应堆编号是哪个质数的倍数。这样
 * 不仅缩小了查询的范围（从N减小到sqrt(N)），而且省去了分解质因数的过程。
 *
 * @File:   colliders.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-01-12
 *
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int d[N];          // 记录最小质因数
int prime_num = 0;
int md[N];         // 记录当前使能编号所对应的质因数
bool stats[N];     // 机器运行状态位图
int evenc = 0;

void sieve(void)
{
	d[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (d[i] == 0) {
			for (int j = 2 * i; j <= N; j += i)
				d[j] = i;
			d[i] = i;
			prime_num++;
		}
	}
}

int check(int n, int tot)
{
	if (!(n % 2) && evenc) // 偶数直接检验奇偶性
		return evenc;

	// 对于奇数，需要对其进行质因数分解，并检测是否有倍数存在
	int a, t;
	t = n;
	a = d[n];
	while (a != 1) {
		if (md[a]) // 有某个质因数的倍数存在
			return md[a];
		t /= a;
		a = d[t];
	}
	return 0;
}

// 将和数每个质因数置位
void set_m(int n)
{
	int a, t;
	t = n;
	a = d[n];
	while (a != 1) {
		md[a] = n;
		t /= a;
		a = d[t];
	}
}

void clear_m(int n)
{
	int a, t;
	t = n;
	a = d[n];
	while (a != 1) {
		md[a] = 0;
		t /= a;
		a = d[t];
	}
}

int main(void)
{
	int n, m;

	sieve();
	cin >> n >> m;
	while(m--) {
		char op;
		int c;

		cin >> op >> c;
		if (op == '-') {
			if (stats[c] == 0)
				cout << "Already off\n";
			else {
				if (evenc == c)
					evenc = 0;
				stats[c] = 0;
				clear_m(c);
				cout << "Success\n";
			}
		} else if (op == '+') {
			if (stats[c] == 1)
				cout << "Already on\n";
			else {
				int cf = check(c, n);
				if (cf)
					cout << "Conflict with " << cf << '\n';
				else {
					if (c % 2 == 0)
						evenc = c;
					stats[c] = 1;
					set_m(c);
					cout << "Success\n";
				}
			}
		}
	}
	return 0;
}

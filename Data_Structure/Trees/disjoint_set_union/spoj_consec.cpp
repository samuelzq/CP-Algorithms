/**
 * SPOJ - Consecutive Letters
 * https://www.spoj.com/problems/CONSEC/
 * https://vjudge.net/problem/SPOJ-CONSEC
 *
 * @File:   spoj_consec.cpp
 * @Author: Lao Zhang <samuelzhang77@yahoo.com>
 * @Date:   2022-03-04
 *
 **/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

int p[N + 5];
int size[N + 5];
char str[N + 5];
char ostr[N + 5];

void init(int n)
{
	for (int i = 0; i <= n; i++) {
		p[i] = i;
		size[i] = 1;
	}
}

void make(int a)
{
	p[a] = a;
	size[a] = 1;
}

int find(int v)
{
	if (v == p[v])
		return v;
	return p[v] = find(p[v]);
}

void union_set(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b) {
		if (size[a] < size[b])
			swap(a, b);
		p[b] = a;
		size[a] += size[b];
	}
}

int main(void)
{
	int t;
	stack<pair<int, int>> querry;
	stack<int> ans;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> str;
		int len = strlen(str);
		init(len);

		int q;
		cin >> q;
		while (q--) {
			int o, i;
			cin >> o >> i;
			if (o == 2) {
				ostr[i] = str[i];
				str[i] = '#';
			}
			querry.push({o, i});
		}

		for (int j = 0; j < len; j++) {
			if (str[j] == '#')
				continue;
			if (j + 1 < len && str[j] == str[j + 1])
				union_set(j, j + 1);
		}

		while (!querry.empty()) {
			pair<int, int> op = querry.top();
			int o, c;
			o = op.first;
			c = op.second;
			if (o == 1) {
				ans.push(size[find(c)]);
			} else {
				make(c);
				if (c - 1 >= 0 && ostr[c] == str[c - 1])
					union_set(c - 1, c);
				if (c + 1 < len && ostr[c] == str[c + 1])
					union_set(c, c + 1);
				str[c] = ostr[c];
			}
			querry.pop();
		}
		cout << "Case " << i << ":\n";
		while (!ans.empty()) {
			cout << ans.top() << '\n';
			ans.pop();
		}
	}
	return 0;
}

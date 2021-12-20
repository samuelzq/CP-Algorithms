/**
* HackerRank - Is Fibo
* https://vjudge.net/problem/HackerRank-is-fibo
*
*本题使用枚举法穷举。目前无法提交验证。
*
# @File:   HackerRank_is_fibo.cpp
* @Author: Lao Zhang <samuelzhang77@yahoo.com>
# @Date:   2021-12-20
#
**/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int t;

	cin >> t;
	while (t--) {
		long long n;
		bool isfib = false;
		isfib = false;
		cin >> n;

		if (n) {
			long a, b, c;
			a = 0, b = 1, c = a + b;
			while (c < n) {
				a = b;
				b = c;
				c = a + b;
			}
			if (c == n)
				isfib = true;
		}

		if (isfib)
			cout << "IsFibo\n";
		else
			cout << "IsNotFibo\n";
	}
	return 0;
}

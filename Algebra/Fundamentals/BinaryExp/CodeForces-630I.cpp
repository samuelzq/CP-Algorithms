// 分成两种情况：
// 1、n个汽车排列在头部或者尾部，此时有4×3×4^(n-3)种排列方式；
// 2、n个汽车排列在队列中，此时该连续子序列前后各有3个选择，可以将
//    n+2视为一个集合，该集合可以选择的位置有2n-2-n-2+1=n-3个，其余
//    n-4个位置各有4种选择。此时共有4×3^2×(n-3)×4^(n-4)。

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, m;
	long long s1, s2, ans;

	cin >> n;
	m = 2 * n - 2;
	s1 = 1;
	s1 = s1 << (2 * n - 6);      // m - n - 1 = n - 3
	s2 = (n - 3) * 3 * 3 * s1;
	s1 *= 2 * 4 * 3;
	cout << s1 + s2 << endl;
	return 0;
}

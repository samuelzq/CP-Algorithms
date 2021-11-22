// 利用尝试法，找到一组解即可

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int a, b, c, g;
	while (cin >> a >> b >> c) {
		g = 0;
		for (int i = 0; c - a * i >= 0; i++) {
			if ((c - a * i) % b == 0) {
				g = 1;
				break;
			}
		}
		if (!g)
			cout << "No\n";
		else
			cout << "Yes\n";
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	while (n--) {
		int a, b, ans;
		cin >> a >> b;

		ans = 1;
		a %= 10;
		while (b) {
			if (b & 1)
				ans = ans * a % 10;
			a = a * a % 10;
			b >>= 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
